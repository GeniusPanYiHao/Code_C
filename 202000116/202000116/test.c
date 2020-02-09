#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i, b, c;
	int a[10] = { 0,2,1,3,4,5,6,7,8,9};
	for (i = 1; i < 10; i++)
	{
		b = a[i];
		c = i - 1;
		while ((c >= 0) && (b < a[c]));
		{
			a[c + 1] = a[c];
			c--;
		}
		a[c+1] = b;
	}
	for (int d = 0; d < 10; d++)
	{
		printf("%d\n", a[d]);
	}
	return 0;
}