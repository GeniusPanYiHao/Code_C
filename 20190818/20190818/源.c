#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int input(int n)//:nΪ����
{
	int i = 0;
	int a = 0;
	int b = 1;
	for (i = 0; i <= n - 1; i++)//:��ӡ�ϰ벿��
	{
		for (a = n - i - 1; a > 0; a--)//:��ӡ�ո�iÿȡһ��ֵѭ�����ٴξʹ�ӡ���ٸ��ո�
		{
			printf(" ");
		}
		for (b = 0; b <2 * i + 1; b++)//����ӡ*�ţ�iÿȡһ��ֵѭ�����ٴξʹ�ӡ���ٸ�*��
		{
			printf("*");
		}
		printf("\n");//:i������һ��ȡֵǰ����
	}
	for (i = n - 1; i >0; i--)//:��ӡ�°벿�֣�ԭ��ͬ��
	{
		for (a = 0; a<n - i; a++)
		{
			printf(" ");
		}
		for (b = 0; b <2 * i - 1; b++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	input(7);
	return 0;
}

