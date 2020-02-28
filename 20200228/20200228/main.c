#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Node
{
	int data;
	struct Node *next;
}LNode;
LNode *creat(int n){
	LNode *head, *node, *end;//����ͷ�ڵ㣬��ͨ�ڵ㣬β���ڵ㣻
	head = (LNode*)malloc(sizeof(LNode));//�����ַ
	end = head;         //���ǿ�������ͷβ�ڵ�һ��
	for (int i = 0; i < n; i++) {
		node = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &node->data);
		end->next = node;
		end = node;
	}
	end->next = NULL;//��������
	return head;
}

void Find1(LNode *head, int pos)//����ֵ����
{
	LNode *p = head;
	int i = 1;
	while (p != NULL&&i != pos)
	{
		p = p->next;
		i++;
	}
	if (i == pos)
		return p;
	else
		return NULL;
}
void Find2(LNode *head, int X)
{
	LNode *p = head;
	while (p != NULL&&p->data != X)
	{
		p = p->next;
	}
	return p;
}
void Insert(LNode *head, int i,int X)//:�ڵ�i��Ԫ��ǰ����X
{
	LNode *s;
	if (i == 1)//:����headǰ����
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = X;
		s->next = head;
		return s;
	}
	Find1(head, i - 1);
	LNode *p = head;
	int a = 1;
	while (p!=NULL&&a < i)
	{
		p = p->next;
	}
	s = (LNode*)malloc(sizeof(LNode));
	s->data = X;
	s->next = p->next;
	p->next = s;
	return head;
}
void Delete(LNode *head,int i)//:ɾ������ĵ�i���ڵ�
{
	LNode *s;
	if (i == 1)
	{
		s = head;
		if (head != NULL)
		{
			head = head->next;
		}
		else
			return NULL;
		free(s);
		return head;
	}
	Find1(head, i - 1);
	LNode *p = head;
	int a = 1;
	while (p != NULL&&a < i)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("��i���ڵ㲻����");
		return NULL;
	}
	else if (p->next == NULL)
	{
		printf("������");
		return NULL;
	}
	else
		s = p->next;
	p->next = s->next;
	free(s);
	return head;
}
void show(LNode *head)//��������
{
	LNode *h = head;
	while (head->next != NULL)
	{
		h = h->next;
		printf("%d", h->data);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	creat(n);
	LNode *head=creat(1);
	/*Delete(head, 2);*/
	/*Insert(head, 2, 1);*/
	show(head);
}