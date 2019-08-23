#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
int main()
{
	int a, i;
	int count = 0;
	int temp1[16];
	int temp2[16];
	scanf("%d", &a);
	while (count<32)
	{
		temp1[count / 2] = a % 2;
		a = a >> 1;
		count++;
		temp2[(count - 1) / 2] = a % 2;
		a = a >> 1;
		count++;
	}
	printf("奇数列:\n");
	for (count = 15; count >= 0; count--)
		printf("%d", temp1[count]);
	printf("\n偶数列\n");
	for (count = 15; count >= 0; count--)
		printf("%d", temp2[count]);
	return 0;
}
