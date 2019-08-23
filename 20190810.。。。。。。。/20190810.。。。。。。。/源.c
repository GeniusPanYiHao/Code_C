#include<stdio.h>
#include<assert.h>
int my_strlen(const char *p)
{
	assert(p != NULL);
	if (*p == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + my_strlen(p + 1);
	}
}
int main()
{
	char *p = "abcdefg";
	int ret = my_strlen(p);
	printf("%d\n", ret);
	return 0;
}






