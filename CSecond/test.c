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


//�β��е�����ʵ���ϲ�������,��һ����ָͨ�����
//int a[]  int* a���������ǵ���int*(һ����ͨ��intָ��)����
//�β��е�������һ��ָ�����,��������µ��������һ����ʵ������ 
void print_arr(int a[])
{
	//1.��64λ��������,sizeof(a)�ĳ�����8���ֽ�,���൱����һ����ͨ��ָ�����
	//2.��32λ��������,sizeof(a)�ĳ�����4���ֽ�,���൱����һ����ͨ��ָ�����
	//3.sizeof(a[0]) ��Ϊ��һ��int�͵ı���,��32��64λ�ı������¶���4λ
	//4.���������ڲ�ͬ�ı���������������ͬ
	int len = sizeof(a) / sizeof(a[0]);//len-> 32λ��Ϊ4/4=1  64λ��Ϊ8/4=2
	printf("sizeof(a)=%d\n", sizeof(a));
	printf("sizeof(a[0])=%d\n", sizeof(a[0]));
	for (int i=0;i<len;i++)
	{
		printf("%d ", a[i]);
	}
}

//����������������
int main()
{
	int a[] = { 1,2,3,4,5 };
	//print_arr(a);
	int n = sizeof(a) / sizeof(*a);
	print_arr2(a,n);
	return 0;
}

//ָ������
int main8()
{
	int a[] = { 1,2,3 };
	int len = sizeof(a) / sizeof(*a);
	//ָ������ ÿ��Ԫ��װ����һ��int*ָ��
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

//�ҳ��ڶ������
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

//ָ��Ӽ���
int main5()
{
	int a[] = { 1,2,3,4,5 };
	//ָ��ָ���׵�ַ
	int* p = a;
	p = &a[0];
	int n = sizeof(a) / sizeof(*a);//sizeof(a) / sizeof(a[0]);
	for (int i=0;i<n;i++)
	{
		printf("*p=%d  ", *p);
		p++;
	}
	printf("\n");


	//ָ��ָ��β��ַ
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

	const int* p2 = &a;//const���ε���ָ��ָ����ڴ�,���ܱ��ı�
	//*p2 = 110; error
	p2 = NULL;//ok ָ�뱾���ǿ��Ա��ı��

	int* const p3= &a;//const���ε���ָ��,ָ�뱾��ĵ�ַ���ɱ�  ����ָ��
	*p3 = 11;//ok
	//p3 = NULL; error p3 ָ�뱾���ɱ�

	const int* const p4 = &a;//const���ε���ָ����������Լ�ָ��ָ����ڴ治�ܱ��ı�

	//  *p4 = 100; //error   ָ��ָ����ڴ��ֵ���ܱ��ı�
	//p4 = NULL; //error  //ָ�뱾��Ҳ���ܱ��ı�

	return 0;
}


int main2()
{
	//void a; error
	//void* ָ�� ����ָ���κ���������,
				//����ʹ��ָ��ָ����ڴ��ַ��ʱ��,Ҫת��Ϊ�������������ָ������

	printf("%d\n", sizeof(void *));

	void* a = NULL;
	int b = 10;
	a = &b;
	//*a = 220; error
	*(int*)a = 220;

	printf("%d\n", b);
	printf("%d\n", *(int*)a);

	//ָ��������ӷ�,���Ĳ�����ָ��ָ����������;���,int����Ϊ4�ֽ�,char Ϊ1�ֽ�...
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

	//Ұָ��:ָ��ָ����һ���Ƿ��Ļ��߲����ڵ��ڴ��ַ  ����ָ������ȳ�ʼ��

	//int *x=(int *)0x1235;//Ұָ�� �����ڵ�һ���ڴ��ַ
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
	////32λ��������,�������͵�ָ�붼����32λ��С(4�ֽ� )�洢��ַ
	////64λ��������,�������͵�ָ�붼����64λ��С(8�ֽ� )�洢��ַ
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