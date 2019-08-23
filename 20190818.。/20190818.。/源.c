//求出0～999之间的所有“水仙花数”并输出。
//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。
//
///*
//在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），是指一N位数，其各个数之N次方和等于该数。
//例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
//153 = 1^3 + 5^3 + 3^3。
//370 = 3^3 + 7^3 + 0^3。
//371 = 3^3 + 7^3 + 1^3。
//407 = 4^3 + 0^3 + 7^3。
//*/
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

