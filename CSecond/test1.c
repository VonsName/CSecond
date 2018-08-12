#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//收尾同时遍历  双端  查找除去空白都多少个字符
int main()
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