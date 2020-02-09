#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	string s = "";
	string tables = "0123456789ABCDEF";
	int M = 0;
	int N = 0;
	cin >> M >> N;
	if (M == 0)
	{
		s = "0";
	}
	while (M)
	{
		if (M<0)
		{
			M = -M;
			cout << "-";
		}
		s = tables[M%N] + s;
		M /= N;
	}
	cout << s.c_str() << endl;
	return 0;
}