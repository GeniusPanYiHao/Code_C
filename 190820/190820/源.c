#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int n)
{
	int a;
	int b;
	int c;
	for (a = 1; a <= n; a++)
	{
		for (b = 1; b <= a; b++)
		{
			c = b*a;
			printf("%d*%d=%d  ", b, a, c);
		}
		printf("\n");
	}
}
int main()
{
	input(12);
	return 0;
}
