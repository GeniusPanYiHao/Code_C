#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int pow(int n, int k)
{
	if (k == 1)
	{
		return n;
	}
	return n*pow(n, k - 1);
}int main()
{
	int a = pow(2, 4);
	printf("%d", a);
	return 0;
}
