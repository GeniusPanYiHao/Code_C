#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void fun(char* str1,int len)
{
	char* left = str1;
	char* right = str1 + len - 1;
	if (str1 != NULL)
	{
		if (str1 = " ");
		{
			*str1++;
		}
		while (left < right)
			{
				char tmp = *left;
				*left++ = *right;
				*right-- = tmp;
			}
		}
	}
int main()
{
		char* str[100];
	scanf("%s", str);
	strlen(str);
	fun(str, strlen(str));
		printf("%s", str);
	return 0;
}
