#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int divided(int x, int y)
{
	if (y == 0)
		throw x;
	return x / y;
}
int main()
{
	try{
		cout << "5/2=" << divided(5, 2) << endl;
		cout << "8/0=" << divided(8, 0) << endl;
		cout << "6/2=" << divided(6, 2) << endl;
	}
	catch (int e)
	{
		cout << e << "is dibided by zero" << endl;
	}
	return 0;
}