#include <stdio.h>
#include <math.h>
#include <time.h>

/*            Test the difference caused by                     */
/*                different  methods                            */
/*                  	   of                                   */
/*                   select  pivot                              */
/*                                                              */
/*                                                              */
/* 	I used three different methods                              */
/* 	1. select right-hand (could be any side actually)           */
/*  2. random select                                            */
/*  3. take the median                                          */


clock_t start, stop;
double duration;


void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void Qs_1(int A[], int left, int right) {
	if (left >= right)	
		return;
	if (left+1 == right)
		if (A[left] < A[right])
			return;
	int L = left;
	int R = right-1;
	int pivot = A[right];
	while (L < R) {
		while (A[L] < pivot) L++;	
		while (A[R] > pivot) R--;
		if (L < R) Swap(&A[L], &A[R]);
	}	
	Swap(&A[L], &A[right]);
	Qs_1(A, left,  L-1);
	Qs_1(A, L+1, right);
}

/* Select the right-hand pivot */
void qsort_1(int A[], int N) {
	if (N == 1)		
		return;
	else
		Qs_1(A, 0, N-1);
}

int random(int A[], int left, int right) {
	int r_index = rand()%(right-left+1)+left;
	int pivot = A[r_index];
	Swap(&A[r_index], &A[right]);
	return pivot;
}

void Qs_2(int A[], int left, int right) {	
	if (left >= right)	
		return;
	int pivot = random(A, left, right);
	if (left+1 == right)
		if (A[left] < A[right])
			return;
	int L = left;
	int R = right-1;
	while (L < R) {
		while (A[L] < pivot) L++;
		while (A[R] > pivot) R--;
		if (L < R) Swap(&A[L], &A[R]);
	}
	Swap(&A[L], &A[right]);
	Qs_2(A, left,  L-1);
	Qs_2(A, L+1, right);
	
}

/* Select pivot at random */
void qsort_2(int A[], int N) {
	if (N == 1)	
		return;
	else
		Qs_2(A, 0, N-1);
}


int median(int A[], int left, int right) {
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

void Qs_3(int A[], int left, int right) {
	if (left >= right)
		return;
	if (left+1 == right)
		if (A[left] < A[right])
			return;
	int pivot = median(A, left, right);
	int L = left;
	int R = right-1;
	while (L < R) {
		while (A[++L] < pivot);
		while (A[--R] > pivot);
		if (L < R) Swap(&A[L], &A[R]);
	}
	Swap(&A[L], &A[right]);
	Qs_3(A, left, L-1);
	Qs_3(A, L+1, right);
}

/* Select median as pivot */
void qsort_3(int A[], int N) {
	if (N == 1)
		return;
	else { 	
		srand(time(0));
		Qs_3(A, 0, N-1);		
	}
}


int main() {
	int A[7] = {6, 7, 2, 1, 3, 5, 4};
	int N = sizeof(A)/sizeof(A[0]);
	start = clock();
	int i = 0;
	while (i<500000) {	
	/*	Qs_1(A, 0, N-1); */
	/*	Qs_2(A, 0, N-1); */
		Qs_3(A, 0, N-1); 
		i++;
	} 
	stop = clock();
	duration = (double)(stop-start)/CLOCKS_PER_SEC;
	printf("time consuming = %6.3f\n", duration);
	for (i=0; i<N; i++)
		printf("%3d", A[i]);
	printf("\n");

}
