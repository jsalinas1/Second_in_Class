#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(){
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); ///
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); ///
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

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

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-555-1212");
    
    if(matchPtr != NULL)
        printf("Employee Phone 213-555-1212 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee  Phone 213-555-1212 is not found in the record\n");

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-152-4333");
    
    if(matchPtr != NULL)
        printf("Employee Phone 213-152-4333 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Phone 213-152-4333 is not found in the record\n");

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 15.2);
    
    if(matchPtr != NULL)
        printf("Employee Salary 15.2 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Salary 15.2 is not found in the record\n");

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 16.2);
    
    if(matchPtr != NULL)
        printf("Employee Salary 16.2 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Salary 16.2 is not found in the record\n");

    return EXIT_SUCCESS;
}