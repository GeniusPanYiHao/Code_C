
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	int arr[32] = { 0 };
	unsigned int sum = 0;
	for (i = 0; i < 32; i++)
	{
		arr[i] = value & 1;
		value = value >> 1;
	}
	for (i = 0; i <32; i++)
	{
		sum = sum + arr[i]*pow(2, 31 - i);
	}
	return sum;
}
int main()
{
	int n = 0;
	printf("����һ�����֣�");
	scanf("%d",&n);
	unsigned int a=reverse_bit(n);
	printf("��ת�����ƺ��ֵΪ��   ");
	printf("%u", a);
	return 0;
}



