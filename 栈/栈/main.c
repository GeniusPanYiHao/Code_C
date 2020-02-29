#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define STACK_INIT_SIZE 100
typedef int ElemType;
typedef struct stack
{
	ElemType *top;//:ָ��ջ����ָ��
	ElemType *base;//��ָ��ջ�׵�ָ��
	int stacksize;//��ջ��ǰ���õ��������

}Stack;
Stack *StackInit(Stack *s)
{
	s->base = (ElemType*)(malloc(STACK_INIT_SIZE* sizeof(ElemType)));
	if (s->base == NULL)
		exit(0);
	else
		s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
}
void stackPush(Stack *s, ElemType X)
{
	if (s->top ==s->base)
	{
		return NULL;
	}
	else
		s->top++;
	s->top= X;
	return;
}
void stackPop(Stack *s, ElemType E)
{
	if (s->top == s->base)
	{
		return NULL;
	}
	else
		E = s->top;
	s->top--;
}
void show(Stack *s)
{
	while (s->top != s->base)
	{
		printf("%d", s->top);
	}
	return NULL;
}
int main()
{
	Stack *s;
	s=StackInit(0);
	stackPush(s, 1);
	stackPush(s, 1);
	stackPush(s, 1);
	stackPush(s, 1);
	stackPush(s, 1);
	show(s);
}