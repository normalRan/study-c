#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n) {
	char *ret_val;
	char *find;	
	ret_val  = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(ret_val, '\n');
		if (find) {
			*find = '\0';
		} else {
			while (getchar() != '\n')	
				continue;
		}
	}
	return ret_val;
}

typedef struct node {
	char name[20];
}Node;

void f (Node node) {
	s_gets(node.name, 20);
}

int main (void) {
	Node node;
	s_gets(node.name, 20);
	f(node);
	printf("%s", node.name);
	
}




