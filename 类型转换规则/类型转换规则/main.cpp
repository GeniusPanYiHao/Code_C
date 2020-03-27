#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class base1//：基类base1定义
{
public:
	void display()const
	{
		cout << "base1::display()" << endl;
	}
};
class base2:public base1//:公有派生类base2定义
{
public:
	void display()const
	{
		cout << "base2::display()" << endl;
	}
};
class deverce :public base2//:公有派生类deverce定义
{
public:
	void display()const
	{
		cout << "deverce::display()" << endl;
	}
};
void fun(base1 *ptr)
{
	ptr->display();
}
int main()
{
	base1 a;
	base2 b;
	deverce c;
	fun(&a);
	fun(&b);
	fun(&c);
	return 0;
}