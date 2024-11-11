#include<stdio.h>
int main() {
int numStars;


	printf("Enter an odd number of stars: ");
	scanf("%d", &numStars);


	if (numStars % 2 != 0) {
		int spacing = 1; 
		int maxSpacing = (numStars + (numStars - 2)); 

		
		for (int row = 0; row < numStars - 1; row++) {
			for (int space = 1; space <= maxSpacing - row; space++) {
				printf(" ");
			}
			printf("*"); 
		
				if (row != 0) {
				for (int innerSpace = 0; innerSpace < spacing; innerSpace++) {
					printf(" ");
				}
				spacing = spacing + 2; 
				printf("*"); 
			}
			printf("\n");
		}

		
		for (int i = 0; i < numStars; i++) {
			printf("*");
		}

		for (int i = 0; i < spacing; i++) {
			printf(" ");
		}

		for (int i = 0; i < numStars; i++) {
			printf("*");
		}
		printf("\n"); 

		spacing = spacing + 2 * (numStars - 2); 
		
		for (int row = 1; row < numStars; row++) {
			for (int space = 0; space != row; space++) {
				printf(" ");
			}
			printf("*"); 
	
			for (int innerSpace = 0; innerSpace < spacing; innerSpace++) {
				printf(" ");
			}
			spacing = spacing - 2; 
			printf("*\n"); 
		}

	
		maxSpacing = 1; 
		for (int row = 0; row < numStars - 1; row++) {
			for (int space = 0; space < (numStars - 2) - row; space++) {
				printf(" ");
			}
			printf("*");
			for (int space = 0; space < (numStars - 2) - row; space++) {
				printf(" ");
			}
			if (row != numStars - 2) {
				printf("*"); 
			} else {
				printf(" "); 
			}
			for (int g = 1; g <= maxSpacing; g++) {
				printf(" ");
			}
			if (row != numStars - 2) {
				printf("*"); 
			} else {
				printf(" "); 
			}
			if (row != numStars - 1) {
				maxSpacing = maxSpacing + 4; 
			} else {
				maxSpacing = maxSpacing + 6; 
			}
	
			for (int space = 0; space < (numStars - 2) - row; space++) {
				printf(" ");
			}
			printf("*\n"); 
		}
	} else {
		
		printf("The number entered is not odd!\n");
	}
	return 0;
}
