#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int elem;
	struct Node* next;
}LNode;
void insert(LNode **head, int x)
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
void delete(LNode **head, int pos)//£ºÉ¾³ýµÚpos¸öÔªËØ
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
int main() {
	LNode *head;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		insert(1,2);
	}
	delete(1, 2);
	LNode *t = head;
	while (t != NULL) {
		printf("%d ", t->elem);
		t = t->next;
	}
	return 0;
}
