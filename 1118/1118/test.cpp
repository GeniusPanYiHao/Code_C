#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void fun()
{
	int count = 0;
	int a[100];
	int i = 0;
	int A;
	cin >> A;
	while (A != 0);
	{
		a[i] = A % 2;
		A = A / 2;
		i++;
	}
	for (i = i-1; i>=0; i--)
	{
		int sum = a[i] ^ 1;
		if (sum == 0)
		{
			count++;
		}
	}
	cout << count << endl;
}
int main()
{
	fun();
	return 0;
}