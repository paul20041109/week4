#include <stdio.h>
#define  MAX_STUDENT 100
#include "myhead.h"

int main()
{
    SRecord srecords[MAX_STUDENT];
    int numSRecords = readSRecordsFromCSV("records.csv", srecords, MAX_STUDENT);

    printSRecords(srecords, numSRecords);

    sortSRcord(srecords, numSRecords, "total");
    printf("\n\nAfter sorting by total:\n");
    printSRecords(srecords, numSRecords);
    
    return 0;
}
