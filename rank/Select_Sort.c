#include <stdio.h>

void Select_Sort(int A[], int N)
{
	int i, k;
	for (i = 0; i<N-1; i++) {
		int min = A[i];
		int minIndex = i;
		for (k = i+1; k<N; k++) {
			if (A[k] < min) { 
				min = A[k];	
				minIndex = k;
			}
		}
		A[minIndex] = A[i];
		A[i] = min;
	}	
}

int main (void)
{
	int A[7] = {42, 31, 3, 89, 2, 21, 66};
	int N = sizeof(A)/sizeof(A[0]);
	Select_Sort(A, N);
	int i;
	for (i=0; i<N; i++) 
		printf("%d\t", A[i]);	
	printf("\n");
	return 0;
}
