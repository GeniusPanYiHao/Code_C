//Fibonacci数列是这样定义的：
//F[0] = 0
//F[1] = 1
//for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，
//你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
#define _CRT_SECURE_NO_WARNINGS 1
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
			printf("%d",0);
			break;
		}
		else if (f2 > n)
		{
			if (abs(f2 - n) > abs(f1 - n))
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
