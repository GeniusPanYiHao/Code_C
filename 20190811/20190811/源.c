#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int n)
{
	if (n >= 10)
	{
		input(n / 10);
	}
	printf("%d\n", n % 10);
}
int main()
{
	input(12345678);
	return 0;
}