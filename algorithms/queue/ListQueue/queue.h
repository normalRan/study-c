#ifndef QUEUE_H_
#define QUEUE_H_
#define MaxSize 5

typedef struct item {
	long arrive;
	int  processtime;
}Item;

typedef struct node {
	Item item;	
	struct node *next;
}Node; 

typedef struct queue {
	Node *front;
	Node *rear;
	int items;
}Queue;

/* interface fanc */

/* operation : Initialize Queue                            */
/* pre condition : pq -> Queue                             */
/* post condition : pq -> NULL                             */
void InitializeQueue(Queue *pq);


/* operation : Check if the queue is full                  */
/* pre condition : pq -> queue that has been initiallized  */
/* post condition : if full return true else return false  */
int QueueIsFull(const Queue *pq);


/* operation : Check if the queue is empty                 */
/* pre condition : pq -> queue that has been initiallized  */
/* post condition : if empty return true else return false */
int QueueIsEmpty(const Queue *pq);


/* operation : Check the num of item                        */
/* pre condition : pq -> != NULL                            */
/* post condition : return Queue -> count                   */
int QueueItemCount(const Queue *pq);


/* operation : Add an Item at the end                       */
/* pre condition : pq -> != NULL                            */
/*                 give item                                */
/* post condition : if !QueueIsEmpty, Add Item at the end   */
/*                  else Add Item at front                  */
/*                  retuen true if succes else return false */
int EnQueue(Queue *pq, Item item);


/* operation : delete Item at end                           */
/* pre condition : pq -> != NULL                            */
/*                        !QueueIsEmpty                     */
/* post condition : if succse return true else return false */
int DeQueue(Queue  *pq);


/* operation : Empty Queue                                  */
/* pre condition : pq -> != NULL                            */
void EmptyTheQueue(Queue *pq);

#endif
