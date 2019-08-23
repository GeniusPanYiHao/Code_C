#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>  
#include<stdlib.h>
void strcpy(char arr[], char brr[], int sz)
{
	int i = 0;
	for (i = 0; i <=sz; i++)
	{
		arr[i] = brr[i];
	}
}
int main()
{
	char arr[100];
	char brr[] = "student";
	int sz = strlen(brr);
	strcpy(arr, brr, sz);
	printf("%s", arr);
	return 0;
}