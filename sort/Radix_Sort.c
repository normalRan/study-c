#include <stdio.h>
#include <math.h>
#include <stdio.h>

void makeEmpty(int Bin[][10]) {
	int i, j;
	for (i=0; i<10; i++)
		for (j=0; j<10; j++)
			Bin[i][j] = -1;
}


void PutToBin(int X, int digit, int Bin[][10]) {
	int n = (X/digit)%10;
	int i , j;
	for (i=0; i<10 && Bin[i][n]!=-1; i++);
		Bin[i][n] = X;
} 

void updateArray(int A[], int Bin[][10]) {
	int n, i, j;
	n = 0;
	for (i=0; i<10; i++)
		for (j=0; j<10; j++)
			if (Bin[j][i] != -1)	
				A[n++] = Bin[j][i];
}

void show(int Bin[][10]) {
	printf("\n");
	int i,j;
	for (i=0; i<10; i++) {
		for (j=0; j<10; j++)	
			printf("%3d", Bin[i][j]);
		printf("\n");
	}
	printf("\n");
}

void sort(int A[], int N) {
	int Bin[10][10];
	makeEmpty(Bin);
	int i;
	for (i=0; i<N; i++)	
		PutToBin(A[i], 1, Bin);
	updateArray(A, Bin);	
//	show(Bin);
	makeEmpty(Bin);
	for (i=0; i<N; i++)	
		PutToBin(A[i], 10, Bin);
	updateArray(A, Bin);
//	show(Bin);
}


void Radix_Sort(int A[], int N) {
	if (N == 1)
		return;
	sort(A, N);
}

void value(int A[], int N) {
	srand(time(0));	
	int i;	
	for (i=0; i<N; i++)
		A[i] = rand()%100;
}

int main() {
	int A[10];	 
	int N = sizeof(A)/sizeof(A[0]);
	value(A, N);
	Radix_Sort(A, N);
	int i;
	for (i=0; i<N; i++)
		printf("%3d", A[i]);
	printf("\n"); 
	return 0;
}
