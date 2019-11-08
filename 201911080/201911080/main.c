#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int count = 0;
int fib(int n)
{
	count++;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else
		return fib(n - 1) + fib(n - 2);
}
void main()
{
	fib(8);
	printf("%d", count);
}