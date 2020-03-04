#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int Value(Item *pItem); 
static void TraverseList(List *plist, void(*p)(Item *pItem, FILE *fp));
static void Print(Item *pItem, FILE *fp);

void Swap(Item *a, Item *b) {
	Item tmp = *a;
	*a = *b;
	*b = tmp;
}

int getDay(char *buf) {
	if (buf[9] != '\n')
		return (buf[8]-'0')*10 + buf[9]-'0';
	else
		return buf[8]-'0';
}	 

int getMonth(char *buf) {
	if (buf[9] != '\n')
		return (buf[8]-'0')*10 + buf[9]- '0';
	else
		return buf[8]-'0';
}

float getTempterature(char *buf) {
	return atof(buf+15);
}

void getWeather(char *p, char *buf) {
	int i;
	int N = strlen(buf+10);
	for(i=0; i<N-1; i++)
		p[i] = buf[10+i];
}

void getPollutionLevel(char *p, char *buf) {
	p[0] = buf[17];
	p[1] = '\0';
}

void getWindScale(char *p, char *buf) {
	p[0] = buf[12];
	p[1] = '\0';
}

int CaluDate(Item *p) {
	return p->Day + (p->Month)*30;
}

/*
void Buddle_Sort(int *A, int N) {
	int i, j, flag;
	for(i=0; i<N-1; i++) {
		flag = 0;
		for(j=0; j<N-1-i; j++)
			if (A[j] > A[j+1]) {
				Swap(&A[j], &A[j+1]);	
				flag = 1;
			}
		if (flag == 0)
			break;
	}
}
*/

int Count(void) {
	int count = 0;
	char buf[1024];
	FILE *fp = fopen("1.txt", "r");
	while(1) {
		memset(buf, 0, sizeof(buf));		
		fgets(buf, sizeof(buf), fp);
		if (buf[0] == '\n')
			count++;
		if (feof(fp))
			break;
	}
	fclose(fp);
	return count/2;
}

void Rerank0fDate(Item *p, int N) {
	int i, j, flag; 	
	for(i=0; i<N-1; i++) {
		flag = 0;	
		for(j=0; j<N-1-i; j++)
			if(CaluDate(p+j) > CaluDate(p+j+1)) {
				Swap(&p[j], &p[j+1]);	
				flag = 1;
			}
		if (flag = 0)
			break;
	}
	FILE * fp = fopen("1.txt", "w");	
	for(i=0; i<N; i++)
		Print(p+i, fp);
	fclose(fp);
}

void Rerank0fTempterature(Item *p, int N) {
	int i, j, flag; 	
	for(i=0; i<N-1; i++) {
		flag = 0;	
		for(j=0; j<N-1-i; j++)
			if(p[j].Tempterature > p[j+1].Tempterature) {
				Swap(&p[j], &p[j+1]);	
				flag = 1;
			}
		if (flag = 0)
			break;
	}
	FILE * fp = fopen("1.txt", "w");	
	for(i=0; i<N; i++)
		Print(p+i, fp);
	fclose(fp);
}

void RerankOfPollutionLevel(Item *p ,int N) {
	int i, j, flag; 	
	for(i=0; i<N-1; i++) {
		flag = 0;	
		for(j=0; j<N-1-i; j++)
			if(p[j].PollutionLevel[0] >  p[j+1].PollutionLevel[0]) {
				Swap(&p[j], &p[j+1]);	
				flag = 1;
			}
		if (flag = 0)
			break;
	}
	FILE * fp = fopen("1.txt", "w");	
	for(i=0; i<N; i++)
		Print(p+i, fp);
	fclose(fp);
}

void RerankOfWindScale(Item *p ,int N) {
	int i, j, flag; 	
	for(i=0; i<N-1; i++) {
		flag = 0;	
		for(j=0; j<N-1-i; j++)
			if(p[j].WindScale[0] >  p[j+1].WindScale[0]) {
				Swap(&p[j], &p[j+1]);	
				flag = 1;
			}
		if (flag = 0)
			break;
	}
	FILE * fp = fopen("1.txt", "w");	
	for(i=0; i<N; i++)
		Print(p+i, fp);
	fclose(fp);
}

void Rerank(void) {
	int N = Count();
	Item tmp[N];
	char buf[1024];
	int i;	
	for(i=0; i<N; i++) {
		tmp[i].Day = 0;
		tmp[i].Month = 0;
		tmp[i].Tempterature = 0;
		memset(tmp[i].Weather, 0, sizeof(tmp[i].Weather));
		memset(tmp[i].PollutionLevel, 0, sizeof(tmp[i].PollutionLevel));
		memset(tmp[i].WindScale, 0, sizeof(tmp[i].WindScale));
	}
	i = 0;
	FILE *fp = fopen("1.txt", "r");
	while(1) {
		memset(buf, 0, sizeof(buf));	
		fgets(buf, sizeof(buf), fp);
		if (buf[0] == '\n')
			continue;
		if (buf[0] == 'D')
			tmp[i].Day = getDay(buf);
		if (buf[0] == 'M')
			tmp[i].Month = getMonth(buf);
		if (buf[0] == 'T')
			tmp[i].Tempterature = getTempterature(buf);
		if (buf[2] == 'a')
			getWeather((tmp[i].Weather), buf);
		if (buf[0] == 'P')
			getPollutionLevel((tmp[i].PollutionLevel), buf);
		if (buf[1] == 'i')
			getWindScale((tmp[i++].WindScale), buf);
		if (feof(fp))
			break;
	}
	int choice;
	puts("choice\n");
	puts("1 : date");
	puts("2 : Tempterature");
	puts("3 : PollutionLevel");
	puts("4 : WindScale");
	scanf("%d", &choice);
	switch(choice) {
		case 1 : Rerank0fDate(tmp, N);	
			break;
		case 2 : Rerank0fTempterature(tmp, N);
			break;
		case 3:  RerankOfPollutionLevel(tmp, N);
			break;
		case 4 : RerankOfWindScale(tmp, N); 
			break;	
	}
	for(i=0; i<N; i++)
		printf("%d\t%d\t%f\t%s\t%s\n", tmp[i].Day, tmp[i].Month,
						tmp[i].Tempterature, tmp[i].PollutionLevel, tmp[i].WindScale);
						
	fclose(fp);
}

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








