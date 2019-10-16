#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

/*
��������createList
�������ܣ��������Ա�
��������
��������ֵ���ɹ�ʱ������ָ�����Ա��׵�ַ��ָ�룻ʧ��ʱ������NULL��
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
��������destroyList
�������ܣ��������Ա�
������LIST * pList ָ�����Ա��׵�ַ��ָ��
��������ֵ���ޡ�
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
��������isFull
�������ܣ��ж����Ա��Ƿ���
������LIST * pList ָ�����Ա��׵�ַ��ָ��
��������ֵ����ʱ������1������ʱ������0��ʧ�ܷ���-1��
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
��������insertList
�������ܣ������Ա��������
������LIST * pList ָ�����Ա��׵�ַ��ָ��
int offset �����λ��
data_type item �����Ԫ��
��������ֵ���ɹ�ʱ������0��ʧ��ʱ������-1��
*/
int insertList(LIST * pList, data_type item, int offset)
{
	int i = 0;
	//�ж��Ƿ���Բ���
	if (NULL == pList
		|| 0 > offset
		|| offset > pList->count)
	{
		printf("parameter error\r\n");
		return ERR;
	}

	if (TRUE == isFull(pList))//����
	{
		printf("list is FULL \r\n");
		return ERR;
	}
	//�ƶ�
	for (i = pList->count - 1; i >= offset; i--)
	{
		pList->data[i + 1] = pList->data[i];
	}
	//����
	pList->data[offset] = item;
	//����count
	pList->count++;
	return OK;
}

/*
��������deleteList
�������ܣ������Ա�ɾ������
������LIST * pList ָ�����Ա��׵�ַ��ָ��
int offset ɾ����λ��
data_type * pData ɾ��������
��������ֵ���ɹ�ʱ������0��ʧ��ʱ������-1��
*/
int deleteList(LIST * pList, int offset, data_type * pData)
{

}

/*
��������showList
�������ܣ���ʾ���Ա���������
������LIST * pList ָ�����Ա��׵�ַ��ָ��
��������ֵ���ޡ�
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