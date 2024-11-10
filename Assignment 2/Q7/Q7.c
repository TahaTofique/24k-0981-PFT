#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool validatestring(char arr[6][5], char *string) {
	int len = strlen(string);
	int horizontal = 5 - len;
	int vertical = 6 - len;

	if (len > 6) {
		return false;
	}

	for (int row = 0; row < 6; row++) {
		for (int start = 0; start <= horizontal; start++) {
			int match = 1;
			for (int k = 0; k < len; k++) {
				if (arr[row][start + k] != string[k]) {
					match = 0;
					break;
				}
			}
			if (match) {
				return true;
			}
		}
	}

	for (int col = 0; col < 5; col++) {
		for (int start = 0; start <= vertical; start++) {
			int match = 1;
			for (int k = 0; k < len; k++) {
				if (arr[start + k][col] != string[k]) {
					match = 0;
					break;
				}
			}
			if (match) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	char grid[6][5];
	char word[100];
	int score = 0;

	srand(time(0));

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			grid[i][j] = 'a' + (rand() % 26);
		}
	}

	grid[5][0] = '0';
	grid[5][1] = '9';
	grid[5][2] = '8';
	grid[5][3] = '1';



	printf("Grid:\n");
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			printf(" %c", grid[i][j]);
		}
		printf("\n");
	}


	while (1) {
		printf("Enter a word or type 'end' to stop: ");
		scanf("%s", word);

		if (strcmp(word, "end") == 0) {
			break;
		}

		if (validatestring(grid, word)) {
			printf("FOUND ! \n");
			score++;
		} else {
			printf("WAKE UP ! \n");
		}
		printf("Score: %d\n", score);
	}

	printf("Final score: %d\n", score);
	return 0;
}
