//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//char number(char p)
//{
//	while ((p = getchar()) != EOF)
//	{
//		if ((p >= 'a') && (p <= 'z'))
//			printf("%c\n", p - 32);
//		else if ((p >= 'A') && (p <= 'Z'))
//			printf("%c\n", p + 32);
//		else if ((p >= '1') && (p >= '9'))
//			;
//	}
//}
//int main()
//{
//	int i;
//	printf("������һ���ַ���");
//	scanf("%d", &i);
//	number(i);
//	return 0;
//}
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��











#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void menu()//:��ӡ�˵�
{
	printf("*******************************\n");
	printf("*******1.��ʼ������************\n");
	printf("*******2.�������**************\n");
	printf("*******3.��������**************\n");
	printf("*******************************\n");
}
int init(char arr[], int sz)//:��ʼ������
{
	int a = 0;
	for (a = 0; a < sz; a++)
	{
		printf("%d", arr[a]);
	}
}
int reverse(char arr[], int sz)//:��������
{
	int left = 0;
	int right = sz - 1;
	int i = 0;
	int t = 0;
	while (left < right)//:����������±�С���ұ�ʱ�����������ֽ���
	{
		i = arr[left];
		arr[left] = arr[right];
		arr[right] = i;
		left++;//:ÿ�ν�������߼�1���ұ߼�һ
		right--;
	}
	for (t = 0; t < sz; t++)
	{
		printf("%d", arr[t]);
	}
	return arr[t];
}
void empty(char arr[], int sz)//:������飬������Ϊ0
{
	int t;
	for (t = 0; t < sz; t++)
	{
		arr[t] = 0;
		printf("%d", arr[t]);
	}
}
int main()
{
	char arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int n = 0;
	int i = 0;
	menu();
	printf("��ѡ��\n");
	scanf("%d", &n);//������ѡ��
	switch (n)
	{
	case 1://����ѡ��Ϊ1ʱִ�г�ʼ������ĺ���
		init(arr, sz);
		break;
	case 3://����ѡ��Ϊ3ʱִ���������麯��
		reverse(arr, sz);
		break;
	case 2://����ѡ��Ϊ2ʱִ��������麯��
		empty(arr, sz);
		break;
	default:
		printf("��������\n");
		break;
	}
	system("pause");
	return 0;
}








