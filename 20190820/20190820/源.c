#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int search(int arr[], int sz, int find)
{
	int right = sz - 1;//:right初始为最右边值得下标
	int left = 0;//:left初始为最左边值下标
	while (left <= right)//:如果左下标小于右边的下标
	{
		int mid = (left + right) / 2;//:找到最中间的数的下标
		if (find < arr[mid])//:如果要找的数小于中间的数
		{
			right = mid - 1;//:令中间数前面一个数为新的右边
		}
		else if (find>arr[mid])//:如果要找的数大于中间的数
		{
			left = mid + 1;//:令中间的数后面一个为新的左边
		}
		else//：如果中间的数刚好为要找的数
		{
			printf("%d", mid);
			return mid;//：返回要找的数的坐标
		}
	}
	printf("-1\n");
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof arr / sizeof arr[0];//:数组长度
	int ret = search(arr, sz, 9);
	return 0;
}
