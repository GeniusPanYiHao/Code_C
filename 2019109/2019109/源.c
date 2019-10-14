#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void PaiXu(int* arr, int sz)
{
	int left= 0;
	int right = sz - 1;
	int t;
	for (left = 0; left != right; left++)
	{
		if (arr[left] % 2 != 0)
		{
			continue;
		}
		else
		{
			t = arr[left];
			arr[left] = arr[right];
			arr[right] = t;
		}
		if (arr[right] % 2 == 0)
		{
			left--;
			right--;
		}
	}
}
int main()
{
	int arr[] = { 2, 3, 5, 6, 8, 7, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PaiXu(arr, sz);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%-3d", arr[i]);
	}
	return 0;
}










