#define _CRT_SECURE_NO_WARNINGS 1
int NumberOf1(unsigned int n)
{
	int i;
	int count = 0;
	while (n != 0)
	{
			count++;
		n = n&(n - 1);
	}
	return count;
}
int main()
{
	int n=0;
	printf("%d\n", NumberOf1(-1));
	return 0;
}