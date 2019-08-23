#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int n)
{
	int a = 1;
	int b = 2;
	int c = 3;
	if (n > 1)
	{
		c = a*b*c;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	printf("输入一个数");
	scanf("%d", &n);
	printf("%d", input(n));
	return 0;
}