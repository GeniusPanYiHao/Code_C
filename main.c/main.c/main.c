#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int n)
{
	int a = 1;
	int b = 1;
	int c = 2;
	int i;
	for (i = 1; i <= n; i++)
	{
		if (i < 3)
		{
			c = 1;
		}
		else
		{
			c = a + b;
			a = b;
			b = c;
		}
	}
	printf("%d", c);
}
int main()
{
	int n = 0;
	printf("������һ�����֣�");
	scanf("%d", &n);
	input(n);
	return 0;
}
