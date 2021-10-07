#include <string.h>
#include <stdlib.h>
#include "Employee.h"

Employee EmployeeTable[] = {
    {1001l, "Daphne Borromeo", "909-555-2123", 8.78},
    {1011l, "Tammy Franklino", "213-555-1212", 7.65},
    {1140l, "Dorris Perl", "310-555-1215", 8.65},
    {4011l, "Tony Bobcat", "909-555-1235", 10.32},
    {5045l, "Brian Height", "714-5555-2749", 15.2}
};

const int EmployeeTableEntries = sizeof(EmployeeTable)/sizeof(EmployeeTable[0]);