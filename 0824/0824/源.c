//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int input(int n)
//{
//	int c;
//	int a;
//	int b;
//	for (a = 1; a <= n; a++)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			c = a*b;
//			printf("%d*%d=%d    ", b, a, c);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	input(12);
//	return 0;
//}
//2
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int input(int a, int b)
//{
//	int c;
//	c = a;
//	a = b;
//	b = c;
//	printf("%d\n%d", a, b);
//}
//int main()
//{
//	input(22, 55);
//	return 0;
//}
//3
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int year)
{
	if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
	{
		printf(" ������");
	}
	else
		printf("��������");
}
int main()
{
	int n;
	printf("����һ������");
	scanf("%d", &n);
	input(n);
	return 0;
}
