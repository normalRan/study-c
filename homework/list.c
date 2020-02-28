#include"list.h"
#include<stdio.h>
#include<stdlib.h>

static int Value(Item *pItem); 
static void TraverseList(List *plist, void(*p)(Item *pItem, FILE *fp));
static void Print(Item *pItem, FILE *fp);

void InitializeList(List *plist) {
	*plist = (List)malloc(sizeof(struct list));
	(*plist)->count = 0;
	(*plist)->node = NULL;
}

int IsEmpty(List *plist) {
	if ((*plist)->count == 0)
		return 1;
	else
		return 0;
}

int IsFull(List *plist) {
	if ((*plist)->count == MaxOfDay)
		return 1;
	else
		return 0;
}

int AddItem(List *plist) {
	if (IsFull(plist))
		return 0;
	List list = *plist;
	Node *new = (Node *)malloc(sizeof(struct node));
	if (!Value( &(new->item) ))
		return 0; 
	new->next = NULL;
	if (list->node == NULL) 
		list->node = new;
	else {
		Node *scan = list->node;	
		while(scan->next != NULL)
			scan = scan->next;
		scan->next = new;
	}
	list->count++;
	return 1;
}

int DeleteItem(List *plist) {
	if (IsEmpty(plist))
		return 0;	
	List list = *plist;
	list->count--;
	Node *Pre  = list->node;
	Node *scan = list->node;
	if (Pre->next == NULL)
		list->node = NULL;
	else {
		scan = Pre->next;	
		while (scan->next != NULL) {
			Pre->next = scan;	
			scan = scan->next;
		}
		Pre->next = NULL;
	}
	free(scan);
	return 1;
}

void Traverse(List *plist) {
	TraverseList(plist, (*Print));	
}

static int Value(Item *pItem) {
	printf("\nbegin\n");
	printf("please enter the Day(1~31, (ENTET 0 QUIZ)\t");
	scanf("%d", &(pItem->Day));		
	if (pItem->Day == 0)
		return 0;
	printf("please enter the Month(1~12):\t");
	scanf("%d", &(pItem->Month));		
	printf("please enter the Tempterature(*C):\t");
	scanf("%f", &(pItem->Tempterature));		
	printf("please enter the Weather:\t");
	scanf("%s", pItem->Weather);		
	printf("please enter the PollutionLevel(A~F):\t");
	scanf("%s", pItem->PollutionLevel);		
	printf("please enter the WindScale(A~F):\t");
	scanf("%s", pItem->WindScale);		
	return 1;
};


static void TraverseList(List *plist, void(*p)(Item *pItem, FILE *fp)) {
	FILE *fp = fopen("1.text", "w");
	List list = *plist;
	Node *scan = list->node;
	while(scan!= NULL) 
		(*p)(&(scan->item), fp),
		scan = scan->next;
	fclose(fp);
}

static void Print(Item *pItem, FILE *fp) {
	fprintf(fp,"\n");
	fprintf(fp, "Day   : %d\n", pItem->Day);
	fprintf(fp, "Month : %d\n", pItem->Month);
	fprintf(fp, "Tempterature : %.1f\n", pItem->Tempterature);
	fprintf(fp, "Weather : %s\n", pItem->Weather);
	fprintf(fp, "PollutionLevel : %s\n", pItem->PollutionLevel);
	fprintf(fp, "WindScale : %s\n", pItem->WindScale);
	fprintf(fp, "\n");
}




















