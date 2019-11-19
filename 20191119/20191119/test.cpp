//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Testop{
//public:
//	int m_a;
//	int m_b;
//	Testop() :
//		m_a(0),
//		m_b(0)
//	{
//
//	}
//	Testop(int a, int b) :
//		m_a(a),
//		m_b(b)
//	{
//
//	}
//
//	Testop operator+(const Testop &s)const
//	{
//		Testop res;
//		res.m_a = m_a + s.m_a;
//		res.m_b = m_b + s.m_b;
//
//		return res;
//	}
//	Testop & operator = (const Testop &s)
//	{
//		m_a = s.m_a;
//		m_b = s.m_b;
//
//		return *this;
//	}
//};
//
//int main()
//{
//	Testop a(3, 5);
//	Testop b(2, 7);
//
//	Testop c;
//	Testop d;
//	d = c = a + b;
//	cout << d.m_a << ' ' << d.m_b << endl;
//
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class TestSt
{
public:
	static int m_s_i;
};

int TestSt::m_s_i = 0;
int main()
{
	TestSt t1;

	cout << t1.m_s_i << endl;


	return 0;
}