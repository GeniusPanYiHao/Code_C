#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
	int main()
	{
		int a=2;
		int b=4;
		int c=5;
		int i;
		for (i = 10; i <= 100; i++)
		{
			if ((i % 3 == a) && (i % 5 == b) && (i % 7 == c))
			{
				printf("%d", i);
			}
		}
	}