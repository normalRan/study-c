#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void showmovies(Item item);

char *s_gets(char *st, int n) {
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(ret_val, '\n');	
		if (find) 
			*find = '\0';
		else {
			while (getchar() != '\n')	
				continue;
		}
	}
	return ret_val;
}

void showmovies(Item item) {
	printf("movie : %s\n", item.name);
	printf("rate : %d\n", item.date);
}

int main(void) {
	List movies = NULL;
	Item temp;
	
	InitializeList(&movies);
	if (ListIsFull(&movies)) {
		fprintf (stderr, "no memory availabel ! Bye ~\n");	
	}
	puts("please enter a movies ~");

	while (s_gets(temp.name, size) != NULL && temp.name[0] != '\0') {
		puts("please give your rating.");
		scanf("%d", &temp.date);
		while (getchar() != '\n')
			continue;
		if (AddItem(temp, &movies) == false) {
			fprintf(stderr,"Problem allocating memory.\n");	
			break;
		}		
		if (ListIsFull(&movies)) {
			puts("List is full already.\n");	
			break;
		}
			puts("please enter your moives(empty line to stop).");
	}
	int i = ListItemCount(&movies);	
	printf("%d\n", i);
	if (!ListIsEmpty(&movies))	
		Traverse(&movies, (*showmovies));
	else 
		printf("no movies now.\n");

	EmptyTheList(&movies);
	printf("Bye ~\n");
	return 0;
}




