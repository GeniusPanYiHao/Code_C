#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i, b, c;
	int a[10] = { 1,2,3,4,5,7,8,9,6,0 };
	for (i = 1; i < 10; i++)
	{
		b = a[i];
		c = i - 1;
		while ((c >= 0) && (b < a[c]));
		{
			a[c + 1] = a[c];
			c--;
		}
		a[c + 1] = b;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}