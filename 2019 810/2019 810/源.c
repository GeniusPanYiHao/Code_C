#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int n)
{
	if (n == 1)
	{
		return 1;
	}
		return n*input(n - 1);
}
int main()
{
	int n = 1;
	printf("输入一个数");
	scanf("%d",& n);
	printf("%d", input(n));
	return 0;
}
