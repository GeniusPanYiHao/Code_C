//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水39
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int d = 20;
	int n = d / 1;
	{n == d / 1; }
	int i;
	{i = n / 2; }
	int a;
	{a = i / 2; }
	int b;
	{b = a / 2; }
	int c;
	{c = b / 2; }
	printf("%d", n + i + a + b + c);
}
