#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int fun()
{
	int A;
	cin >> A;
	int max = 0;
	while (A)
	{
		int count = 0;
		while (A &1 ==1 )
		{
			count++;
			A = A >> 1;
		}
		max = count > max ? count : max;
		A = A >> 1;
	}
	return max;
}
int main()
{
	int MAX = fun();
	cout << MAX << endl; 
	return 0;
}
	