#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
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
	printf("%s", p);
}
int main()
{
	char* str1[20];
	cin.get(str1, 20);
	int len1 = strlen(str1);
	char* str2[20];
	cin.get(str2, 20)
		int len2 = strlen(str2);
	Delete(str1, str2, len1, len2);
	system("pause");
	return 0;
}