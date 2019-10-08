//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
void reverve_swap(char *left, char *right)
{
    assert(left != NULL);
    assert(right != NULL);
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}
char *reverve(char *p)
{
	int len = strlen(p);
	char *start = p;
	char *end = NULL;
	char *ret = p;
	reverve_swap(p, p + len - 1);
	while (*p)
	{
		start = p;
		while ((*p != ' ') && (*p != '\0'))
		{
			p++;
		}
		end = p - 1;
		reverve_swap(start, end);
		if (*p == ' ')
			p++;
	}
	return ret;
}
int main()
{
    char arr[] = "韩帅  是  傻逼";
    printf("%s\n", reverve(arr));
    system("pause");
    return 0;
}