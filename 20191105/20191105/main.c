
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<string.h>
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void _MergeSort(int* a, int left, int right, int* tmp)
{
	//:区间只剩一个元素，不需要分解和合并
	if (left >= right)
	{
		return;
	}
	//:分解
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	//:归并
	int begin1 = left;
	int begin2 = mid + 1;
	int end1 = mid;
	int end2 = right;
	int tmpindex = begin1;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			swap(&tmp[tmpindex++], &a[begin1++]);
		}
		else
		{
			swap(&tmp[tmpindex++], &a[begin2++]);
		}
	}
	while (begin1 <= end1)
	{
		swap(&tmp[tmpindex++], &a[begin1++]);
	}
	while (begin2 <= end2)
	{
		swap(&tmp[tmpindex++], &a[begin2++]);
	}
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*(n + 1));
	_MergeSort(a, 0, n, tmp);
	free(tmp);
}
int main()
{
	int a[] = { 10, 5, 6, 8, 9, 4, 2, 1, 3, 7 };
	int len = sizeof(a) / sizeof(a[0]);
	MergeSort(a, len - 1);
	int i = 0;
	for (i = 0; i <= 11; i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}