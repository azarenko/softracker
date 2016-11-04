#include "cJSON.h"

typedef struct DevicePoint
{
    char* device_id;
    char* name;
    long int datetime_ts;
    double latitude;
    double longitude;
    int altitude;
    int speed;
    int course;
    int accuracy;
    int nsat;
    long int lastupdate_ts;
    char* gprs;
    char* wifi;
    char* connected;
    char* battary;
    long int lastcharge_ts;
} DevicePoint;

int proto(char* reqdata, int len, const char** outPacketId);

int savepoint(DevicePoint *dp);

int parsepoint(cJSON* point);
