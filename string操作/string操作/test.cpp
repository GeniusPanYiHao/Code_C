#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
string input(string str)
{
	size_t pos = str.find(".");
	return str.substr(pos+1);
}
int main()
{
	string str;
	getline(cin, str);
	input(str);
	cout << input(str) << endl;
}
