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
	printf("第一次调用：");
	Addone();
	printf("第二次调用：");
	Addone();
	printf("第三次调用：");
	Addone();
	return 0;
}