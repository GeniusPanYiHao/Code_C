#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void  BubbleSort(int *a, int n)
{
	int i, j,k;
	for (i = 1; i < n; i++)
	{
		for (j = n - 1; j >n/2; j--)
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
//void SwapSort(int *a, int n)
//{
//	int i, j,k;
//	for (i = 0; i < n-1; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			if (a[i] < a[j])
//			{
//				k = a[i];
//				a[i] = a[j];
//				a[j] = k;
//			}
//		}
//	}
//}
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
//int Mid3(int *a, int left, int right)
//{
//	int mid = (left + right) / 2;
//	if (a[left] > a[mid]);
//	{
//		SwapSort1(&a[left], &a[mid]);
//	}
//	if (a[left] > a[right])
//	{
//		SwapSort1(&a[left], &a[right]);
//	}
//	if (a[right] < a[mid])
//	{
//	SwapSort1(&a[right], &a[mid]);
//	}
//	SwapSort1(&a[mid], &a[right - 1]);
//	return a[right - 1];
//}
//void QuickSort1(int *a, int left, int right)
//{
//	int i, j, mid;
//	mid = Mid3(a, left, right);
//	i = left;
//	j = right - 1;
//	while (i<j)
//	{
//		while((a[++i] < mid)&&i<=j)
//		{
//			
//		}
//		while ((a[--j]>mid)&&i<=j)
//		{
//			
//		}
//		if (i < j)
//			SwapSort1(&a[i], &a[j]);
//		else
//			break;
//	}
//	SwapSort1(&a[i], &a[right - 1]);
//	QuickSort1(a, left,j);
//	QuickSort1(a, i+1,right );
//}
void QuickSort(int *a, int left, int right)
{
	int i, j, mid;
	if (left < right)
	{
		int i = left;
		int j = right;
		int mid = (left+right)/2;
		/*SwapSort1(&mid,&a[right]);*/
		while (i<j)
		{
			while ((a[i] < a[mid]) && i <= j)
			{
				i++;
			}
			while((a[j] > a[mid])&&i<=j)
			{
				j--;
			}
			SwapSort1(&a[i],&a[j]);
			/*k = a[i];
			a[i] = a[j];
			a[j] = k;*/
		}
		SwapSort1(&a[i], &a[mid]);
		/*k = a[i];
		a[i] = mid;
		mid= k;*/
		QuickSort(a, left,mid-1);
		QuickSort(a, mid+1, right);
	}
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
	int a[] = {5,4,3,6,5};
	int n = sizeof(a)/ sizeof(a[0]);
	int left =0;
	int right = n-1;
	/*SwapSort(a, n);*/
	//PrintArray(a, n);
	///*SelectSort(a, n);*/
	//PrintArray(a, n);
	/*InsertSort(a, n);*/
	/*PrintArray(a, n);*/
	/*QuickSort(a, left,right);*/
	QuickSort(a, left, right);
	PrintArray(a, n);
	/*Mid3(a, left, right);
	PrintArray(a, n);*/
}