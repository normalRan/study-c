#include <stdio.h>

int Pow(int n, int m) {
	if (m == 0)
		return 1;
	if (m == 1)
		return n;
	if (m & 1)
		return n*Pow(n*n, m/2);
	else
		return Pow(n*n, m/2);
}

int Calu(int Front, int rear, char sign) {

	int answer;
	switch (sign) {
		case '+' : 
			answer = Front + rear;
			break;
		case '-' :
			answer = Front - rear;
			break;
		case '*' :
			answer = Front * rear;
			break;
		case '/' :
			answer = Front / rear;
			break;
	}
	return answer;
}

int FindNum(char *tmp) {
	int digit = 0;
	int num = 0;
	while (*tmp-'0'>=0 && *tmp-'0'<=9)
		digit++, tmp++;	
	int i;
	for (i=0; i<digit; i++) 	
		num += (*(--tmp)-'0')*Pow(10, i);
/*	printf("num = %d\n", num); */
	return num;
}

int Get(int answer, char *p) {
	if (*p == '\0')
		return answer;
	char *sign = p;
	p++;
	int Front = answer;
	int Rear  = FindNum(p);
	answer = Calu(Front, Rear, *sign);
	while (*p-'0'>=0 && *p-'0'<=9)
		p++;
	return Get(answer, p);
}

int getAnswer(char *p) {
	int begin = FindNum(p);
	while (*p-'0'>=0 && *p-'0'<=9)
		p++;
	return Get(begin, p);
}


int main() {
	char num[] = "10-3*4+88-12";
	int answer = getAnswer(num);
	printf("answer = %d\n", answer); 
	//printf("%d\n",Calu(10, 5, '/')
	//printf("%d\n", convert(c));
	return 0;
}
