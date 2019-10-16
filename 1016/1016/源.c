#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

/*
函数名：createList
函数功能：创建线性表
参数：无
函数返回值：成功时，返回指向线性表首地址的指针；失败时，返回NULL。
*/
LIST * createList(void)
{
	LIST * pList = NULL;

	pList = (LIST *)malloc(sizeof(LIST));
	if (NULL != pList)
	{
		memset(pList, 0, sizeof(LIST));
		pList->count = 0;
	}
	return pList;
}

/*
函数名：destroyList
函数功能：销毁线性表
参数：LIST * pList 指向线性表首地址的指针
函数返回值：无。
*/
void destroyList(LIST * pList)
{
	if (NULL == pList)
	{
		return;
	}
	free(pList);
	pList = NULL;
}
/*
函数名：isFull
函数功能：判断线性表是否满
参数：LIST * pList 指向线性表首地址的指针
函数返回值：满时，返回1；不满时，返回0；失败返回-1。
*/
int isFull(LIST * pList)
{
	if (NULL == pList)
	{
		return ERR;
	}
	if (SIZE == pList->count)
	{
		return TRUE;
	}
	return FALSE;
}

/*
函数名：insertList
函数功能：给线性表插入数据
参数：LIST * pList 指向线性表首地址的指针
int offset 插入的位置
data_type item 插入的元素
函数返回值：成功时，返回0；失败时，返回-1。
*/
int insertList(LIST * pList, data_type item, int offset)
{
	int i = 0;
	//判断是否可以插入
	if (NULL == pList
		|| 0 > offset
		|| offset > pList->count)
	{
		printf("parameter error\r\n");
		return ERR;
	}

	if (TRUE == isFull(pList))//表满
	{
		printf("list is FULL \r\n");
		return ERR;
	}
	//移动
	for (i = pList->count - 1; i >= offset; i--)
	{
		pList->data[i + 1] = pList->data[i];
	}
	//插入
	pList->data[offset] = item;
	//更新count
	pList->count++;
	return OK;
}

/*
函数名：deleteList
函数功能：从线性表删除数据
参数：LIST * pList 指向线性表首地址的指针
int offset 删除的位置
data_type * pData 删除的数据
函数返回值：成功时，返回0；失败时，返回-1。
*/
int deleteList(LIST * pList, int offset, data_type * pData)
{

}

/*
函数名：showList
函数功能：显示线性表所有数据
参数：LIST * pList 指向线性表首地址的指针
函数返回值：无。
*/
void showList(LIST * pList)
{
	int i = 0;
	if (NULL == pList)
	{
		return;
	}
	for (i = 0; i < pList->count; i++)
	{
		printf("%d\t", pList->data[i]);
	}
	printf("\r\n");
}