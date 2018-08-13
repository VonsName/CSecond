#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>



void foo()
{
	extern int x; //extern声明不分配内存空间
	printf("%d", x);// 如果在定义全局变量前使用,必须要先声明 
}

//普通的全局变量
//不显示初始化的时候默认初始化为0
//整个程序运行完毕才会释放
int x = 10;


int main12()
{
	foo();
	return 0;
}

void fun01()
{
	//静态变量如果没有初始化默认为0,普通的变量没有初始化的时候,默认为随机数
	//静态变量初始化只会执行一次
	//static 在编译期间就已经分配了内存,而普通的局部变量只有当执行到了定义的地方才会分配内存
	static int i = 0;
	int a = 10;
	//static int  j = a; error //static只能用常量初始化
}
int main11()
{
	int a = 10;
	if (1) {
		int a = 11;
		printf("%d\n", a);
	}
	printf("%d\n", a);
	return 0;
}

//数组名是常量
int addSum(char *buf)
{
	char* p= strtok(buf, ",");
	int i = 0;
	int sum = 0;
	while (p != NULL)
	{
		printf("%s\n", p);
		int n = atoi(p);
		sum += n;
		p = strtok(NULL, ",");
	}
	printf("%d\n", sum);
	
	return 0;
}

int main10()
{
	char buf[] = { "23,13,5,10" };
	addSum(buf);
	return 0;
}

//收尾同时遍历  双端  查找除去空白都多少个字符
int main09()
{
	char *p = "     abcdevf      ";
	char* start = p;
	char* end = p + strlen(p) - 1;
	while (*start==' '&&*start!='\0')
	{
		start++;
	}

	while (*end == ' '&&end != p)
	{
		end--;
	}
	printf("%d", (end - start) + 1);
	return 0;
}

//查找字符串
int main08()
{
	//p保存的是字符串常量的首地址
	char *p = "123abcd123abcd123abcd123abcd123abcd123abcd131123abcd";
	int len = sizeof(p) / sizeof(*p);
	//查找匹配字符串,找到了返回匹配字符串的地址,没有找到返回NULL
	char* tmp = strstr(p, "abcd");
	int sum = 0;
	do 
	{
		if (tmp != NULL) {
			sum++;
		}
		else
		{
			printf("%s", "查找结束了,没有该字符串");
			break;
		}
		//地址向后移动
		tmp = strstr(tmp + strlen("abcd"), "abcd");
	} while (tmp!=NULL);
	printf("%d", sum);
	return 0;
}

int main07(int argc,char* argv[])
{
	int i = 0;
	for (i;i<argc;i++)
	{
		printf("argv=%s ,", *(argv + i));//打印主函数参数
	}
	return 0;
}

int main06()
{
	
	char* p = "hello";//保存的是hello字符串常量的首地址 它指向的内存不能改变
	//两个意义不一样
	char buf[] = "hello";//编译器是把每个字符保存在buf数组中 

	char* p1 = buf;
	*p1 = 'c';//数组中的元素可以改变  该数组和字符串常量"hello"没有直接的关系
	printf("%s\n", buf);

	char* p2[] = { "hello","world","nihao" };
	printf("sizeof(*p2)=%d\n", sizeof(*p2));
	printf("sizeof(p2)=%d\n", sizeof(p2));
	printf("*p2=%s\n", *p2);//hello


	printf("p2=%d\n", *p2);//和下面的输出相同 输出的hello的首地址
	printf("hello=%d", "hello");
	return 0;
}

int main05()
{
	//字符串常量("hello world")都是一个地址(首元素地址)  字符串常量存放在data区 "hello world"
	printf("%s\n", "hello world");
	printf("%s\n", "hello world" + 1);//首地址+1 ello world
	printf("%s\n", "hello world" + 2);//首地址+2 llo world
	printf("%c\n", *("hello world"));//打印首元素 h
	printf("%p\n", "hello world");
	printf("%p\n", "hello world"+1);
	printf("%p\n", "hello world" + 2);

	char* p1 = "hello world";
	char* p2 = "hello world";

	printf("\n");
	printf("%p\n", p1);//这里两个输出的都是一个地址
	printf("%p\n", p2);
	printf("\n");
	printf("*p1=%c\n", *p1);
	//*p1 = 'b'; error //Segmentation fault (core dumped) 字符串常量为只读,不能被改变

	//strcpy(p1, "nihaoa"); //error Segmentation fault (core dumped) 
							//字符串常量为只读,不能被改变 不同的字符串首地址不一样
	return 0;
}

int main04()
{
	char buf[100] = {0};
	char src[] = "hello world";
	char* p = buf;
	int len = sizeof(src) / sizeof(*src);
	for (int i=0;i<len;i++)
	{
		*(p + i) = *(src + i);
	}
	printf("!!p=%s  buf=%s", p, buf);
	return 0;
}

//字符串拷贝
int main03()
{
	//char* p;//没有初始化
	//strcpy(p, "hello mayyr");
	//printf("%s", p);//Segmentation fault (core dumped) 拷贝的时候是把内容
								//拷贝给p所指向的内存,但是p这里是一个野指针
	char buf[100];
	char* p = buf;
	strcpy(p, "hello mike");//strcpy 
	printf("p=%s  buf=%s", p,buf);
	return 0;
}


//字符串打印是从首地址开始打印直到遇到\0或者0
//字符串指针
int main02()
{
	char str[] = "hello word";
	printf("%s\n", str);//%s 操作的是字符串指向的内存空间
	printf("%p\n", str);//%p操作的是变量本身
	//*str 代表的是数组第一个元素,是char类型
	//printf("%s\n", *str);  这里会出现段错误Segmentation fault (core dumped)
	return 0;
}

//在linux下运行会出现段错误,因为返回了局部变量的地址
//并且在Linux下面fun()函数不会返回a的地址
//Segmentation fault (core dumped)
//当fun()函数结束的时候,a所在的内存空间就被释放了,这个时候再继续操作这块
//内存地址就会出现段错误  (野指针操作)
int* fun()
{
	int a;
	return &a;
}

int main01()
{
	/*int* p = fun();
	*p = 100;
	printf("*p=%d", *p);*/

	int* p = NULL;
	p = fun();
	*p = 1;
	printf("*p=%d", *p);
	//system("pause");
	return 0;
}