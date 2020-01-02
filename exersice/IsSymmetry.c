#include <stdio.h> 

int IsSymmetry(char *p, int N) {
	int left, right;
	left = 0;
	right = N-1;
	while (*(p+left) == *(p+right))
		left++, right--;			
	if (left >= right)
		return 1;
	else
		return 0;
}

int symmetryNum(char *p, int N) {
	int left, right;
	left = 0;
	int cnt, Max;
	Max = 0;
	while (left < N-1) {
		right = N-2;
		while (*(p+left) != *(p+right))	
			right--;
		cnt = right-left+1;
		if (IsSymmetry(p+left, cnt) && Max < cnt)
			Max = cnt;
		left++;
	}
	return Max;
}



int main() {
	char A[] = "I0I0Ixxx";
	int N = sizeof(A)/sizeof(A[0]);
	printf("%d", symmetryNum(A, N));
	return 0;
}
