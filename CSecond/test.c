#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//
print_arr2(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}


//形参中的数组实际上不是数组,是一个普通指针变量
//int a[]  int* a编译器都是当作int*(一个普通的int指针)处理
//形参中的数组是一个指针变量,其他情况下的数组就是一个真实的数组 
void print_arr(int a[])
{
	//1.在64位编译器下,sizeof(a)的长度是8个字节,它相当于是一个普通的指针变量
	//2.在32位编译器下,sizeof(a)的长度是4个字节,它相当于是一个普通的指针变量
	//3.sizeof(a[0]) 因为是一个int型的变量,在32和64位的编译器下都是4位
	//4.所以这里在不同的编译器下输出结果不同
	int len = sizeof(a) / sizeof(a[0]);//len-> 32位下为4/4=1  64位下为8/4=2
	printf("sizeof(a)=%d\n", sizeof(a));
	printf("sizeof(a[0])=%d\n", sizeof(a[0]));
	for (int i=0;i<len;i++)
	{
		printf("%d ", a[i]);
	}
}

//数组名做函数参数
int main()
{
	int a[] = { 1,2,3,4,5 };
	//print_arr(a);
	int n = sizeof(a) / sizeof(*a);
	print_arr2(a,n);
	return 0;
}

//指针数组
int main8()
{
	int a[] = { 1,2,3 };
	int len = sizeof(a) / sizeof(*a);
	//指针数组 每个元素装的是一个int*指针
	int* p[3];
	
	for (int i=0;i<len;i++)
	{
		//*(p + i) = a + i;
		//*(p + i) = &a[i];
		p[i] = &a[i];
	}
	int len1 = sizeof(p) / sizeof(*p);
	for (int i=0;i<len1;i++)
	{
		//printf("%d  ", *(*(p + i)));
		printf("%d ", *p[i]);
	}
	return 0;
}

int main7()
{
	char src[] = "abc";
	char des[sizeof(src) / sizeof(*src)] = {0};
	char* p = des;
	char* p1 = src;
	int len = sizeof(src) / sizeof(char);
	printf("%d\n", len);
	for (int i=0; i<len-1;i++)
	{
		//*(des+i) = *(src+i);
		*p = *p1;
		p1++;
		p ++;
	}
	printf("%s\n", des);
	return 0;
}

//找出第二大的数
int main6()
{
	int a[] = {4,100,45,11,68,34,78,90};
	int* p = a;
	int max = *a;
	int len = sizeof(a) / sizeof(*a);
	for (int i = 0;i < len; i++)
	{
		if (*p > max) {
			max = *p;
		}
		p++;
	}
	printf("max=%d", max);
	printf("\n");
	int maxm=*a;
	//p = &a[0];
	for (int i = 0; i < len; i++)
	{
		if (*p > maxm &&*p!=max) {
			maxm = *p;
		}
		p--;
	}
	printf("maxm=%d", maxm);

	return 0;
}

//指针加减法
int main5()
{
	int a[] = { 1,2,3,4,5 };
	//指针指向首地址
	int* p = a;
	p = &a[0];
	int n = sizeof(a) / sizeof(*a);//sizeof(a) / sizeof(a[0]);
	for (int i=0;i<n;i++)
	{
		printf("*p=%d  ", *p);
		p++;
	}
	printf("\n");


	//指针指向尾地址
	int* q = a + (n-1);
	q = &a[n - 1];
	/*for (int i=n-1;i>=0;i--)
	{
		printf("*q=%d  ", *q);
		q--;
	}*/
	printf("\n");
	for (int i=0;i<n;i++)
	{
		printf("*q=%d ", *q);
		q--;
	}
	return 0;
}

int main4()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = a;
	int*p1 = &a[0];
	printf("p=%p", p);
	printf("p1=%p", p1);
	printf("\n");
	for (int i=0;i<10;i++)
	{
		printf("%d\n", *(p + i));
		//printf("%d\n", p[i]);
	}
	return 0;
}


int main3()
{
	int a = 10;
	int* p = &a;
	*p = 110;
	
	//p = NULL;
	//*p = 110;error
	printf("%d\n", *p);
	printf("%d\n", p);
	printf("%p\n", p);

	const int* p2 = &a;//const修饰的是指针指向的内存,不能被改变
	//*p2 = 110; error
	p2 = NULL;//ok 指针本身是可以被改变的

	int* const p3= &a;//const修饰的是指针,指针本身的地址不可变  常量指针
	*p3 = 11;//ok
	//p3 = NULL; error p3 指针本身不可变

	const int* const p4 = &a;//const修饰的是指针变量本身以及指针指向的内存不能被改变

	//  *p4 = 100; //error   指针指向的内存的值不能被改变
	//p4 = NULL; //error  //指针本身也不能被改变

	return 0;
}


int main2()
{
	//void a; error
	//void* 指针 可以指向任何数据类型,
				//但是使用指针指向的内存地址的时候,要转化为它本身所代表的指针类型

	printf("%d\n", sizeof(void *));

	void* a = NULL;
	int b = 10;
	a = &b;
	//*a = 220; error
	*(int*)a = 220;

	printf("%d\n", b);
	printf("%d\n", *(int*)a);

	//指针可以做加法,它的步长由指针指向的数据类型决定,int步长为4字节,char 为1字节...
	return 0;
}

int main1()
{
	/*int a = 10;
	int* p;

	p = &a;
	printf("p=%p\n", p);
	printf("a=%p\n", &a);
	printf("&p=%p\n", &p);

	int b = *p;
	*p = 110;
	printf("%d  %d\n", *p, b);
	printf("%d  %d\n", a, b);*/

	//野指针:指针指向了一个非法的或者不存在的内存地址  定义指针必须先初始化

	//int *x=(int *)0x1235;//野指针 不存在的一块内存地址
	//*x = 111;
	//printf("%d\n",*x );

	/*int a = 10;
	int *x1;
	x1 = 0x1234;
	printf("%p\n", x1);
	*x1 = &a;*/
	//int a = sizeof(int *);
	//int b = sizeof(char *);
	//double **p;
	//int c = sizeof(p);
	//int d = sizeof(long **);
	////32位编译器下,所有类型的指针都是用32位大小(4字节 )存储地址
	////64位编译器下,所有类型的指针都是用64位大小(8字节 )存储地址
	//printf("%d %d %d %d", a, b, c, d);
	int a = 10;
	int* p = &a;
	*p = 110;
	printf("*p=%d\n", *(p+0));
	printf("a=%d\n", a);
	printf("p[0]=%d\n", p[0]);
	p[0] = 220;
	printf("*p=%d\n", *(p + 0));
	printf("a=%d\n", a);
	printf("p[0]=%d\n", p[0]);

	return 0;
}