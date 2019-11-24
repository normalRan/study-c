/* Joseph problem */

# include <stdio.h>

int f(int n, int m) {
	if (n == 1)
	 	return n;
	else {
		int i = (f(n-1, m)+m-1)%n+1;
		return i;
	}
}

int main (void) {
	printf("%d\n", f(4, 3));
	return 0;
}

/*
	1  3  2
	2  4  3
	3  1  0
	4  2  1
*/

