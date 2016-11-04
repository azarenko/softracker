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

#include "proto.h"
#include "settings.h"

int proto(char* reqdata, int len, const char** outPacketId)
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
        return parsepoint(point);
    }
    
    if(data->type == cJSON_Array)
    {
        int length = cJSON_GetArraySize(data);
        int i;
        for(i = 0; i < length; i++)
        {
            cJSON * subitem = cJSON_GetArrayItem(data, i);
            if(parsepoint(subitem) == EXIT_FAILURE)
            {
                return EXIT_FAILURE;
            }
        }
    }
    
    return EXIT_SUCCESS;
}

int parsepoint(cJSON* point)
{
    DevicePoint dp;
        
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

int savepoint(DevicePoint *dp)
{
    return EXIT_SUCCESS;
}
