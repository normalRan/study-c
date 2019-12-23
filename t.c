#include <stdio.h>

int f(int N, int cnt) {
	if (N <= 0)
		return cnt;
	else 
		if (N % 10 == 1)
			cnt++;
	return f(N/10, cnt);		
}



int main() {
	int N, cnt;
	cnt = 0;
	puts("please enter a number");
	scanf("%d", &N);
	printf("%d\n", f(N, 0));

}
