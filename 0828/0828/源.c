
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int n)
{
	int a = 1;
	int i = 1;
	for (i = 1; i <= n; i++)
		a *= i;
	return a;
}
int main()
{
	int n = 1;
	printf("输入一个数");
	scanf("%d", &n);
	printf("%d", input(n));
	return 0;
}