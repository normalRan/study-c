#include<stdio.h>
int main() {
	FILE *fp = fopen("1.txt", "w");
	int a = 19;
	if( fp != NULL)
		fprintf(fp, "a = %d\n",a);
	fclose(fp);
}
