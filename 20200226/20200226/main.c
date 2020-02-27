#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <assert.h>
#include <malloc.h>
typedef struct Node
{
	int elem;
	struct Node *head, *next;
}LNode;
void LNodeInit(LNode *sl)
{
	assert(sl);
	sl->next = NULL;
}
void LNodeDestory(LNode *sl)
{
	assert(sl);
	LNode *cur = sl->next;
	while (cur)
	{
		LNode *next = cur->next;
		free(cur);

		cur = next;
	}
	sl->head = NULL;
}