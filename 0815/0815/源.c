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
		if (arr[i] % 2 != 0)
		{
			continue;
		}
		else
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
		if (arr[j] % 2 == 0)
		{
			i--;
			j--;
		}

	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i;
	input(arr, sz);
	for (i = 0; i<sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}