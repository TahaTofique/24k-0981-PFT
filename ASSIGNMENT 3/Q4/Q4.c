#include <stdio.h>
#include <stdlib.h>

struct Employee{
	int* ratings;
	int totalscore;
};

void inputEmployees(int** ratings,int numEmployees,int numPeriods) {
	for(int i=0; i<numEmployees; i++) {
		printf("Enter ratings for Employee %d :\n ",i+1);
		ratings[i]=(int*)malloc(numPeriods*sizeof(int));
		for (int j=0; j< numPeriods; j++) {
			do {
				printf("Rating for Period %d (1-10) : ",j+1);
				scanf("%d",&ratings[i][j]);
			} while (ratings[i][j] < 1 || ratings[i][j]>10);
		}
	}
}
void displayPerformance(int** ratings,int numEmployees, int numPeriods) {
	printf("Employee Performance : \n");
	for (int i=0; i<numEmployees; i++) {
		printf("Employee %d : ",i+1);
		for(int j=0; j<numPeriods; j++) {
			printf("%d",ratings[i][j]);
		}
		printf("\n");
	}
}

int findEmployeeofTheYear(int** ratings,int numEmployees, int numPeriods) {
	int maxAvgIndex = 0;
	float maxAvg = 0;


	for (int i=0; i<numEmployees; i++) {
		int sum = 0;
		for(int j=0; j<numPeriods; j++) {
			sum +=ratings[i][j];
		}
		float avg = (float)sum/numPeriods;
		if (avg>maxAvg) {
			maxAvg=avg;
			maxAvgIndex=i;
		}
	}
	return maxAvgIndex;
}

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods) {
	int maxPeriodIndex = 0;
	float maxAvg = 0;

	for (int j = 0; j < numPeriods; j++) {
		int sum = 0;
		for (int i = 0; i < numEmployees; i++) {
			sum += ratings[i][j];
		}
		float avg = (float)sum / numEmployees;
		if (avg > maxAvg) {
			maxAvg = avg;
			maxPeriodIndex = j;
		}
	}
	return maxPeriodIndex;
}

int findWorstPerformingEmployee(int**ratings,int numEmployees,int numPeriods){
    int minAvgIndex=0;
    float minAvg=11;
    
    for(int i=0;i<numEmployees;i++){
        int sum=0;
        for(int j=0;j<numPeriods;j++){
            sum+=ratings[i][j];
        }
        float avg = (float)sum/numPeriods;
        if(avg<minAvg){
            minAvg = avg;
            minAvgIndex = i;
        }
    }
    return minAvgIndex;
}
int main()
{
	int numEmployees,numPeriods;
	    printf("Enter Number of Employees : \n");
	scanf("%d",&numEmployees);
	   printf("Enter number of evaluation periods: \n");
    scanf("%d", &numPeriods);
    
    int** ratings = (int**)malloc(numEmployees * sizeof(int*));
    
    inputEmployees(ratings,numEmployees,numPeriods);
    displayPerformance(ratings,numEmployees,numPeriods);
    
    int bestEmployee = findEmployeeofTheYear (ratings, numEmployees, numPeriods);
    printf("\nEmployee of the Year: Employee %d\n", bestEmployee + 1);
    
    int bestPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Period: %d\n", bestPeriod + 1);
    
    int worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstEmployee+ 1);
    
    for(int i=0;i<numEmployees;i++){
        free(ratings[i]);
    }
    free(ratings);
	return 0;
}
