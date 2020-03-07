#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void  BubbleSort(int *a, int n)
{
	int i, j,k;
	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j >=i; j--)
		{
			if (a[j] < a[j - 1])
			{
				k = a[j];
				a[j] = a[j-1];
				a[j - 1] = k;
			}
		}
	}
}
void SelectSort(int *a, int n)
{
	int i, j, iTemp,pos;
	for (i = 0; i < n-1; i++)
	{
		iTemp = a[i];
		pos = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j]<iTemp)
			{
				iTemp = a[j];
				pos = j;
			}
		}
		a[pos] = a[i];
		a[i] = iTemp;
	}
}
void SwapSort(int *a, int n)
{
	int i, j,k;
	for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] >a[j])
			{
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
}
void InsertSort(int *a, int n)
{
	int i, j, k,iTemp,pos;
	for (i = 0; i < n; i++)
	{
		iTemp = a[i];
		pos = i;
		while (iTemp<a[pos-1]&&pos>=0)
		{
			k = a[pos - 1];
			a[pos - 1] = iTemp;
			a[pos] =k;
			pos--;
		}
	}
}
void  SwapSort1(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void QuickSort1(int *a, int left, int right)
{
	int i, j, privot;
	if (left < right)
	{
		privot = a[left];
		i = left;
		j = right;
		while (i <j)
		{
			while ((a[j]>=privot) && i < j)
				j--;
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}
			while ((a[i] <= privot) && i < j)
				i++;
			if (i < j)
			{
				a[j] = a[i];
				j--;
			}
		}
		a[i] = privot;
		QuickSort1(a, left, i - 1);
		QuickSort1(a, i + 1, right);
	}
}
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
void MergeSort(int *a, int n)
{
	int *A = (int*)malloc(n * sizeof(int));
	MSort(a, A, 0, n - 1);
	free(A);
}
void PrintArray(int* a, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[] = {3,5,7,1,2,6};
	int n = sizeof(a)/ sizeof(a[0]);
	int left =0;
	int right = n-1;
	/*SwapSort(a, n);
	PrintArray(a, n);
	SelectSort(a, n);
	BubbleSort(a, n);
	PrintArray(a, n);
	InsertSort(a, n);
	PrintArray(a, n);
	QuickSort1(a, left, right);
	PrintArray(a, n);
	Mid3(a, left, right);*/
	MergeSort(a, n);
	PrintArray(a, n);
}