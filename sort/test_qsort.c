#include <stdio.h>
#include <math.h>
#include <time.h>
#define infinity 1000000

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
/*                                                              */
/*                                          2019.12.11 00:54    */

clock_t start, stop;
double duration1;
double duration2;
double duration3;


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
		while (A[L] <  pivot) L++;
		while (A[R] >= pivot) R--;
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
		while (A[L] <  pivot) L++;
		while (A[R] >= pivot) R--;
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
	else {
		srand(time(0));
		Qs_2(A, 0, N-1);
	}
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
	if (left+1 == right) {
		if (A[left] > A[right])
			Swap(&A[left], &A[right]);
		return;
	}
	int pivot = median(A, left, right);
	int L = left;
	int R = right;
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
	else  	
		Qs_3(A, 0, N-1);		
	
}

void value(int A[], int N) {
	srand(time(0));	
	int i;
	for (i=0; i<N; i++)	
		A[i] = rand()%infinity+1;
}

int randN() {
	srand(time(0));
	return rand()%100;
}

double rank1(int A[], int N) {
	int tmpA[N];
	int i;
	for (i=0; i<N; i++) 
		tmpA[i++] = A[i++];
	start = clock();
	qsort_1(tmpA, N);
	stop = clock();
	return (double)(stop-start)/CLOCKS_PER_SEC;
}

double rank2(int A[], int N) {
	int tmpA[N];
	int i;
	for (i=0; i<N; i++) 
		tmpA[i++] = A[i++];
	start = clock();
	qsort_2(tmpA, N);
	stop = clock();
	return (double)(stop-start)/CLOCKS_PER_SEC;
}

double rank3(int A[], int N) {
	int tmpA[N];
	int i;
	for (i=0; i<N; i++) 
		tmpA[i++] = A[i++];
	start = clock();
	qsort_3(tmpA, N);
	stop = clock();
	return (double)(stop-start)/CLOCKS_PER_SEC;
}

int main() {
	srand(time(0));
	int i = 0;
	start = clock();
	while (i < infinity) {	
		int	n = randN();
		int A[n];
		int N = sizeof(A)/sizeof(A[0]);
		value(A, N);
		duration1 += rank1(A, N);	
		duration2 += rank2(A, N);	
		duration3 += rank3(A, N);	
		i++;
	} 
	stop = clock();
	printf("right hand :time consuming = %6.6f\n", duration1);
	printf("random :time consuming = %6.6f\n", duration2);
	printf("median :time consuming = %6.6f\n", duration3);
/*	for (i=0; i<N; i++)
		printf("%3d", A[i]);
	printf("\n");
*/

}

/*
int main01() {
	int A[7];
	int i;
	int N = sizeof(A)/sizeof(A[0]);
	value(A, N);
	for (i=0; i<N; i++)
		printf("%3d", A[i]);
	printf("\n");
	qsort_3(A, N);
	for (i=0; i<N; i++)
		printf("%3d", A[i]);
	printf("\n");
	return 0;
}
*/
