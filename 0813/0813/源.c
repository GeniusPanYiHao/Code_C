#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void fun()
{
	char killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		printf("%c", killer);
}
int main()
{
	fun();
	return 0;
}
