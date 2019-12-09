#include <stdio.h>

void Shell_Sort(int A[], int N) {
	int i, gap;
	for (gap = 2; gap > 0; gap--) {
		for (i = gap-1; i < N; i+=gap) {
			int tmp = A[i];		
			int k = i-gap;
			for (k; k>=0 && tmp<A[k]; k-=gap) 
				A[k+gap] = A[k];	
			A[k+gap] = tmp;
	    }
	}
}

int main (void) { 
	int A[7] = {5, 4, 3, 9, 89, 45, 54};
	int N = sizeof(A)/sizeof(A[0]);
	Shell_Sort(A, N);
	int i;
	for (i = 0; i<N; i++) 
		printf("%d\t", A[i]);	
	printf("\n");
	return 0;
}
