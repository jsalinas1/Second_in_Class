#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(){
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); ///
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); ///

    extern Employee EmployeeTable[]; /// Lets the compiler know that we already have employeetable defined in employeeTablec
    extern const int EmployeeTableEntries; ///Lets the compilor know that we already have entries defined in .c file

    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    if(matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else 
        printf("Employee ID is NOT found in the record\n");

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

    if(matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else 
        printf("Employee Tony Bobcat is NOT found in the record\n");

    return EXIT_SUCCESS;
}