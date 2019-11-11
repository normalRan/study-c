#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void copyToNode(Item item, Node *pNode);

void InitializeStack(Stack *pStack) {
	*pStack = NULL;
}

Stack *CreatStack(void) {
	Stack S = NULL;
	Stack *pStack = &S;
	if (pStack != NULL)
		return pStack;
	else {
		puts("memory allcating error!");	
		return NULL;
	}
}

bool isFull(const Stack *pStack) {
	if (isEmpty(pStack))
		return false;
	Node *temp = *pStack;	
	int cnt = 0;
	while (temp != NULL) {
		cnt++;
		temp = temp->next;		
	}
	if (cnt < MaxSize)
		return false;
	else 
		return true;
}

bool isEmpty(const Stack *pStack) {
	if (*pStack == NULL)
		return true;
	else	
		return false;
}

void Push(Stack *pStack, Item item) {
	Node *pNode = (Node *)malloc(sizeof(Node)); 	
	Node *scan  = *pStack;
	if (pNode == NULL) {
		puts("error");
		return;
	}
	copyToNode(item, pNode);
	pNode->next = NULL;
	if (isFull(pStack)) {
		puts("Stack has already Full !");
		Pop(pStack);		
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = pNode;
		return;
	}	
	if (scan == NULL) {
		*pStack = pNode;
	} else {
		while (scan->next != NULL) 
			scan = scan->next;
		scan->next = pNode;
	}	
}

Item Pop(const Stack *pStack) {
	Node *p1 = *pStack;
	Node *p2 = p1->next;
	while (p2->next != NULL) {
		p1 = p1->next;
		p2 = p2->next;
	}
	p1->next = NULL;
	Item item = p2->item;
	free(p2);
	return item;
}

void Traverse(const Stack *pStack, void(*pfun)(Item item)) {
	if (pStack == NULL)	
		return;
	Node *temp = *pStack;
	while (temp != NULL) {
		(*pfun)(temp->item);	
		temp = temp->next;				
	}
	printf("\n");
	return;
}


static void copyToNode(Item item, Node *pNode) {
	pNode->item = item;
}

