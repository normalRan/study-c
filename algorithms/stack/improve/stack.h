#ifndef STACK_H_ 
#define STACK_H_
#include <stdbool.h>

typedef struct Item {
	int date;
}Item;

typedef struct node {
	Item item;	
	struct node *next;
}Node;


typedef struct stack {
	Node *head;		
	int count;
}Stack;

/* interface fanc */

Stack *CreatStack(void);

bool isEmpty(Stack *S);

void Push(Stack *S, Item item);

bool Pop(Stack *S);

int countStack(Stack *S);

#endif
