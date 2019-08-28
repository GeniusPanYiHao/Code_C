//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int input(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 2;
//	int i;
//	for (i = 1; i <= n;i++)
//	{
//		if (i < 3)
//		{
//			c = 1;
//		}
//		else
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//	}
//	printf("%d", c);
//}
//int main()
//{
//	int n = 0;
//	printf("请输入一个数字：");
//	scanf("%d", &n);
//	input(n);
//	return 0;
//}







#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int fib(int n)
{
	int a = 1;
	int b = 1;
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	int n;
	printf("请输入一个数：");
	scanf("%d", &n);
	printf("%d", fib(n));
	return 0;
}
