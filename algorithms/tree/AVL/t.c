#include <stdlib.h>
#include <stdio.h>
#include "avl.h"
/* gcc with avl.c */

void Print(Position P) {	
	if (P)
	printf("%3d", P->Element);
}

void f(Position P) {
	if (P == NULL)
		return;
	printf("%3d",P->Element);
	f(P->Left);
	f(P->Right);
}

int main(void) {
	AvlTree T;
	int n;	
	while (scanf("%d", &n))
		T = Insert(n, T);
	f(T);
	printf("\n");
 	T = Delete(1, T);
	f(T);
	printf("\n");
	return 0;
	// 
	// 4 2 1 3 6 7
}

