#include <stdio.h>
#include "stack.h"

int main (void) {
	Stack *S  = CreatStack();
	Item temp;
	while (scanf("%d", &temp.date)) {
		Push(S, temp);	
	}
	if (Pop(S))
		puts("succes");
	int n = countStack(S);	
	printf("%d\n", n);
	return 0;
}
