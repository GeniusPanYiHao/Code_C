#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int search(int arr[], int sz, int find)
{
	int right = sz - 1;//:right��ʼΪ���ұ�ֵ���±�
	int left = 0;//:left��ʼΪ�����ֵ�±�
	while (left <= right)//:������±�С���ұߵ��±�
	{
		int mid = (left + right) / 2;//:�ҵ����м�������±�
		if (find < arr[mid])//:���Ҫ�ҵ���С���м����
		{
			right = mid - 1;//:���м���ǰ��һ����Ϊ�µ��ұ�
		}
		else if (find>arr[mid])//:���Ҫ�ҵ��������м����
		{
			left = mid + 1;//:���м��������һ��Ϊ�µ����
		}
		else//������м�����պ�ΪҪ�ҵ���
		{
			printf("%d", mid);
			return mid;//������Ҫ�ҵ���������
		}
	}
	printf("-1\n");
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof arr / sizeof arr[0];//:���鳤��
	int ret = search(arr, sz, 9);
	return 0;
}
