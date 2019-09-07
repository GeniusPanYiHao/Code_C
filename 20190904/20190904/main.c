#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char cChar;
	short int iShort;
	int iInt;
	float fFloat = 70000;
	cChar = (char) fFloat;
	iShort = (short)fFloat;
	iInt = (int)fFloat;
	printf("%c\n", cChar);
	printf("%d\n", iShort);
	printf("%d\n", iInt);
	printf("%f\n", fFloat);
}