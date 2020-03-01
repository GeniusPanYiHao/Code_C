#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct stack
{
	ElemType data[MAXSIZE];
	ElemType top;
	int stacksize;
}Stack;
int StackPush(Stack *s, ElemType X)
{
	if (s->top == MAXSIZE - 1)
	{
		printf("栈满\n");
		return 0;
	}
	s->top++;
		s->data[s->top] = X;
	return 1;
}
int StackPop(Stack *s, ElemType *E)
{
	if (s->top == -1)
	{
		printf("栈空\n");
		return 0;
	}
		*E = s->data[s->top];
		--s->top;
	return 1;
}
void StackClear(Stack *s)
{
	s->top = -1;
}
void show(Stack *s)
{
	while (s->top != -1)
	{
		printf("栈内元素有：%d\n", s->data[s->top]);
		s->top--;
	}
}
int main()
{
	int n;
	Stack s = { { 1, 2, 3, 4, 5 }, 4 };
	StackPop(&s, &n);
	printf("出栈的元素为：%d\n", n);
	StackClear(&s);//:清空栈
	StackPush(&s, 7);
	StackPush(&s, 6);
	StackPush(&s, 5);
	show(&s);
}

