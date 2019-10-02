//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void fun()
//{
//	int a;
//	int b;
//	int c;
//	int d;
//	int e;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					if (((b == 2) + (a == 3) == 1) && ((b == 2) + (e == 4) == 1) && ((c == 1) + (d == 2) == 1) && ((c == 5) + (d == 3) == 1) && ((e == 4) + (a == 1) == 1) && (a*b*c*d*e == 120))
//						printf("a=%db=%dc=%dd=%de=%d", a, b, c, d, e);
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	fun();
//		return 0;
//}
//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void YangH(int arr[][6],int rol,int col)
{
	int i;
	int j;
	for (i = 0; i <= rol; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
}
void show(int arr[][6], int rol, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= rol; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[6][6];
	YangH(arr,6,6);
	show(arr, 6, 6);
	return 0;
}