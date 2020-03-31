#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
long long input(long long n)
{
	if (n < 2)
		return n;
	long long pre1 = 1;
	long long pre2 = 1;
	long long pre3 = 2;
	long long cur = 0;
	for (int i = 4; i <= n; i++)
	{
		cur = pre1 + pre3;
		pre1 = pre2;
		pre2 = pre3;
		pre3 = cur;
	}
	return pre3;
}
int main()
{
	int n;
	scanf("%d", &n);
	cout<<input(n)<<endl;
}