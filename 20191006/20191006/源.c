//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
//4.
//��һ���ַ����������Ϊ:"student a am i",
//			���㽫��������ݸ�Ϊ"i am a student".
//			Ҫ��
//			����ʹ�ÿ⺯����
//			ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int arr[32] = { 0 };
	int i = 0;
	unsigned int sum = 0;
	for (i =0; i <= 31; i++)
	{
		arr[i] = value & 1;
		value = value >> 1;
	}
	for (i =0; i<=31; i++)
	{
		sum += arr[i]*pow(2, 31-i);
	}
	return sum;
}
int main()
{
	unsigned int a=reverse_bit(25);
	printf("%u",a);
	return 0;
}

