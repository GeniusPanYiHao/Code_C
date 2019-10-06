//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值是value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
//4.
//有一个字符数组的内容为:"student a am i",
//			请你将数组的内容改为"i am a student".
//			要求：
//			不能使用库函数。
//			只能开辟有限个空间（空间个数和字符串的长度无关）。
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

