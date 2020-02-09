#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int i(int n)
{
	if (n <= 2)
		return 1;
	else
		return i(n - 1) + i(n - 2);
}
int main()
{
	printf("%d", i(6));
}