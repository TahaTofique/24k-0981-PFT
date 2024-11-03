#include <stdio.h>

int main()
{
	int n,i;

	printf("Enter Num of values : ");
	scanf("%d",&n);
	int arr[n];

	printf("\n");

	for(i=0; i<n; i++) {
		printf("Enter Values %d: ",i+1);
		scanf("%d",&arr[i]);
	}

	printf("\n");


	for(i=0; i<n; i++) {
		printf("Value %d: ",i+1);
		for(int j=0; j<arr[i]; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	
printf ("Vertical:\n");

int maxheight=0;
for(i=0;i<n;i++){
    if(arr[i] > maxheight){
        maxheight=arr[i];
    }
}

for(int j =maxheight; j>0; j--) {
		for(i=0; i<n; i++) {
		    if(arr[i]>=j){
			printf("* ");
		}else{
		printf("  ");
	}}
printf("\n");
}
	return 0;
}
