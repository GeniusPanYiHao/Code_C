#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	unsigned char i = 7;
	int j = 0;
	for (i=7; i > 0; i -= 3)
	{
		++j;
	}
	printf("%d\n", j);
	return 0;
}
