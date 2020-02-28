#include<stdio.h>
#include"list.h"

int main(void) {
//	printf("hello world!\n");
	List movies = NULL;	
	List *plist = &movies;
	InitializeList(plist);
//	AddItem(plist, item);
	while(AddItem(plist));
	Traverse(plist);
}
