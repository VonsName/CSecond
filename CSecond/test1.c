#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��βͬʱ����  ˫��  ���ҳ�ȥ�հ׶����ٸ��ַ�
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

//�����ַ���
int main08()
{
	//p��������ַ����������׵�ַ
	char *p = "123abcd123abcd123abcd123abcd123abcd123abcd131123abcd";
	int len = sizeof(p) / sizeof(*p);
	//����ƥ���ַ���,�ҵ��˷���ƥ���ַ����ĵ�ַ,û���ҵ�����NULL
	char* tmp = strstr(p, "abcd");
	int sum = 0;
	do 
	{
		if (tmp != NULL) {
			sum++;
		}
		else
		{
			printf("%s", "���ҽ�����,û�и��ַ���");
			break;
		}
		//��ַ����ƶ�
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
		printf("argv=%s ,", *(argv + i));//��ӡ����������
	}
	return 0;
}

int main06()
{
	
	char* p = "hello";//�������hello�ַ����������׵�ַ ��ָ����ڴ治�ܸı�
	//�������岻һ��
	char buf[] = "hello";//�������ǰ�ÿ���ַ�������buf������ 

	char* p1 = buf;
	*p1 = 'c';//�����е�Ԫ�ؿ��Ըı�  ��������ַ�������"hello"û��ֱ�ӵĹ�ϵ
	printf("%s\n", buf);

	char* p2[] = { "hello","world","nihao" };
	printf("sizeof(*p2)=%d\n", sizeof(*p2));
	printf("sizeof(p2)=%d\n", sizeof(p2));
	printf("*p2=%s\n", *p2);//hello


	printf("p2=%d\n", *p2);//������������ͬ �����hello���׵�ַ
	printf("hello=%d", "hello");
	return 0;
}

int main05()
{
	//�ַ�������("hello world")����һ����ַ(��Ԫ�ص�ַ)  �ַ������������data�� "hello world"
	printf("%s\n", "hello world");
	printf("%s\n", "hello world" + 1);//�׵�ַ+1 ello world
	printf("%s\n", "hello world" + 2);//�׵�ַ+2 llo world
	printf("%c\n", *("hello world"));//��ӡ��Ԫ�� h
	printf("%p\n", "hello world");
	printf("%p\n", "hello world"+1);
	printf("%p\n", "hello world" + 2);

	char* p1 = "hello world";
	char* p2 = "hello world";

	printf("\n");
	printf("%p\n", p1);//������������Ķ���һ����ַ
	printf("%p\n", p2);
	printf("\n");
	printf("*p1=%c\n", *p1);
	//*p1 = 'b'; error //Segmentation fault (core dumped) �ַ�������Ϊֻ��,���ܱ��ı�

	//strcpy(p1, "nihaoa"); //error Segmentation fault (core dumped) 
							//�ַ�������Ϊֻ��,���ܱ��ı� ��ͬ���ַ����׵�ַ��һ��
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

//�ַ�������
int main03()
{
	//char* p;//û�г�ʼ��
	//strcpy(p, "hello mayyr");
	//printf("%s", p);//Segmentation fault (core dumped) ������ʱ���ǰ�����
								//������p��ָ����ڴ�,����p������һ��Ұָ��
	char buf[100];
	char* p = buf;
	strcpy(p, "hello mike");//strcpy 
	printf("p=%s  buf=%s", p,buf);
	return 0;
}


//�ַ�����ӡ�Ǵ��׵�ַ��ʼ��ӡֱ������\0����0
//�ַ���ָ��
int main02()
{
	char str[] = "hello word";
	printf("%s\n", str);//%s ���������ַ���ָ����ڴ�ռ�
	printf("%p\n", str);//%p�������Ǳ�������
	//*str ������������һ��Ԫ��,��char����
	//printf("%s\n", *str);  �������ֶδ���Segmentation fault (core dumped)
	return 0;
}

//��linux�����л���ֶδ���,��Ϊ�����˾ֲ������ĵ�ַ
//������Linux����fun()�������᷵��a�ĵ�ַ
//Segmentation fault (core dumped)
//��fun()����������ʱ��,a���ڵ��ڴ�ռ�ͱ��ͷ���,���ʱ���ټ����������
//�ڴ��ַ�ͻ���ֶδ���  (Ұָ�����)
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