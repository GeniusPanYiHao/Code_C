#define _CRT_SECURE_NO_WARNINGS 1
//#include<math.h>
//using namespace std;
//void input(long long l, long long r)
//{
//	long long n = 0;
//	long long s = 0;
//	for (l; l <= r; l++)
//	{
//		s = (l*(1 + l)) / 2;
//		if (s % 3 == 0)
//		{
//			n++;
//		}
//	}
//	cout<<n<<endl;
//}
//int main()
//{
//	int l;
//	scanf("%d", &l);
//	int r;
//	getchar();
//	scanf("%d", &r);
//	input(l, r);
//	return 0;
//}
#include<iostream>
#include <string>
using namespace std;
int main()
{
	int size;
	int a = 0;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		int len;
		cin >> len;
		string str;
		cin >> str;
		for (a; a < len;a++)
		{
			if (str[a] == '.')
			{
				a = a + 2;
				count++;
			}
		}
		cout << count << endl;
	}
}
