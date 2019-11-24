#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *CreatStack(void) {
	Stack *S;
	S = (Stack *)malloc(sizeof(Stack));
	Node *pNode = (Node *)malloc(sizeof(Node));
	S->head = pNode;	
	S->count = 0;
	pNode->next = NULL;
	return S;
}

bool isEmpty(Stack *S) {
	Node *p = S->head;	
	return (!p->next);
}

void Push(Stack *S, Item item) {
	Node *new = (Node *)malloc(sizeof(Node));	
	if (!new) 
		return;	
	new->item = item;
	Node *sNode = S->head;;
	new->next = sNode->next;
	sNode->next = new;
	S->count++;
}

bool Pop(Stack *S) {
	if (isEmpty(S)) {
		puts("Stack empty !");	
		return false;
	}
	Node *sNode = S->head;
	Node *freeNode = sNode->next;
	sNode->next = freeNode->next;
	free(freeNode);
	S->count--;
	return true;
}

int countStack(Stack *S) {
	return S->count;
}

