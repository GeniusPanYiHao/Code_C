#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int n)//:n为行数
{
	int i = 0;
	int a = 0;
	int b = 1;
	for (i = 0; i <= n - 1; i++)//:打印上半部分
	{
		for (a = n - i - 1; a > 0; a--)//:打印空格，i每取一次值循环多少次就打印多少个空格
		{
			printf(" ");
		}
		for (b = 0; b <2 * i + 1; b++)//：打印*号，i每取一次值循环多少次就打印多少个*号
		{
			printf("*");
		}
		printf("\n");//:i进入下一次取值前换行
	}
	for (i = n - 1; i >0; i--)//:打印下半部分，原理同上
	{
		for (a = 0; a<n - i; a++)
		{
			printf(" ");
		}
		for (b = 0; b <2 * i - 1; b++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	input(7);
	return 0;
}

