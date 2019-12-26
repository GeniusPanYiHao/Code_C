#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;
void Delete(char* a, char* b, int len1, int len2)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	char* p = a;
	for (i = 0; i<len2; ++i)
	{
		tmp = b[i];
		for (j = 0; j<len1&&a[j] != '\0'; j++)
		{
			if (tmp == a[j])
			{
				int c = j;
				for (c; c<len1&&a[c] != '\0'; ++c)
				{
					a[c] = a[c + 1];
				}
			}
		}
	}
	cout << p << endl;
}
int main()
{
	char a[] = "They are students";
	int len1 = strlen(a);
	for (int n = 0; n<len1; n++)
	{
		cin >> a[n];
	}
	char b[] = "aeiou";
	int len2 = strlen(b);
	for (int d = 0; d<len2; d++)
	{
		cin >> b[d];
	}
	Delete(a, b, len1, len2);
	system("pause");
	return 0;
}