#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#define null -1

/* Implement */

Queue CreatQueue(void) {
	Queue Q = (Queue)malloc(sizeof(struct Qnode));	
	Q -> Front = 0;	
	Q -> Rear  = 0;
	Q -> size  = 0;
	int i;
	for (i=0; i<Capacity; i++)
		Q -> Array[i] = null;
}

void EnQueue(Queue Q, ElementType X) {
	if (IsFull(Q))
		return;
	else {
		if (Q->Rear < Capacity)
			Q -> Array[Q->Rear++] = X;
		else 
			Q -> Array[(Q->Rear=1)-1] = X;
		Q -> size++;
	}
}

void Dequeue(Queue Q) {
	if (IsEmpty(Q))	
		return;
	else {
		if (Q->Front < Capacity)
			Q -> Array[Q->Front++] = null;
		else 
			Q -> Array[(Q->Front=1)-1] = null;
		Q -> size--;
	}
}

int IsEmpty(Queue Q) {
	return Q -> size == 0;	
}

int IsFull(Queue Q) {
	return Q -> size == Capacity;	
}
