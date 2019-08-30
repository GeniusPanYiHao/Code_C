#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	extern char iExtern;
	printf("%c", iExtern);
	return 0;
}