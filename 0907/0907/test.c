#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	float fDues;
	float fAmount;
	int iOntime;
	char cChar;
	printf("������Ƿ�����\n");
	scanf("%f", &fDues);
	printf("�Ƿ�ʱ���(y/n)\n");
	getchar();
	cChar = getchar();
	iOntime = (cChar == 'y') ? 1 : 0;
	fAmount = iOntime ? fDues : (fDues*1.1);
	printf("%.2f", fAmount);
	return 0;
}

