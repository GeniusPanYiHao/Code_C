#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Yang(int arr[][9], int rol, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= rol; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
		}
	}
}
void show(int arr[][9], int rol, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= rol; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%-3d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[9][9] = { 0 };
	Yang(arr, 9, 9);
	show(arr, 9, 9);
	return 0;
}

