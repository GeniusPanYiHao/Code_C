#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
template<typename T>T abs(T x)
{
	return x < 0 ? -x : x;
}
int main()
{
	int a = 5;
	double b = -5.5;
	cout<<abs(a)<<endl;
	cout<<abs(b)<<endl;
}