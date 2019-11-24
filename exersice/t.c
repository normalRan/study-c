#include <stdio.h>

int main (void) {
	int a[4] = {3, 4, 6, 2};
	int num = 4;
	for (int n = 0; n<num; n++) {
		printf("%d\t", a[n]);	
	}
	printf("\n");
	int i, j; 
	for (i =1; i<num; i++) {
		int base = a[i];	
		j = i -1;
		for (j; j>=0; j--) {
			if (base < a[j]) {
				a[j+1] = a[j];	
			} else
				break;
		}
		a[j+1] = base;
	}
	for (int n = 0; n<num; n++) {
		printf("%d\t", a[n]);	
	}
	printf("\n");
}
	

