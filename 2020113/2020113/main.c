#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i, j;
//	int min;
//	int b;
//	int a[10] = { 0, 2, 3, 1, 5, 4, 6, 8, 9, 7 };
//	/*for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}*/
//	for (i = 0; i < 10; i++)
//	{
//		min= a[i];
//		b = i;
//		for (j = i + 1; j < 10; j++)
//		{
//			if (min>a[j])
//			{
//				min = a[j];
//				b = j;
//			}
//		}
//		a[b] = a[i];
//		a[i] = min;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", a[i]);
//	}
//	return 0;
//}



//#include<stdio.h>
//int paixu(char* a)
//{
//	int i, j;
//	int min, b;
//	int len = strlen(a);
//	for (i = 0; i <10; i++)
//	{
//		min = a[i];
//		b = i;
//		for (j = i + 1; j <10; j++)
//		{
//			if (a[j] < min)
//			{
//				min = a[j];
//				b = j;
//			}
//		}
//		a[b] = a[i];
//		a[i] = min;
//	}
//	for (i = 0; i <10; i++)
//	{
//		printf("%d\n", a[i]);
//	}
//}
//int main()
//{
//	char a[] = { 0, 2, 1, 4, 3, 6, 5, 9, 8, 7 };
//	paixu(a);
//}








#include<stdio.h>
int main()
{
	int i, j;
	int min;
	int b, c;
	int a[] = { 1, 0, 3, 2, 5, 6, 4, 8, 9, 7 };
	for (i = 0; i <= 9; i++)
	{
		for (j = 9; j >= 0; j--)
		{
			if (a[j] < a[j - 1])
			{
				min = a[j-1];
				a[j-1] = a[j];
				a[j] = min;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}
}








