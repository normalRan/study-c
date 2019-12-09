#include <stdio.h>

void Insert_Sort(int A[], int N) {
	int i;
	for (i = 1; i < N; i++) {
		int tmp = A[i];	
		int j = i-1;
		for (j; j >= 0 && tmp < A[j]; j--) 
				A[j+1] = A[j];
		A[j+1] = tmp;
	}
}			

int main(void) {
	int A[7] = {21, 3 ,65, 23, 4, 47, 88};
	int N = sizeof(A)/sizeof(A[0]); 
	Insert_Sort(A, N);
	int i;
	for (i=0; i<N; i++)
		printf("%3d", A[i]);
	printf("\n");
}
