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
		if (arr[i] % 2 != 0)//:����ߵ�һ������ʼ�жϣ����Ϊ�����������
		{
			continue;
		}
		else//:���Ϊż��������ұ�
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
		if (arr[j] % 2 == 0)//�����ұߵ�һ������ʼ�жϣ���Ϊż�������ж�ǰһ����
		{
			i--;
			j--;
		}

	}
}
int main()
{
	int arr[] = { 1, 1,3,3,5,5,7,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);//����������ĳ���//sizeof(arr)Ϊ����������ֽ�����sizeof(arr[0])Ϊһ��Ԫ����ռ���ֽ���
	int i;
	input(arr, sz);//:���ú���
	for (i = 0; i<sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

