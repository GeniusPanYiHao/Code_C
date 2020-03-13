#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
class string
{
public:
	string(const char *str = "")//：构造函数
	{
		if (str == nullptr)
		{
			str = "";
		}
		Str = new char[strlen(str) + 1];
		strcpy(Str,str);
	}
	void swap(char *a, char* b)
	{
		char s;
		s = *a;
		*a = *b;
		*b = s;
	}
	//：拷贝构造函数
	string::string(const string &s)
		:Str(new char[strlen(s.Str) + 1])
	{
		strcpy(Str, s.Str);
	}
	//:赋值运算符重载
	string& operator=(const string& s)
	{
		swap(Str, s.Str);
		return *this;
	}
	~string()
	{
		if (Str)
		{
			delete[] Str;
			Str = nullptr;
		}
	}
private:
	char* Str;
};
int main()
{
	return 0;
}