#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int computer(int a, int b, int(*func)(int, int))
{
	return func(a, b);
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int sum(int a, int b)
{
	return a + b;
}
int main()
{
	int a, b, res;
	cout << "ÇëÊäÈë" << endl;
	cin >> a;
	cout << "ÇëÊäÈë" << endl;
	cin >> b;
	res = computer(a, b, &max);
	cout << res << endl;
	res = computer(a, b, &min);
	cout << res << endl;
	res = computer(a, b, &sum);
	cout << res << endl;
}