#include <stdio.h>


void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int Select_Pivot(int A[], int left, int right) {
	int Center = (left+right)/2;
	if (A[left] > A[Center])
		Swap(&A[left], &A[Center]);
	if (A[left] > A[right])
		Swap(&A[left], &A[right]);
	if (A[Center] > A[right])
		Swap(&A[Center], &A[right]);
	Swap(&A[Center], &A[right]);
	return A[right];
}


void Qsort(int A[], int left, int right) {
	if (left >= right)
		return;
	int pivot = Select_Pivot(A, left, right);
	int L = left;
	int R = right;
	if (R - L != 1) {
		while (L < R) {
			while (A[++L] < pivot);	
			while (A[--R] > pivot);
			if (L < R)
				Swap(&A[L], &A[R]);
		}
	}
	Swap(&A[L], &A[right]);
	Qsort(A, left, L-1);
	Qsort(A, L+1, right);
}


void Quick_Sort(int A[], int N) {
	if (N == 1)
		return;
	else				
		Qsort(A, 0, N-1);
}

int main() {
	int A[7] = {7, 3, 2, 4, 1, 6, 5};
	int N = sizeof(A)/sizeof(A[0]);
	//Select_Pivot(A, 0, N-1);
	Quick_Sort(A, N);
	int i;
	for (i=0; i<N; i++)
		printf("%3d", A[i]);
	printf("\n");
}
