#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>
#define size 20

typedef struct everthing {
	char name[size];
	int date;
}Item;

typedef struct node {
	Item item;
	struct node *next;
}Node;

typedef Node *List;


/*  interface  */

/* operation      : Initialize the linked list							             */
/* pre condition  : plist -> list										             */
/* post condition : List initializies NULL								             */

void InitializeList(List *plist); 
	
/* operation      : Verify that list is empty, plist -> InitializeList               */
/* post condition : if list is empty, return ture, else return false                 */

bool ListIsEmpty(const List *plist);

/* operation : verfy that list is full, plist -> InitializeList                      */
/* post condition : if list is empty, return ture, else return false                 */

bool ListIsFull(const List *plist);

/* operation      : Determine the num of list                                        */
/* post condition : return the num of the list                                       */

unsigned int ListItemCount(const List *plist);

/* operation      : Add an item to the end of the list                               */
/* pre condition  : plist -> list, it is an item to be added                         */
/* post condition : if success return ture, else return false                        */

bool AddItem(Item item, List *list);

/* operation      : Apply the function to every item in the list                     */
/*                  plist -> list                                                  
 *                  pfun ->func, func hava an aguement of item and return void       */	
/* post condition : *Apply the function to every item in the list                    */

void Traverse(const List *plist, void(*pfun)(Item item));

/* operation      : free storage                                                     */
/*                  plist -> InitializeList                                          */
/* post condition : free all                                                         */

void EmptyTheList(List *plist);


#endif





