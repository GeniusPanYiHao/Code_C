#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	float fDues;
	float fAmount;
	int iOntime;
	char cChar;
	printf("请输入欠款数额：\n");
	scanf("%f", &fDues);
	printf("是否按时还款？(y/n)\n");
	getchar();
	cChar = getchar();
	iOntime = (cChar == 'y') ? 1 : 0;
	fAmount = iOntime ? fDues : (fDues*1.1);
	printf("%.2f", fAmount);
	return 0;
}

