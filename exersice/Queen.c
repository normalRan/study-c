/* eight Queue */

#include <stdio.h>

#define MAXSIZE 8

void show_grid(char grid[][MAXSIZE]) {
	int i,k;
	for ( i=0; i<MAXSIZE; i++ ) {
		for ( k=0; k<MAXSIZE; k++ )	
			printf("%3c", grid[i][k]);	
		printf("\n");
	}
}

int check(char grid[][MAXSIZE], int row, int col) {
	if (row == 0) return 1;
	int t_row = row;
	int t_col = col;
	for (; t_row>=0; t_row--) {
		if (grid[t_row][t_col] == '*')
			return 0;
	}			
	t_row = row;
	t_col = col;
	while (t_row && t_col) {
		if (grid[--t_row][--t_col] == '*') 
			return 0;
	}	
	t_row = row;
	t_col = col;
	while (t_row && t_col<MAXSIZE-1) {
		if (grid[--t_row][++t_col] == '*')	
			return 0;
	}
	return 1;
}


void put(char grid[][MAXSIZE], int row) {
	if (row == MAXSIZE) {
		show_grid(grid);	
		printf("\n\n");
		return;
	}
	int col;
	for ( col=0; col<MAXSIZE; col++ ) {
		if (check(grid, row, col)) {
			grid[row][col] = '*';
			put(grid, row+1);
			grid[row][col] = ' ';
		} else continue; 
	}
	return;
}

int main (void) {
	char grid[MAXSIZE][MAXSIZE];
	int i,k;
	for ( i=0; i<MAXSIZE; i++ ) 
		for ( k=0; k<MAXSIZE; k++ )	
			grid[i][k] = ' ';
	printf("\n");
	put(grid, 0);
}

																		/*
																		 **      2019.11.21
																		*/

