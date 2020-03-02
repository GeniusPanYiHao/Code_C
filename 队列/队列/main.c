#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int ElemType;
#define MAXSIZE 6
typedef struct QUEUE
{
	int rare;
	int front;
	ElemType *data;
}Queue;
Queue *InitQueue(Queue *Q)
{
	Q->data = (ElemType*)malloc(sizeof(ElemType));
	if (!Q->data)
	{
		return 0;
	}
	Q->rare = 0;
	Q->front = 0;
}
void enQueue(Queue *Q, ElemType X)
{
	if (Q->front==-1)
	{
		return NULL;
	}
	Q->data[Q->rare] = X;
	Q->rare++;
	return 1;
}
void outQueue(Queue *Q, ElemType E)
{
	if (Q->front==-1)
	{
		return NULL;
	}
	E = Q->data[Q->front];
	Q->front++;
	printf("出队的元素为：%d\n", E);
}
void show(Queue *Q)
{
	int E;
	while (Q->rare!=Q->front)
	{
		E = Q->data[Q->front];
		printf("队内的元素有：%d\n", E);
		Q->front++;
	}
}
int main()
{
	int E;
	Queue Q;
	InitQueue(&Q);
	enQueue(&Q, 55);
	outQueue(&Q, &E);
	enQueue(&Q, 5);
	enQueue(&Q, 55);
	enQueue(&Q, 55);
	outQueue(&Q, &E);
	enQueue(&Q, 55);
	enQueue(&Q, 4);
	outQueue(&Q,&E);
	show(&Q);
}
