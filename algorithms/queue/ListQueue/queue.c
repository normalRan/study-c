#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static int analyQueue(const Queue *pq);

static void CopyToNode(Node *pNode, Item item);

void InitializeQueue(Queue *pq) {
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int QueueIsFull(const Queue *pq) {
	return (pq->items >= MaxSize);
}

int QueueIsEmpty(const Queue *pq) {
	return (pq->items == 0);
}

int QueueItemCount(const Queue *pq) {
	return pq->items;
}

int EnQueue(Queue *pq, Item item) {
	Node *new = (Node *)malloc(sizeof(Node));	
	if (new == NULL)
		return 0;
	CopyToNode(new, item);	
	new->next = NULL;
	int i = analyQueue(pq);
	switch (i) {
		case 1:	
			pq->front = pq->rear = new;	
			pq->items++;
			break;
		case 2:
			puts("Full!");
			break;
		case 3:
			 pq->rear->next = new;
			 pq->rear = new;
			 pq->items++;
			 break;
	}
	return 1;
}

int DeQueue(Queue *pq) {
	if(QueueIsEmpty(pq)) {
		puts("already empty !");	
		return 0;
	}
	if (pq->front == pq->rear)
		free(pq->front);
	else {
		Node *p = pq->front;						
		pq->front = p->next;
		free(p);
	}
		pq->items--;
	return 1;
}

void EmptyTheQueue(Queue *pq) {
	while (1) {
		if (QueueIsEmpty(pq))	
			break;
		else 
			DeQueue(pq);
	}
}


static void CopyToNode(Node *pNode, Item item) {
	pNode->item = item;
}

static int analyQueue(const Queue *pq) {
	if (QueueIsEmpty(pq))	
		return 1;
	if (QueueIsFull(pq))
		return 2;
	return 3;
}
