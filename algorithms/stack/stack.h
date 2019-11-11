#ifndef STACK_H
#define STACK_H
#define MaxSize 5
#include <stdbool.h>

typedef struct item {
	int date;
}Item;

typedef struct node {
 	Item item;
	struct node *next;
}Node;

typedef Node *Stack;

/* interface */

/* operation      : Initialize Skack                            */
/* post condition : *pSkack -> NULL                             */
void InitializeStack(Stack *pSkack);

/* operation      : Creat Stack									*/
/* pre condition  : size < MaxSize								*/
/* post conditon  : return Stack								*/
Stack *CreatStack(void);

/* operation      : Verify that Stack is full                   */
/* pre condition  : Stack is not NULL                           */
/* post conditon  : return ture or fault                        */
bool isFull(const Stack *pStack);

/* operation      : Verify that Stack is empty                  */
/* pre condition  : Stack is not NULL                           */
/* post conditon  : return ture or fault                        */
bool isEmpty(const Stack *pStack);

/* operation      : Push item on top                            */
/* pre condition  : Stack is not NULL                           */
void Push(Stack *pStack, Item item);

/* operation      : Pop item on top                             */
/* pre condition  : Stack is not NULL                           */
Item Pop(const Stack *pStack);

/* operation      : Apply the function to each item             */
/* pre condition  : Stack is not NULL  pfun->func               */
void Traverse(const Stack *pStack, void(*pfun)(Item item));

#endif
