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
	cout << "调用A的无参构造函数" << endl;
}
A::A(int i)
{
	a = i;
	cout << "调用A的构造函数" << endl;
}
A::~A()
{
	cout << "调用A的析构函数" << endl;
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
	cout << "调用B的无参构造函数" << endl;
}
B::B(int i,int j):A(i), b(j)
{
	cout << "调用B的构造函数" << endl;
}
B::~B()
{
	cout << "调用B的析构函数" << endl;
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