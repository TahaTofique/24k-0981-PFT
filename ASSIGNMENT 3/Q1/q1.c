#include <stdio.h>
#include <string.h>
#define NUM_EMPLOYEES 4

struct Employee{
    int employeecode;
    char employeename[20];
    char dateofjoining[11];
    
};
  int getYear(const char *date) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);
    return year;
}


int calculateTenure(const char *joiningDate, const char *currentDate) {
    int joinYear = getYear(joiningDate);
    int currentYear = getYear(currentDate);
    return currentYear - joinYear;
}
    void displayEligibleEmployees(struct Employee employees[], int count, const char *currentDate) {
    int eligibleCount = 0;

    printf("\nEmployees with More Than 3 Years of Tenure:\n");
    printf("Code\tName\t\tDate of Joining\n");

    for (int i = 0; i < count; i++) {
        int tenure = calculateTenure(employees[i].dateofjoining, currentDate);
        if (tenure > 3) {
            eligibleCount++;
            printf("%04d\t%-10s\t%s\n", employees[i].employeecode, employees[i].employeename, employees[i].dateofjoining);
        }
    }
        printf("\nTotal Employees with More Than 3 Years of Tenure: %d\n", eligibleCount);
}

int main()
{
    struct Employee employees[NUM_EMPLOYEES]={
    {0001,"Ali","2/03/2019"},
    {0002,"Omer","6/09/2020"},
    {0003,"Jalil","8/08/2018"},
    {0004,"Ahmed","8/04/2023"}};
        
        char currentDate[11] ;
        
        printf("Enter Current Date DD/MM/YYYY : ");
        scanf("%s",currentDate);
 displayEligibleEmployees(employees, NUM_EMPLOYEES, currentDate);

   

    return 0;
}
