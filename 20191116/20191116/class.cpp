#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A3{
	int a=5;

public:
	void change(int i)
	{
		i = a;
	}
};
int main()
{
	A3 c;
	c.change(3);
	printf("%d", c);
}