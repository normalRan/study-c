#ifndef LIST_H_
#define LIST_H_
#define MaxOfMonth 12
#define MaxOfDay 31

struct item {
	int Day;
	int Month;
	float Tempterature;
	char Weather[10];
	char PollutionLevel[2]; /* A ~ F */
	char WindScale[2];      /* A ~ F */
};
typedef struct item Item;

struct node {
	Item item;
	struct node *next;
};
typedef struct node Node;

struct list {
	int count;	
	Node *node;
};
typedef struct list *List;

/* interface */

void InitializeList(List *plist);

int IsEmpty(List *plist);

int IsFull(List *plist);

int AddItem(List *plist);

int DeleteItem(List *plist);

void Traverse(List *plist);

#endif
