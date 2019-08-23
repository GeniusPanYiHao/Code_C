#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int a, int b)
{
	int i = a%b;
	while (a%b == i)
	{
		if (i != 0)
		{
			a = b;
			b = i;
		}
		if (i == 0)
		{
			break;
		}
		printf("%d", b);
	}
	return b;
}
int main()
{
	input(1000,10000);
	return 0;
}