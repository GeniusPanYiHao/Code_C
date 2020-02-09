#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int f1 = 0;
	int f2 = 1;
	int f3 = 1;
	int N = 0;
	scanf("%d", &N);
	while (1)
	{
		if (f2 == N)
		{
			printf("0");
			break;
		}
		if (f2 > N)
		{
			if (abs(f2 - N) > abs(f1 - N))
			{
				printf("%d", abs(f1 - N));
				break;
			}
			else
			{
				printf("%d", abs(f2 - N));
				break;
			}
		}
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}
}