#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"Md5.h"
#include"findfile.hpp"
using namespace std;
void testHex()
{
	Md5 md5;
	elemtype n = 0x23456789;
	cout << md5.changeHex(n) << endl;
}
void teststringMd5()
{
	Md5 md5;
	std::string str = "0123456789abcdef";
	cout << md5.getstringMd5(str) << endl;
}
void testfileMd5()
{
	Md5 md5;
	const char* filePath = "test1.txt";
	const char* filePath1 = "test2.txt";
	cout << md5.getfileMd5(filePath) << endl;
	md5.reset();
	cout << md5.getfileMd5(filePath1) << endl;
}
void testsearch()
{
	string path;
	cout << "ÊäÈë²éÕÒÄ¿Â¼" << endl;
	getline(cin, path);
	unordered_set<string> subfiles;
	searchDir(path, subfiles);
	for (const auto& f : subfiles)
	{
		cout << f << endl;
	}
}
int main()
{
	/*testHex();*/
	/*teststringMd5();*/
	/*testfileMd5();*/
	testsearch();
	return 0;
}