#include<stdio.h>
//study 枚举 enum 

/*
 *enum里面的成员是一个标识符, 枚举常量
 *第一个成员如果没有赋值会默认为0, 下个成员依次+1递增
 *
 * */

enum Color
{
	pink,red,green,white,black,yellow

};

struct Stutent
{
	int age;
	char name[50];
	enum Color love_color;

};


int main (void)
{
	//创建一个枚举变量
	enum Color color_flag;
	//可以用枚举成员给枚举变量赋值
	color_flag = pink;
	//可以用在结构体中把枚举变量作为一个对象的属性之一, 然后用枚举成员为其赋值 
	
	//创建一个学生对象
	 struct Stutent Alan;
	 Alan.love_color = red;

	 if ( Alan.love_color = red )
		 printf("Alan's favoriate color is red\n !");
	 
	 //枚举适合描述对象的属性

	 
}





