#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
void MSort(int *a, int *A, int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MSort(a, A, left, mid);
	MSort(a, A, mid + 1, right);
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int Aindex = left;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			A[Aindex] = a[begin1];
			Aindex++;
			begin1++;
		}
		else
		{
			A[Aindex] = a[begin2];
			Aindex++;
			begin2++;
		}
	}
	while (begin1 <= end1)
	{
		A[Aindex] = a[begin1];
		Aindex++;
		begin1++;
	}
	while (begin2 <= end2)
	{
		A[Aindex] = a[begin2];
		Aindex++;
		begin2++;
	}
	memcpy(a + left, A + left, (right - left + 1) * sizeof(int));
}
void MerageSort(int *a, int n)
{
	int *A = (int*)malloc(n * sizeof(int));
	MSort(a, A, 0,n-1);
	free(A);
}

void Print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
}
int main()
{
	int a[] = { 1, 3, 0, 2, 5, 4, 9, 6 };
	int n = sizeof(a) / sizeof(a[0]);
	MerageSort(a, n);
	Print(a, n);
}