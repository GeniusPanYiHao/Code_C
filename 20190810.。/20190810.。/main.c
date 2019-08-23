#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int n)
{
	if (n <= 9)
		return n;
	else
		return input(n)*input(n - 1);
}
int main()
{
	int n = 1;
	printf("输入一个数");
	scanf("%d", n);
	printf("%d", input(n));
	return 0;
}
