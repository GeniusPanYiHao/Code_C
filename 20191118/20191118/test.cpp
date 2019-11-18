#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Testop
{
public:
	int m_a;
	int m_b;
	Testop() :
		m_a(0),
		m_b(0)
	{

	}
	Testop(int a, int b) :
		m_a(a),
		m_b(b)
	{

	}

	Testop operator+(const Testop &s) const//:this²»ÄÜ±ä
	{
		Testop res;
		res.m_a = m_a + s.m_a;
		res.m_b = m_b + s.m_b;

		return res;
	}
};

int main()
{
	Testop a(3, 5);
	Testop b(2, 7);
	a.operator+(b);
	Testop c = a + b;

	cout << c.m_a <<"\n" << c.m_b << endl;

	return 0;
}