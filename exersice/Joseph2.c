#include <stdio.h>

int f(int N, int M, int I, int n) {
	if (n == N)
		return I;
	else 
		return f(N, M, (I+M)%(n+1)+1, n+1);
}

int main() {
	int i = f(5, 0, 1, 1);
	printf("%d\n", i);
	return 0;
}
