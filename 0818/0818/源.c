#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int input(int n)
{
	int i;
	int a;
	int sum = 0;
	int sum1 = 0;
	for (i = n; i; i /= 10)
	{
		for (a = 1; a <= 2; a++)
		{
			{ sum1 += pow(i % 10, a); }
			if (sum1 = n)
			{
				printf("是水仙花数");
			}
			else
			{
				printf("不是水仙花数");
			}
		}
	}
}
int main()
{
	input(11);
	return 0;
}