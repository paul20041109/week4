#include "myhead.h"
#include <string.h>
#include <stdlib.h>
#define  MAX_STUDENT 10


// comparison function by department for SRecord
int compareSRecordsBydepartment(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    return strcmp(srecordA->student.department, srecordB->student.department);
}
// comparison function by total for SRecord
int compareSRecordsBytotal(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    if(srecordA->total < srecordB->total)   return 1;
    if(srecordA->total > srecordB->total)   return -1;
    return 0;
}
// comparison function by sid for SRecord
int compareSRecordsBysid(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    return strcmp(srecordA->student.sid, srecordB->student.sid);
}
void sortSRcord(SRecord* srecords, int numSRecords, const char* sortBy) {
    if(strcmp(sortBy, "department") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsBydepartment);
    } else if(strcmp(sortBy, "total") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsBytotal);
    } else if(strcmp(sortBy, "sid") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsBysid);
    }
}
