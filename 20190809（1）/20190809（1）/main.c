#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int fib(int n)
{
	int a = 1;
	int a1 = 1;
	int a2;
	if (n <= 2)
	return 1;
	else
	{
		while (n > 2)
	{
			a2 = a + a1;
			a = a1;
			a1 = a2;
			n--;
	}
	}
	return a2;
}
int main()
{
	int n = 0;
	printf("输入一个数");
	scanf("%d", &n);
	printf("%d", fib(n));
	return 0;
}