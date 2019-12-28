#include <stdio.h>

char *search(char *cpsource, char ch) {
	char *tmp = cpsource;
	char *Find;
	int cnt;
	int Max = 0;
	while (tmp != '\0') {
		cnt = 0;
		while (*tmp == ch) {
			cnt++;		
			tmp++;
		}
		if (Max < cnt) {
			Max = cnt;	
			Find = tmp-cnt;
		}
		if (*tmp == '\0')
			break;
		else
			tmp++;
	}
	int i;
	for (i=0; i<Max; i++)
		printf("%c", *(Find+i));
	printf("\n");
	return Find;
}


int main() {
/*
	char Array[10];
	int i;
	for (i=0; i<sizeof(Array)/sizeof(Array[0]); i++)
		scanf("%c", Array+i);
	
	printf("%d\n", (int)(search(Array, 'f') - Array));
*/
	char A[] = "aabbcccddddeeeeeffffff";
	search(A, 'e');
	return 0;
}
