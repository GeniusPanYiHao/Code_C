//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ39
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int d = 20;
	int n = d / 1;
	{n == d / 1; }
	int i;
	{i = n / 2; }
	int a;
	{a = i / 2; }
	int b;
	{b = a / 2; }
	int c;
	{c = b / 2; }
	printf("%d", n + i + a + b + c);
}
