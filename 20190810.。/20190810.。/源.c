#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int digist(int n)
{
	if (n >9)
	{
	digist(n/10);
	}
	printf("%d  ", n%10);
}
int main()
{
	digist(5896);
	return 0;
}