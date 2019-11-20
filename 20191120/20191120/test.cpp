//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//void ADD(int A)
//{
//	cin >> A;
//	int str[100];
//	int str1[100];
//	for (int i = 0; i <= A / 2; i++)
//	{
//		int a = 2 * i + 1;
//		for (int c =3; c <= a; c++)
//		{
//			if (a%c == 0)
//				break;
//			else
//			{
//				str[i] = a;
//			}
//		}
//	}
//	for (int d = 0; d <= A / 2; d++)
//	{
//		int b = 2 * d + 1;
//		for (int c = 3; c <= b; c++)
//		{
//			if (b%c == 0)
//				break;
//			else
//			{
//				str1[d] = b;
//			}
//		}
//	}
//	for (int i = 0; i <= A / 2; i++)
//	{
//		for (int d = 0; d <= A / 2; d++)
//		{
//			if (A==str[i] + str1[d])
//			{
//				cout << str[i] << str1[d] << endl;
//			}
//		}
//	}
//}
//int main()
//{
//
//	ADD(2);
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
bool Judgement(int A)
{
	for (int i = 2; i <A; i++)
	{
		if (A%i == 0)
		{
			return false;
		}
	}
			return true;
}
int main()
{
	int b;
	cin >> b;
	assert(b >2);
	int j, d, t,m= 0;
	for (j = 2; j <= b / 2; j++)
	{
		if (Judgement(j) && Judgement(b - j))
		{
			d = b - j - j;
			if (m == 0 || m > d)
			{
				m = d;
				t=j;
			}
		}
	}
	cout << t << "\n" << b - t << endl;
}