#define _CRT_SECURE_NO_WARNINGS 1
//:二分查找法
#include<iostream>
using namespace std;
int BinarySort(int *a,int key,int n)
{
	int left = 1;
	int mid;
	int right = n;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (a[mid]== key)
		{
			return mid;
			break;
		}
		else if (a[mid] < key)
		{
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
}
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(a) / sizeof(a[0]);
	int key =6;
	cout<<BinarySort(a,5,n)<<endl;
}


//索引查找法


