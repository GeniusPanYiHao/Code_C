//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//const my_strstr(const char* str, const char*sub_str)
//{
//	int i;
//	for (i = 0; str[i] != '\0'; i++)
//	{
//		int tem = i;
//		int j = 0;
//		while (str[i++] == sub_str[j++])
//		{
//			if (sub_str[j] == '\0')
//			{
//				return &str[tem];
//			}
//		}
//		i = tem;
//	}
//}
//int main()
//{
//	char* s = "12345678abc";
//	char* t = "6";
//	printf("%s", my_strstr(s, t));
//	return 0;
//}



//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int digitsum(int n)
{
	int sum = 0;
	while (n >=10)
	{
		sum += n % 10;
		printf("%d", sum);
	}
}
int main()
{
	digitsum(1729);
	return 0;
}