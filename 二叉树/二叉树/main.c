#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode
{
	char data;
	int *lchild, *rchild;
}BiTree;
void PreOrderTraverse(BiTree *T)//二叉树的先序遍历
{
	if (T == NULL)
		return;
	printf("%c ", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
void InOrderTraverse(BiTree *T)//二叉树的中序遍历
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c ", T->data);
	InOrderTraverse(T->rchild);
}
void PostOrderTraverse(BiTree *T)//后序遍历
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c ", T->data);
}
void CreateBiTree(BiTree **T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree*)malloc(sizeof(BiTree));
		if (!*T)
			exit(-1);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
int main()
{
	BiTree *T;
	CreateBiTree(&T);
	PreOrderTraverse(T);
	InOrderTraverse(T);
	PostOrderTraverse(T);
	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Bitnode
//{
//	char data;
//	int *Lchild;
//	int *Rchild;
//}BinTree;
////#include<stdio.h>
////#include<stdlib.h>
////typedef struct BiTNode
////{
////	char data;
////	struct BiTNode *lchild, *rchild;
////}BiTNode, *BiTree;
//void CreateTree(BinTree **T)
//{
//	char ch;
//	scanf("%c", &ch);
//	if (ch == '#')
//		*T = NULL;
//	else
//	{
//		*T = (BinTree*)malloc(sizeof(BinTree));
//		if (!*T)
//			return 0;
//		(*T)->data = ch;
//		CreateTree(&(*T)->Lchild);
//		CreateTree(&(*T)->Rchild);
//	}
//}
////void CreateBiTree(BiTree *T)
////{
////	char ch;
////	scanf("%c", &ch);
////	if (ch == '#')
////		*T = NULL;
////	else
////	{
////		*T = (BiTree)malloc(sizeof(BiTNode));
////		if (!*T)
////			exit(-1);
////		(*T)->data = ch;
////		CreateBiTree(&(*T)->lchild);
////		CreateBiTree(&(*T)->rchild);
////	}
////}
//void PreBintree(BinTree *T)
//{
//	if (T == NULL)
//		return;
//	printf("%c  ", T->data);
//	PreBintree(T->Lchild);
//	PreBintree(T->Rchild);
//}
////void PreOrderTraverse(BiTree T)//二叉树的先序遍历
////{
////	if (T == NULL)
////		return;
////	printf("%c ", T->data);
////	PreOrderTraverse(T->lchild);
////	PreOrderTraverse(T->rchild);
////}
//void MidBintree(BinTree *T)
//{
//	if (T == NULL)
//	{
//		return;
//	}
//	MidBintree(T->Lchild);
//	printf("%c", T->data);
//	MidBintree(T->Rchild);
//}
//void AfterBintree(BinTree *T)
//{
//	if (T != NULL)
//		AfterBintree(T->Lchild);
//	AfterBintree(T->Rchild);
//	printf("%d", T->data);
//}
////int main()
////{
////	BiTree T;
////	CreateBiTree(&T);
////	PreOrderTraverse(T);
////	InOrderTraverse(T);
////	PostOrderTraverse(T);
////	return 0;
////}
//int main()
//{
//	BinTree *T;
//	CreateTree(&T);
//	PreBintree(T);
//	MidBintree(T);
//	return 0;
//}
//
