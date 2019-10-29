#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//结构体套数组


struct Student 
{
	int age;
	char name[50];
	int score;		
}; //注意分号

struct text 
{
	char *name;
};


int main (void)
{
// ---------------------
	struct text a;
	a.name="pcouldchage";
	
	char *pl;
	printf("%p\n", pl);
	pl="keyi"; //这样是可以的,实际上指针改变了一次
	printf("%p\n", pl);
	printf("-------------------------\n");
// 若用指针来保存字符串显然可以因为指针是可变的
	

//-----------------------结构体指针指向栈区空间----------------------
	struct Student *p;
	struct Student temp;
	p=&temp;
//	error----
//	:在声明结构体时其中的字符数组的内存地址已经确定不可更改 (数组名时常量)
// 	="" 企图将文字常量区的字符串的地址又交给已经确认地址的数组
//	temp.name="ewqewqeewq";
//	p->name="ran";
//	同理
// 	char a[10];
//	a="address";
//	-------rorre;

//如何把字符串地址给字符数组?
//1).
	char ab[10]="dasdsada";
	struct Student temp2 = { 1, "22qs", 88 };
//在初始化的时候直接赋值

//2).
//strcpy
	strcpy(temp.name,"ssad");
	strcpy(p->name,"ssad");
// p=&temp p->name = temp.name = (&temp)->name
//将""拷贝到数组的地址不改变数组的地址	
	


//---------------- 指针指向堆区-------------------------
//	malloc()

	char*p1;
	printf("%p\n", p1);//这里输出为null
	p1 = (char*)malloc( ( strlen("mike")+1 ) * sizeof(char) ); 
	printf("%p\n", p1);
	if(p!=NULL)
	free(p);
//	还掉空间在继续调用
	printf("-------------------------\n");
	strcpy(p1,"mike");
	printf("%p\n", p1);
	p1="ran";//指针改变,这里还有一个问题: 改变后再也找不到malloc()的指针因此在改变指针前应将堆区空间free()
	printf("%p\n", p1);
	
// 若用指针来保存字符串显然可以因为指针是可变的
	
//	strlen() : 返回给定string的长度不包括\0;
//	因此要+1
	








	return 0;
}



