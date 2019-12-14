#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Queue.h"

/* gcc with Queue.c */

void showQ(Queue Q) {
	int i;
	for (i=0; i<Capacity; i++)
		printf("%3d", Q->Array[i]);
	printf("\n");
}


int main() {
	Queue Q = CreatQueue();
	EnQueue(Q, 3);
	EnQueue(Q, 3);
	EnQueue(Q, 3);
	Dequeue(Q);
	Dequeue(Q);
	Dequeue(Q);
	srand(time(0));
	puts("EnQueue");
	while (!IsFull(Q)) {
		EnQueue(Q, rand()%10);			
		showQ(Q);
	}
	puts("DeQueue");
	while (!IsEmpty(Q)) {
		Dequeue(Q);
		showQ(Q);
	}
}
