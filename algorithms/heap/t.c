/* gcc with heap.c */

#include <stdio.h> 
#include <stdlib.h>
#include "heap.h"

int main(void) {
	Heap h;
	MaxHeap heap = &h;
	InitializeHeap(heap);
	Item temp;
	while (scanf("%d\n", &temp))
		InsertItem(heap, temp);
	if (IsFull(heap))	
		puts(" already full !");
	else puts("no full !");
	if (IsEmpty(heap)) 	
		puts("empty !");
	return 0;
}

						/*
						 * *  2019.11.24 00:37
						*/
