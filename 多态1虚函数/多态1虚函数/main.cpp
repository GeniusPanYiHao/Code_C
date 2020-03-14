//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class base1
//{
//public:
//	virtual ~base1();
//};
//base1::~base1()
//{
//	cout << "base1 destructor" << endl;
//}
//class deverced:public base1
//{
//public:
//	deverced();
//	virtual~deverced();
//private:
//	int *p;
//};
//deverced::deverced()
//{
//	p = new int(0);
//}
//deverced::~deverced()
//{
//	cout << "deverced destructor" << endl;
//	delete p;
//}
//void fun(base1 *b)
//{
//	delete b;
//}
//int main()
//{
//	base1 *b =new deverced();
//	fun(b);
//	return 0;
//}
//:抽象类
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class base1
{
public:
	virtual void display() const=0;//:纯虚函数
};
class base2 :public base1
{
	virtual void display() const;//:覆盖基类函数
};
void base2::display() const
{
	cout << "base2::display()" << endl;
}
class deverced :public base2
{
public:
	virtual void display() const;//:覆盖基类函数
};
void deverced::display()const
{
	cout << "deverced::display()" << endl;
}
void fun(base1* ptr)
{
	ptr->display();
}
int main()
{
	base2 Base;
	deverced Deverced;
	fun(&Base);
	fun(&Deverced);
	return 0;
}