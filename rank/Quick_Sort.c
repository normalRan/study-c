#include <stdio.h>

void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void select_pivot(int A[], int left, int right) {
	int Center = left+right/2; 
	if (A[left] > A[Center])
		Swap(&A[left], &A[Center]);
	if (A[left] > A[right])
		Swap(&A[left], &A[right]);
	if (A[Center] > A[right])
		Swap(&A[Center], &A[right]);

	Swap(&A[Center], &A[right]);
}

only_two(int A[], int left, int right) {
	if (A[left] < A[right])
		return;
	else
		Swap(&A[left], &A[right]);
}

void Quick_s(int A[], int left, int right) {
	if (left >= right)
		return;
	if (right - left == 1) {
		only_two(A, left, right);			
		return;
	}	
	int left_p  = left;
	int right_p = right-1;
	select_pivot(A, left, right);
	int pivot = right;
	while (left_p < right_p) {
		while ( A[left_p] < A[pivot] && left_p < right)	
			left_p++;	
		while (A[right_p] > A[pivot] && right_p > left)
			right_p--;
		if (left_p < right_p)
			Swap(&A[left_p], &A[right_p]);
	}
	Swap(&A[left_p], &A[pivot]);
	pivot = left_p;
	Quick_s(A, left, pivot-1);
	Quick_s(A, pivot+1, right);
}

void Quick_Sort(int A[], int N) {
	if  (N == 1)			
		return;
	else
		Quick_s(A, 0, N-1);	
}

int main() {
	int A[7] = {3, 6, 1, 8, 2, 5, 7};
	int n = sizeof(A)/sizeof(A[0]);
	Quick_Sort(A, n);
	int i;
	for (i=0; i<n; i++)
		printf("%4d", A[i]);
	printf("\n");
	return 0;
}

