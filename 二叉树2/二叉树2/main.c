#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Bintree
{
	char data;
	int *Lchild;
	int *Rchild;
}BinTree;
void CreateTree(BinTree **T)
{
	int val;
	scanf("%d", &val);
	if (val == 0)
		*T = NULL;
	else
	{
		*T = (BinTree*)malloc(sizeof(BinTree));
		if (!*T)
		{
			exit(1);
		}
		(*T)->data = val;
		CreateTree(&(*T)->Lchild);
		CreateTree(&(*T)->Rchild);
	}
}
void PreBintree(BinTree *T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%d  ", T->data);
	PreBintree(T->Lchild);
	PreBintree(T->Rchild);
}
void MidBintree(BinTree *T)
{
	if (T == NULL)
	{
		return;
	}
	MidBintree(T->Lchild);
	printf("%d  ", T->data);
	MidBintree(T->Rchild);
}
void AfterBintree(BinTree *T)
{
	if (T == NULL)
	{
		return;
	}
	AfterBintree(T->Lchild);
	AfterBintree(T->Rchild);
	printf("%d  ", T->data);
}
int main()
{
	BinTree *T;
	CreateTree(&T);
	printf("前序遍历为：");
	PreBintree(T);
	printf("中序遍历为：");
	MidBintree(T);
	printf("后序遍历为：");
	AfterBintree(T);
	return 0;
}
