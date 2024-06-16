#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "myhead.h"

void printSRecords(SRecord srecords[], int numSRecords) {
    printf("%-8s %5s %8s    %-6s %5s %6s %5s %6s %6s %6s\n", " Name", "Department", "Grade", "SID", "HW", "Quiz", "Mid", "Final", "Other", "Total");
    printf("--------------------------------------------------------------------------------\n");
    for (int i=0; i<numSRecords; i++){
        printf("%-14s %-7s %8d    %-10s %4.1f %5.1f %5.1f %5.1f %6.1f %6.1f\n", srecords[i].student.name, srecords[i].student. department, srecords[i].student.grade, srecords[i].student.sid, srecords[i].hw, srecords[i].quiz, srecords[i].midterm, srecords[i].final, srecords[i].other, srecords[i].total);
    }
}
int readSRecordsFromCSV(const char* filename, SRecord srecords[], int maxNumSRecodes) {
    FILE* file=fopen(filename, "r"); //read file
    if(file==NULL){
        printf("Failed to open file %s\n", filename);
        return 0;
    }
    char line[1024];
    fgets(line, 1024, file); //skip the first line
    int numSRecords=0;
    while (fgets(line, 1024, file) && numSRecords< maxNumSRecodes){
        sscanf(line, "%[^,],%[^,],%d,%[^,],%lf,%lf,%lf,%lf,%lf,%lf", srecords[numSRecords].student.department, srecords[numSRecords].student.sid, &srecords[numSRecords].student.grade, srecords[numSRecords].student.name, &srecords[numSRecords].hw, &srecords[numSRecords].quiz, &srecords[numSRecords].midterm, &srecords[numSRecords].final, &srecords[numSRecords].other);

        srecords[numSRecords].total = srecords[numSRecords].hw * HW_WEIGHT + srecords[numSRecords].quiz * QUIZ_WEIGHT + srecords[numSRecords].midterm * MIDTERM_WEIGHT + srecords[numSRecords].final * FINAL_WEIGHT + srecords[numSRecords].other * OTHER_WEIGHT;
        
        numSRecords++;
    }
    fclose(file);
    return numSRecords;
}
