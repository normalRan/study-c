#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int TmpA[], int L, int R, int RrightEnd) {
	int LeftEnd = R-1;
	int N = RrightEnd-L+1;
	int left = L;
	int tmp = L;
	while (L <= LeftEnd && R<= RrightEnd) {
		if (A[L] < A[R])	TmpA[tmp++] = A[L++];
		else 				TmpA[tmp++] = A[R++];
	}
	while (L <= LeftEnd)	TmpA[tmp++] = A[L++];
	while (R <= RrightEnd)	TmpA[tmp++] = A[R++];
	int i;
	for (i=left; i<=RrightEnd; i++)
		A[i] = TmpA[i];
}

void Msort(int A[], int TmpA[], int L, int RrightEnd) {
	if (L == RrightEnd) return;
	int Center = (L+RrightEnd)/2;
	Msort(A, TmpA, L, Center);
	Msort(A, TmpA, Center+1, RrightEnd);
	Merge(A, TmpA, L, Center+1, RrightEnd);
}

void Merger_Sort(int A[], int N) {
	if (N == 1)	
		return;
	int *TmpA = (int *)malloc(N * sizeof(int));	
	int i;
	for (i=0; i<N; i++)
		TmpA[i] = 0;
	Msort(A, TmpA, 0, N-1);
}


int main() {
	int A[6] = {4, 6, 1, 3, 5, 7};
	int n = sizeof(A)/sizeof(A[0]);
	Merger_Sort(A, n);
	int i;
	for (i=0; i<n; i++)
		printf("%3d",A[i]);
	printf("\n");
	
	
	
}
