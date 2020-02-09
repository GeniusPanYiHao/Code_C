#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	//：申请扩容
	int *p1 = (int*)malloc(sizeof(int)* 4);
	//：调整空间，既可以扩容也可以减容
	int* p2 = (int*)realloc(p1, sizeof(int)* 10);
	//:申请空间+0初始化
	int* p3 = (int*)calloc(4, sizeof(int));
	int* p4 = (int*)realloc(p3, sizeof(int)* 1);

	//:free(p1);
	free(p2);
	//:free(p3);
	free(p4);
	return 0;
}