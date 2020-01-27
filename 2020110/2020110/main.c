#define _CRT_SECURE_NO_WARNINGS 1
//实现函数 ToLowerCase() ，该函数接收一个字符串参数 str ，并将该字符串中的大写字母转换成小写字母， 之后返回新的字符串
#include<stdio.h>
int input(char* str)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (str[i]>= 'A' && str[i]<='Z')
		{
			str[i] = str[i] + 32;
		}
		else
			str[i] = str[i];
		return str[i];
	}
}
int main()
{
	char str = 'ABCD';
	input(str);
	printf("%s",str);
}
