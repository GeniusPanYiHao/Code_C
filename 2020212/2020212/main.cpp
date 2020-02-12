//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//void Delete(char* src, char* dec)
//{
//	if (!src || !dec)
//	{
//		return;
//	}
//	char* p1;
//	char* A = src;
//	char* p2;
//	for (p2 = dec; *p2; p2++, A = src)
//	{
//		while (*A)
//		{
//			if (*A != *p2)
//			{
//				A++;
//			}
//			else
//			{
//				break;
//			}
//		}
//		if (*A)
//		{
//			for (p1 = A++; *A; p1++, A++)
//			{
//				while (*A == *p2)
//				{
//					A++;
//				}
//				*p1 = *A;
//			}
//			*p1 = '\0';
//		}
//	}
//}
//int main()
//{
//	char* src;
//	char* dec;
//	printf("«Î ‰»Î£∫");
//	scanf("%s", &src);
//	printf("«Î ‰»Î£∫");
//	scanf("%s", &dec);
//	Delete(src, dec);
//	printf("%s", src);
//}

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.size(); i++)
	{
		int index;
		while ((index = s1.find(s2[i])) != -1)
		{
			s1.erase(index, 1);
		}
	}
	cout << s1 << endl;
	return 0;
}