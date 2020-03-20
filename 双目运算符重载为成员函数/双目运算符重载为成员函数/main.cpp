#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class complex
{
public:
	complex(double r=0.0, double i=0.0) :real(r), imag(i){}
	complex operator+(const complex &c2)const;
	complex operator-(const complex &c2)const;
	void display()const;
private:
	double real;
	double imag;
};
complex complex::operator+(const complex &c2)const
{
	return complex(real + c2.real, imag + c2.imag);
}
complex complex::operator-(const complex &c2)const
{
	return complex(real - c2.real, imag - c2.imag);
}
void complex::display()const
{
	cout << "(" << real << "," << imag << ")" << endl;
}
int main()
{
	complex c1(5, 4), c2(2, 10), c3;
	cout << "c1="; c1.display();
	cout << "c2="; c2.display();
	c3 = c1 - c2;//:使用重载运算符完成复数减法
	cout << "c3=c1-c2"; c3.display();
	c3 = c1 + c2;//:使用重载运算符完成复数减法
	cout << "c3=c1+c2"; c3.display();
	return 0;
}