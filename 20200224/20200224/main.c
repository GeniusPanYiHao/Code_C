#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int elem;
	struct Node* next;
}LNode;
void insert(LNode **head, int x)//：尾插法建立单链表
{
	LNode *temp = (LNode*)malloc(sizeof(LNode));
	temp->next = NULL;
	temp->elem = x;
	if ((*head) == NULL)
	{
		(*head) = temp;
	}
	else
	{
		LNode *t = (*head);
		while (t->next != NULL)
		{
			t = t->next;
		}
		t->next = temp;
	}
}
void delete(LNode **head, int pos)//：删除第pos个元素
{
	int i = 1;
	LNode *p=head;
	while (i < pos-1&&p!=NULL)
	{
		i++;
		p = p->next;
	}
	p->next= p->next->next;
	free(p->next);
}
void print(LNode *head)
{
	LNode *p = head->next;
	while (head != NULL)
	{
		printf("%d", p->elem);
		p = p->next;
	}
}
void test()
{
	LNode* head;
	insert(&head, 1);
	delete(&head, 1);
	print(&head);
}
int main() 
{
	test();
}
