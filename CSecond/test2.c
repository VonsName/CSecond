#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//第十天15课时



//static全局变量和普通的全局变量作用域(文件作用域)不一样
//所有文件中,同一个普通全局变量只能定义一次,但是可以声明多次
//而同一个静态全局变量在每个文件中都可以定义一次
//普通全局变量在所有文件中都可以使用 前提是需要声明
//静态全局变量只能在当前文件中才能使用
int main()
{
	return 0;
}