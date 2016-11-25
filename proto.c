#include <math.h>
#include <locale.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <libpq-fe.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>

#include "proto.h"
#include "settings.h"

#define MAXLENQUERY     2048
#define REPORTLEN       256
#define POCKETMAXLEN    1500
#define MAXCHIELDS      4096
#define FD_COPY(f, t)   (void)(*(t) = *(f))
#define INITPACKETLEN 17
#define SERIALIZESENSORLEN 2048

#define DECL  "DECLARE cursor%u CURSOR FOR "
#define FETCH "FETCH ALL in cursor%u"
#define CLOSE "CLOSE cursor%u"

int proto(char* reqdata, int len, const char** outPacketId, char *client_ip, unsigned short client_port)
{
    cJSON *root = cJSON_Parse(reqdata);
    
    cJSON *id = cJSON_GetObjectItem(root, "id");
    if(id == NULL)
    {
        return EXIT_FAILURE;
    }
    *outPacketId = id->valuestring;
    
    cJSON *data = cJSON_GetObjectItem(root, "data");
    if(data == NULL)
    {
        return EXIT_FAILURE;
    }
    
    if(data->type != cJSON_Array && data->type != cJSON_String)
    {
        return EXIT_FAILURE;
    }
    
    if(data->type == cJSON_String)
    {
        cJSON *point = cJSON_Parse(data->valuestring);        
        return parsepoint(point, client_ip, client_port);
    }
    
    if(data->type == cJSON_Array)
    {
        int length = cJSON_GetArraySize(data);
        int i;
        for(i = 0; i < length; i++)
        {
            cJSON * subitem = cJSON_GetArrayItem(data, i);
            if(parsepoint(subitem, client_ip, client_port) == EXIT_FAILURE)
            {
                return EXIT_FAILURE;
            }
        }
    }
    
    return EXIT_SUCCESS;
}

int parsepoint(cJSON* point, char *client_ip, unsigned short client_port)
{
    DevicePoint dp;
    
        dp.client_ip = client_ip;
        dp.client_port = client_port;
    
        cJSON* device_id = cJSON_GetObjectItem(point, "device_id");
        if(device_id == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.device_id = device_id->valuestring;
        
        cJSON* name = cJSON_GetObjectItem(point, "name");
        if(name == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.name = name->valuestring;
        
        cJSON* datetime_ts = cJSON_GetObjectItem(point, "datetime_ts");
        if(datetime_ts == NULL)
        {
            return EXIT_FAILURE;
        }
        if(datetime_ts->type == cJSON_String)
        {
            dp.datetime_ts = atol(datetime_ts->valuestring);
        }
        else
        {
            dp.datetime_ts = datetime_ts->valueint;
        }
        
        cJSON* latitude = cJSON_GetObjectItem(point, "latitude");
        if(latitude == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.latitude = latitude->valuedouble;
        
        cJSON* longitude = cJSON_GetObjectItem(point, "longitude");
        if(longitude == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.longitude = longitude->valuedouble;
        
        cJSON* altitude = cJSON_GetObjectItem(point, "altitude");
        if(altitude == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.altitude = altitude->valueint;
        
        cJSON* speed = cJSON_GetObjectItem(point, "speed");
        if(speed == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.speed = speed->valueint;
        
        cJSON* course = cJSON_GetObjectItem(point, "course");
        if(course == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.course = course->valueint;
        
        cJSON* accuracy = cJSON_GetObjectItem(point, "accuracy");
        if(accuracy == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.accuracy = accuracy->valueint;
        
        cJSON* nsat = cJSON_GetObjectItem(point, "nsat");
        if(nsat == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.nsat = nsat->valueint;
        
        cJSON* lastupdate_ts = cJSON_GetObjectItem(point, "lastupdate_ts");
        if(lastupdate_ts == NULL)
        {
            return EXIT_FAILURE;
        }
        if(lastupdate_ts->type == cJSON_String)
        {
            dp.lastupdate_ts = atol(lastupdate_ts->valuestring);
        }
        else
        {
            dp.lastupdate_ts = lastupdate_ts->valueint;
        }
        
        cJSON* device_info = cJSON_GetObjectItem(point, "device_info");
        cJSON* gprs = cJSON_GetObjectItem(device_info, "gprs");
        if(gprs == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.gprs = gprs->valuestring;
        
        cJSON* wifi = cJSON_GetObjectItem(device_info, "wifi");
        if(wifi == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.wifi = wifi->valuestring;
        
        cJSON* connected = cJSON_GetObjectItem(device_info, "connected");
        if(connected == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.connected = connected->valuestring;
        
        cJSON* battary = cJSON_GetObjectItem(device_info, "battary");
        if(battary == NULL)
        {
            return EXIT_FAILURE;
        }
        dp.battary = battary->valuestring;
        
        cJSON* lastcharge_ts = cJSON_GetObjectItem(device_info, "lastcharge_ts");
        if(lastcharge_ts == NULL)
        {
            return EXIT_FAILURE;
        }
        if(lastupdate_ts->type == cJSON_String)
        {
            dp.lastcharge_ts = atol(lastcharge_ts->valuestring);
        }
        else
        {
            dp.lastcharge_ts = lastcharge_ts->valueint;
        }
        
        return savepoint(&dp);
}

int db_login(PGconn **conn)
{    
    pthread_mutex_lock(&connectionm);
    if (PQstatus(*conn) == CONNECTION_BAD) 
    {
        char *pgoptions=NULL, *pgtty=NULL;
        *conn = PQsetdbLogin(primarypghost, primarypgport, pgoptions, pgtty, primarydbname, primarypglogin, primarypgpwd);
        if (PQstatus(*conn) == CONNECTION_BAD) 
        { 
            if(debug>1)syslog(LOG_ERR,"Connection to database failed %s", PQerrorMessage(*conn));
            PQfinish(*conn);
                        
            *conn = PQsetdbLogin(secondarypghost, secondarypgport, pgoptions, pgtty, secondarydbname, secondarypglogin, secondarypgpwd);
            
            if (PQstatus(*conn) == CONNECTION_BAD) 
            { 
                if(debug>1)syslog(LOG_ERR,"Connection to database failed %s", PQerrorMessage(*conn));
                PQfinish(*conn);
		pthread_mutex_unlock(&connectionm);
                return 0;
            }
        }       
        pthread_mutex_unlock(&connectionm);
    }
    else
    {
	pthread_mutex_unlock(&connectionm);
        return 1;
    }
}

int execsql(PGconn *conn, char *sql, char *report)
{
    if (PQstatus(conn) == CONNECTION_BAD) 
    {
        return (2);
    }
    
    PGresult   *res;

    res = PQexec(conn, "BEGIN");
    if (!res || PQresultStatus(res) != PGRES_COMMAND_OK) {
        if(debug)syslog(LOG_ERR,"BEGIN command failed");
        strncpy(report, PQerrorMessage(conn),99);
        PQclear(res);
        return (1);
    }
    if(debug>1)syslog(LOG_ERR,"BEGIN command ok");

    PQclear(res);
    res = PQexec(conn, sql);
    if (!res || PQresultStatus(res) != PGRES_COMMAND_OK) {
        if(debug)syslog(LOG_ERR,"PQexec command failed");
        strncpy(report, PQerrorMessage(conn),99);
        PQclear(res);
        return (2);
    }
    if(debug>1)syslog(LOG_ERR,"PQexec command ok");

    PQclear(res);
    res = PQexec(conn, "COMMIT");
    if (!res || PQresultStatus(res) != PGRES_COMMAND_OK) { 
        if(debug)syslog(LOG_ERR,"COMMIT command failed");
        strncpy(report, PQerrorMessage(conn),99);
        PQclear(res);
        return (3);
    }
    PQclear(res);
    if(debug>1)syslog(LOG_ERR,"COMMIT command ok");
    return (0); 
}

PGresult *getexecsql(PGconn *conn, char * sql)
{   
    if (PQstatus(conn) == CONNECTION_BAD) 
    {
        return NULL;
    }
    
    char       *sqlfull;
    int        sqllen;
    PGresult   *res;
    
    res = PQexec(conn, "BEGIN");
    if (!res || PQresultStatus(res) != PGRES_COMMAND_OK){ 
            if(debug)syslog(LOG_ERR,"BEGIN failed");
            PQclear(res);
            return NULL;
    }
    PQclear(res);
    if(debug>1)syslog(LOG_ERR,"BEGIN ok");

    char request[MAXLENQUERY];
    bzero(request, MAXLENQUERY);    
    sprintf(request, DECL, conn);
    
    sqllen=strlen(request);              
    sqllen+=strlen(sql);
    sqlfull=(char*)malloc(sqllen+1);  
    memset(sqlfull, 0x00, sqllen+1);
    strcpy(sqlfull, request);            
    strncat(sqlfull, sql, strlen(sql)); 
    
    if(debug>3)syslog(LOG_ERR,"%s",sqlfull);
    res = PQexec(conn, sqlfull);
    if (!res || PQresultStatus(res) != PGRES_COMMAND_OK){
        if(debug)syslog(LOG_ERR,"DECLARE failed");
        PQclear(res);
        return NULL;
    }
    PQclear(res);
    free(sqlfull);
    if(debug>1)syslog(LOG_ERR,"DECLARE ok");

    bzero(request, MAXLENQUERY);
    sprintf(request, FETCH, conn);
    
    res = PQexec(conn, request);
    if (!res || PQresultStatus(res) != PGRES_TUPLES_OK){
        if(debug)syslog(LOG_ERR,"FETCH failed");
        PQclear(res);
        return NULL;
    }
    if(debug>1)syslog(LOG_ERR,"FETCH ok");
    return res;
}

void clearres(PGconn *conn, PGresult *res)
{
    if (PQstatus(conn) == CONNECTION_BAD) 
    {
        return;
    }

    if(res)
    {
    	PQclear(res);
    }    

    char request[MAXLENQUERY];
    bzero(request, MAXLENQUERY);    
    sprintf(request, CLOSE, conn);
    
    res = PQexec(conn, request);
    if(debug>1)syslog(LOG_ERR,"CLOSE ok");
    PQclear(res);
    res = PQexec(conn, "COMMIT");
    if(debug>1)syslog(LOG_ERR,"COMMIT ok");
    PQclear(res);    
} 

int savepoint(DevicePoint *dp)
{
    int ret, num, ifexit;
    char id[sizeof(long)+1];
    PGresult *res;    
       
    int connectionId = connectionIndex++ % CONNECTION_BACKLOG;
    
    pthread_mutex_lock(&selectconnectionlock[connectionId]);
    PGconn* conn = connections[connectionId];
    
    if (PQstatus(conn) == CONNECTION_BAD) 
    {
        conn = NULL;
        if(db_login(&conn) == 0)
        {
            pthread_mutex_unlock(&selectconnectionlock[connectionId]);
            return EXIT_FAILURE;
        }
    }
    
    char query[MAXLENQUERY];
    bzero(query,MAXLENQUERY);
    
    ret = sprintf(query,"SELECT * FROM public.deviceauth('%s', '', '%s', %d, 24);", dp->device_id, dp->client_ip, dp->client_port);
    
    res = getexecsql(conn, query);
    if(res)
    {
        if (PQgetisnull(res,0,0))
        {
            sprintf(id,"0");
            ifexit=1;
            if(debug>1)syslog(LOG_ERR,"getexec sql id not found %s", dp->device_id);
            } 
            else 
            {
                ret = sprintf(id,"%s",PQgetvalue(res, 0, 0));
                ifexit=0;
                if(debug>1)syslog(LOG_ERR,"getexec sql found id=%s",id);
            }         
    }
    clearres(conn, res);
    
    if(ifexit)
    {
        pthread_mutex_unlock(&selectconnectionlock[connectionId]);
        return EXIT_FAILURE;
    }
    
    bzero(query,MAXLENQUERY);
    ret = sprintf(query,
    "SELECT public.device24save(\
    24::bigint,\
    %s::bigint,\
    %lu::bigint,\
    %f::double precision,\
    %f::double precision,\
    %d::real,\
    %d::integer,\
    %d::smallint,\
    0::smallint,\
    %d::smallint,\
    %d::smallint,\
    %s::smallint,\
    %s::integer,\
    0::bigint,\
    ''::text,\
    FALSE,\
    ARRAY[0,0,%d%s]::double precision[],\
    ARRAY[]::text[]\
    );",
                 id,                 
                 dp->datetime_ts,
                 dp->latitude,
                 dp->longitude,
                 dp->speed, 
                 0,
                 dp->altitude,
                 dp->nsat, 
                 dp->accuracy,
                 dp->gprs,
                 dp->battary,
                 0,
                 ""
                );

    if(debug)syslog(LOG_ERR,"query: %s",query);
        
    res = getexecsql(conn, query);
    if(res)
    {
        if (PQgetisnull(res,0,0))
        {
                if(debug)syslog(LOG_WARNING,"can't insert track record errno %d",ret);
                if(debug>1)syslog(LOG_WARNING,"%s",query);
        }
        else 
        {            
        }         
    }
    clearres(conn, res); 
    
    pthread_mutex_unlock(&selectconnectionlock[connectionId]);
    return EXIT_SUCCESS;
}
