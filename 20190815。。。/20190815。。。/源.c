#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define cow	3
#define row	3
int input(int arr[cow][row], int key)
{
	int i = 0;
	int j = row - 1;
	while ((j >= 0) && (i <= 2))
	{
		if (arr[i][j] == key)
		{
			return 1;
		}
		else if (arr[i][j] < key)
		{
			++i;
		}
		else
		{
			--j;
		}
	}
	return 0;
}
int main()
{
	int arr[cow][row] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int key = 0;
	int ret = 0;
	printf("输入要查找的数：");
	scanf("%d", &key);
	ret = input(arr, key);
	if (ret == 1)
	{
		printf("杨氏矩阵中有:%d\n",key);
	}
	else
	{
		printf("杨氏矩阵中没有:%d\n",key);
	}
	return 0;
}

