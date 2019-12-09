#include <stdio.h>

void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Heapify(int A[], int N) {
	int i, k;
	for (i=1; i<N; i++)
		for (k=i; k>0 && A[k]>A[(k-1)/2]; k=(k-1)/2)
			Swap(&A[k], &A[(k-1)/2]);
}

void Heap_Sort(int A[], int N) {
	int i;						
	Heapify(A, N);
	for (i=N-1; i>0; i--) {
		Swap(&A[0], &A[i]);	
		Heapify(A, i);
	}
}

int main() {
	int A[6] = {1, 3, 4, 2, 6, 5};
	int N = sizeof(A)/sizeof(A[0]);
	Heap_Sort(A, N);
	int i;
	for (i=0; i<N; i++)
		printf("%3d", A[i]);
	printf("\n");
}

