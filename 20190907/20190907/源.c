#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char cBig;
	char cSmall;
	puts("�����룺");
	cBig = getchar();
	cSmall = cBig + 32;
	printf("%c", cSmall);
	return 0;
}