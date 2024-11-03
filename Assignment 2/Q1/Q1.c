
#include <stdio.h>

int main()
{

	int arr[]= {0,9,4,6,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	int min=arr[0];
	int min2=arr[4];
	for(int i=1; i<n; i++) {
		if(arr[i]<min) {
			min = arr[i];
		}
	}
	for(int i=0;i<n;i++){
	    if (arr[i] > min && arr[i] < min2){
	       min2=arr[i];
	   } 
	}

	printf("The second smallest number is : %d",min2);

return 0;

}
