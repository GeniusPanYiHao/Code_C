#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int sum = 0;
	int a = 1;
	int b = 2;

	int e = a^b;
	while (e != 0)
	{
		sum++;
		e = e&(e - 1);
	}
	printf("%d", sum);
	return 0;
}
