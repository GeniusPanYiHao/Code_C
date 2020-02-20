#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct LNode *List;
typedef ElementType;
#define MAXSIZE 10
struct LNode
{
	ElementType Data[MAXSIZE];
	int Last;
};
struct LNode L;
List PtrL;
List Empty()
{
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Last = -1;
}
int Find(ElementType x, List PtrL)
{
	int i = 0;
	while (i <= PtrL->Last&&PtrL->Data[i] != x)
	{
		i++;
	}
	if (i > PtrL->Last)
	{
		return -1;
	}
	else
		return i;
}
void Insert(ElementType x, int i, List PtrL)
{
	int j;
	if (PtrL->Last ==MAXSIZE- 1)
	{
		printf("����");
		return;
	}
	if (i<1 && i>PtrL->Last + 2)
	{
		printf("λ�ò��Ϸ�");
		return;
	}
	for (j = PtrL->Last; j >= i - 1; j--)
	{
		PtrL->Data[j + 1] = PtrL->Data[j];
		PtrL->Data[i - 1] = x;
		PtrL->Last++;
		return;
	}
}
void Delete(int i, List PtrL)
{
	int j;
	if (i<1 || i>PtrL->Last + 1)
	{
		printf("�����ڴ�Ԫ��");
		return;
	}
	for (j = i; j <= PtrL->Last; j++)
	{
		PtrL->Data[j-1] = PtrL->Data[j];
		PtrL->Last--;
		return;
	}
}