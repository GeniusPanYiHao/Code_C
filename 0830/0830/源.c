#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Addone()
{
	auto int ilnt = 1;
	ilnt += 1;
	printf("%d\n", ilnt);
}
int main()
{
	printf("��һ�ε��ã�");
	Addone();
	printf("�ڶ��ε��ã�");
	Addone();
	printf("�����ε��ã�");
	Addone();
	return 0;
}