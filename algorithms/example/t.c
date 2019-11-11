#include <stdio.h>

int fMax(int *a, int num) {
	if (num == 1)
		return *a;
	int Max, temp;
	Max = temp = 0;
	int leftMax, rightMax;
	leftMax = rightMax = 0;
	int midIndex = num/2;
	for (int i = midIndex-1; i>=0; i--) {
		temp += a[i];
		if (temp > Max)
			leftMax = temp;
	}	
	printf("leftMax = %d\n", leftMax);
	temp = 0;
	for (int i = midIndex+1; i<num; i++) {
		temp += a[i];
		if (temp > rightMax)
			rightMax = temp;
	}
	printf("rightMax = %d\n", rightMax);
	if (leftMax > rightMax)
		Max = leftMax;
	else
		Max = rightMax;
	if (leftMax + rightMax > Max)
		Max = leftMax + rightMax;
	Max = Max+a[midIndex];
	int left = fMax(a,midIndex);
	int right = fMax(a+midIndex,num-midIndex);
	if (Max < left)
		Max = left;
	if (Max < right)
		Max = right;

	return Max;
}

int fMax2(int *a, int n) {
	int temp, Max;	
	temp = Max = 0;
	for (int i = 0; i<n; i++) {
		temp += a[i];	
		if (Max < temp) 
			Max = temp;
		if (temp < 0)
			temp = 0;
	}
	return Max;
}

int main (void)
{
	int a[6] = {-2, 7, -2, 5, -9, 2};	
	int n =sizeof(a)/sizeof(a[0]);
	for (int i = 0; i<n; i++) 
		printf("%d\t", a[i]);
	printf("\n");
	int Max = fMax2(a, n);
	printf("Max = %d\n", Max);
}
