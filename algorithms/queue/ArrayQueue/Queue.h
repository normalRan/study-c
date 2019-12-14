#ifndef QUEUE_H_
#define Capacity 10

/* Array Queue */

typedef int ElementType;

typedef struct Qnode *PtrToQnode;
typedef PtrToQnode Queue;
struct Qnode {
	int Front;
	int Rear;
	int size;
	ElementType Array[Capacity];	
};

/* interface */

Queue CreatQueue(void); 

void EnQueue(Queue Q, ElementType X);

void DeQueue(Queue Q);

int IsEmpty(Queue Q);

int IsFull(Queue Q);

#endif
