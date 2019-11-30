#include<iostream>
using namespace std;
int main()
{
	int sum = 0;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	cin >> A >> B >> C >> D;
	int a = (A + C) / 2;
	int b1 = (B + D) / 2;
	int c = (D - B) / 2;
	int b2 = (C - A) / 2;
	if (b1 == b2)
	{
		cout << a << " " << b1 << " " << c;
	}
	else
		printf("NO");
}