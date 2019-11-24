#ifndef HEAP_H_
#define HEAP_H_

#define MAXISIZE 5
#define LIMIT 100

/* MaxHeap */

typedef int Item;

typedef struct heap {
	Item *items;		
	int size;			
}Heap;

typedef Heap *MaxHeap;

/* interface */

/* operation : Creat Heap and Initialize it                 */
/* precondition : put a MaxHeap                             */
/* pre conditon : heap->items  heap->size = 0               */
void InitializeHeap(MaxHeap heap);


/* operation : judge weather heap is full                   */
/* precondition : heap has been already Initialized         */
/* pre conditon : if full return 1 else return 0            */
int IsFull(MaxHeap heap);


/* operation : judge weather heap is empty                  */
/* precondition : heap has been already Initialized         */
/* pre conditon : if empty return 1 else return 0           */
int IsEmpty(MaxHeap heap);


/* operation : Add item for heap                            */
/* precondition : heap has been already Initialized         */
/* pre conditon : heap->size++                              */
int InsertItem(MaxHeap heap, Item item);

/* operation : Delete item for heap                         */
/* precondition : heap has been already Initialized         */
/* pre conditon : heap->size--                              */
int DeleteItem(MaxHeap heap);

#endif
