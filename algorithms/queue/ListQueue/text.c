#include <stdio.h>
#include "queue.h"

int main (void) {
	Queue queue;
	InitializeQueue(&queue);	
	Item temp;
	while (scanf("%d", &temp)) {
		EnQueue(&queue, temp);	
	}
	int count = QueueItemCount(&queue); 	
	printf("%d\n", count);
		
	return 0;
}
