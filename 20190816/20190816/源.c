#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int a)
{
	int i;
	int j;
	int c;
	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= i; j++)
		{
			c = i*j;
			printf("%d*%d=%d   ",i,j, c);
		}
		printf("\n");
	}
}
int main()
{
	input(9);
	return 0;
}
