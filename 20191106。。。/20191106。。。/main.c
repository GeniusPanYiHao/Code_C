#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int f1 = 0, f2 = 1, f3 = f1 + f2;
	while (1)
	{
		if (n == f2)
		{
			printf("%d", 0);
			break;
		}
		else if (f2>n)
		{
			if (abs(f2 - n)>abs(f1 - n))
			{
				printf("%d", abs(f1 - n));
			}
			else
			{
				printf("%d", abs(f2 - n));
			}
			break;
		}
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}
	return 0;
}