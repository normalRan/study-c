#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/* interface fanc */

void InitializeHeap(MaxHeap heap) {
	heap->items = (Item *)malloc((MAXISIZE+1) * sizeof(Item));
	heap->size = 0;
	heap->items[0] = LIMIT;
}


int IsFull(MaxHeap heap) {
	return heap->size == MAXISIZE;
}


int IsEmpty(MaxHeap heap) {
	return heap->size == 0;
}
 
 
int InsertItem(MaxHeap heap, Item item) {
	if (IsFull(heap))
		return 0;
	heap->size++;
	int i = heap->size;
	heap->items[i] = item;		
	for (; heap->items[i/2]<heap->items[i]; i/=2) 
			heap->items[i] = heap->items[i/2];
	heap->items[i] = item;		
	return 1;		
}


int DeleteItem(MaxHeap heap) {
	if (IsEmpty(heap))	
		return 0;
	int i = heap->size;
	for (; i>1; i--)
		heap[i-1] = heap[i];
	heap->items[heap->size] = -1;
	heap->size--;
	return 1;
}

