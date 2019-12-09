#include <stdio.h>

void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Buddle_Sort(int A[], int N) {
	int i,k;
	for (i=0; i<N-1; i++) {
		int flag = 0;
		for (k=0; k<N-i-1; k++) {
			if (A[k] > A[k+1]) {
				Swap(&A[k], &A[k+1]);
				flag = 1;		
			}
		}
		if (flag == 0)	break;
	}	
}

int main() {
	int A[7] = {3, 4, 2, 8, 3, 7, 9};
	int N = sizeof(A)/sizeof(A[0]);	
	Buddle_Sort(A, N);
	int i; 
	for (i=0; i<N; i++)
		printf("%3d", A[i]);
	printf("\n");
}
