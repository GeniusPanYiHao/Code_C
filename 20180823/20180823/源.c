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
//	printf("请输入一个字符：");
//	scanf("%d", &i);
//	number(i);
//	return 0;
//}
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。











#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void menu()//:打印菜单
{
	printf("*******************************\n");
	printf("*******1.初始化数组************\n");
	printf("*******2.清空数组**************\n");
	printf("*******3.逆置数组**************\n");
	printf("*******************************\n");
}
int init(char arr[], int sz)//:初始化数组
{
	int a = 0;
	for (a = 0; a < sz; a++)
	{
		printf("%d", arr[a]);
	}
}
int reverse(char arr[], int sz)//:逆置数组
{
	int left = 0;
	int right = sz - 1;
	int i = 0;
	int t = 0;
	while (left < right)//:当数组左边下标小于右边时，将两个数字交换
	{
		i = arr[left];
		arr[left] = arr[right];
		arr[right] = i;
		left++;//:每次交换完左边加1，右边减一
		right--;
	}
	for (t = 0; t < sz; t++)
	{
		printf("%d", arr[t]);
	}
	return arr[t];
}
void empty(char arr[], int sz)//:清空数组，令数组为0
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
	printf("请选择\n");
	scanf("%d", &n);//：进行选择
	switch (n)
	{
	case 1://：当选择为1时执行初始化数组的函数
		init(arr, sz);
		break;
	case 3://：当选择为3时执行逆置数组函数
		reverse(arr, sz);
		break;
	case 2://：当选择为2时执行清空数组函数
		empty(arr, sz);
		break;
	default:
		printf("输入有误\n");
		break;
	}
	system("pause");
	return 0;
}








