#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A
{
public:
	A();
	A(int i);
	~A();
	void print()const;
private:
	int a;
};
A::A()
{
	a= 0;
	cout << "����A���޲ι��캯��" << endl;
}
A::A(int i)
{
	a = i;
	cout << "����A�Ĺ��캯��" << endl;
}
A::~A()
{
	cout << "����A����������" << endl;
}
void A::print()const
{
	cout << a << endl;
}
class B :public A
{
public:
	B();
	B(int i,int j);
	~B();
	void print()const;
private:
	int b;
};
B::B()
{
	b = 0;
	cout << "����B���޲ι��캯��" << endl;
}
B::B(int i,int j):A(i), b(j)
{
	cout << "����B�Ĺ��캯��" << endl;
}
B::~B()
{
	cout << "����B����������" << endl;
}
void B::print()const
{
	A::print();
	cout <<b<< endl;
}
int main()
{
	B obj(5, 6);
	obj.print();
	return 0;
}