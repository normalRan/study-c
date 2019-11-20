#include <stdio.h>
#include "tree.h"

// Please gcc with tree.c !

void show_item(Item item) {
	printf("%d\t", item);
}

int main (void) {
	Tree tree;	
	InitializeTree(&tree);
	Item temp;
	
	// Add Node
	puts("Please enter item");
	while (scanf("%d", &temp)) {
		AddItem(&temp, &tree);	
	}
	printf("%d\n", TreeItemCount(&tree));
	if (TreeIsFull(&tree)) puts("full !");
	
	// test Traverse
	Traverse(&tree, (*show_item));				
	printf("\n");
	
	// test InTree
	Item item = 9;
	if (InTree(&item, &tree))	
		puts("find !");
	
	// test DeleteTree
	DeleteTree(&tree);
	if (TreeIsEmpty(&tree)) puts("now tree is empty !");

	return 0;
														
	// Frist time finsh tree ADT by myself ~
														/* 
													     **  2019.11.20 01:34 
													    */		
}
