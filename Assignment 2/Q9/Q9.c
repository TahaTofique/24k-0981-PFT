#include <stdio.h>
#include <stdbool.h>

char grid[5][5] = {
	{' ', ' ', 'I', 'X', ' '},
	{' ', 'X', ' ', ' ', ' '},
	{'I', ' ', 'X', 'X', ' '},
	{' ', ' ', ' ', 'I', 'X'},
	{' ', 'X', ' ', ' ', 'P'}
};

int povrow = 4;
int povcow = 4;
int prevrow = 4;
int prevcol = 4;

void printgrid() {
	int i, j;
	for(i = 0; i <= 4; i++) {
		printf("{");
		for(j = 0; j <= 4; j++) {
			if(j != 4) {
				printf("%c|", grid[i][j]);
			} else {
				printf("%c", grid[i][j]);
			}
		}
		printf("}\n");
	}
}

bool validatemove(char input) {
	int row = povrow, col = povcow;

	if(input == 'W' || input == 'w') {
		row = povrow - 1;
	} else if(input == 'S' || input == 's') {
		row = povrow + 1;
	} else if(input == 'A' || input == 'a') {
		col = povcow - 1;
	} else if(input == 'D' || input == 'd') {
		col = povcow + 1;
	}

	if(row > 4 || col > 4 || row < 0 || col < 0) {
		return false;
	} else if(grid[row][col] == 'X') {
		return false;
	} else {
		prevrow = povrow;
		prevcol = povcow;
		povrow = row;
		povcow = col;
		return true;
	}
}

void upgrid() {
	grid[povrow][povcow] = 'P';
	grid[prevrow][prevcol] = ' ';
}

int main() {
	char input = ' ';
	printf("Welcome to the grid game!\n");

	while(input != 'x' && input != 'X') {
		printgrid();
		printf("W: Up\nS: Down\nA: Left\nD: Right\nX: Quit\nEnter a move: ");
		scanf(" %c", &input);

		if(validatemove(input) == true) {
			upgrid();
		} else {
			printf("Invalid move. Try again.\n");
		}
	}

	printf("Thank you for playing!\n");
	return 0;
}
