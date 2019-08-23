#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int input(int n)
{
	int i = 0;
	for (i = 0; i <= n; i++)
	{
		int t = i;
		int sum = 0;
		int count = 0;
		while (t != 0)
		{
			count++;
			t = t / 10;
		}
		t = i;
		while (t != 0)
		{
			sum += pow((double)(t % 10), (double)count);
			t = t / 10;
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
int main()
{
	input(999999);
		return 0;
}
