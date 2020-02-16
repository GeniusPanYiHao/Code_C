#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define n 6
typedef char elemtype;
typedef int bool;
elemtype A[n];
int top1 = 1;
int top2 = n;
void warning(char* s)
{
	puts(s);
}
bool full()
{
	return top2 + 1 == top1;
}
void push1(elemtype elem)
{
	if (full())warning("stack overflow");
	else{ A[top1] = elem; top1++; }
}
void push2(elemtype elem)
{
	if (full())warning("stack overflow");
	else{ A[top2] = elem; top2--; }
}
bool empty1()
{
	return top1 == 1;
}
bool empty2()
{
	return top2 == n;
}
elemtype tops1()
{
	return A[top1 - 1];
}
elemtype tops2()
{
	return A[top2 + 1];
}
void pop1()
{
	if (empty1())warning("stack underflow");
	else top1--;
}
void pop2()
{
	if (empty2())warning("stack underflow");
	else top2++;
}
void traverse()
{
	int i;
	for (i = 1; i < top1; i++)
		putchar(A[i]);
	putchar(' ');
	for (i = n; i>top2; i--)
		putchar(A[i]);
	putchar('\n');
}
int main(void)
{
	traverse();
	pop1();
	push1('a');
	putchar(tops1()); putchar('\n');
	pop2();
	push2('z');
	push2('y');
	push2('x');
	push2('w');
	traverse();
	pop2(); pop2(); pop2(); pop2(); pop1();
	traverse();
	push1('b'); push1('b'); push1('b'); push1('b');
	traverse();
	return 0;
}

