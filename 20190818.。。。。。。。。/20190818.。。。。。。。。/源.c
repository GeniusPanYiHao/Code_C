#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void input(int* arr, int sz)
{
	int i = 0;
	int t = 0;
	int j = sz - 1;
	for (i = 0; i != j; i++)
	{
		if (arr[i] % 2 != 0)//:从左边第一个数开始判断，如果为奇数，则继续
		{
			continue;
		}
		else//:如果为偶数则放在右边
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
		if (arr[j] % 2 == 0)//：从右边第一个数开始判断，若为偶数，则判断前一个数
		{
			i--;
			j--;
		}

	}
}
int main()
{
	int arr[] = { 1, 1,3,3,5,5,7,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);//：整个数组的长度//sizeof(arr)为整个数组的字节数，sizeof(arr[0])为一个元素所占的字节数
	int i;
	input(arr, sz);//:调用函数
	for (i = 0; i<sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

