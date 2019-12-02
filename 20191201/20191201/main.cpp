#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;
void one(string str)
{
	char arr[256] = { 0 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	int length = str.length();
	for (i = 0; i<len; i++)
	{
		arr[i] = 1; 
	}
	for (i = 0; i<length; i++)
	{
		if (arr[str[i]] == 1)
		{
			cout << str[i];
			arr[str[i]] = 0;
		}
	}
	cout << endl;
}
int main()
{
	string str;
	while (cin>>str)
	{
		one(str);
	}
	return 0;
}