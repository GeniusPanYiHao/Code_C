//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<math.h>
//using namespace std;
//void Traingle(int T,double a,double b,double c)
//{
//	double p;
//	double s;
//	if ((a + b) > c && (a + c) > b && (b + c)>a)
//	{
//		p = (a + b + c)*1.000 / 2;
//		s = sqrt(p*(p - a)*(p - b)*(p - c));
//		printf("%.3f\n", s);
//	}
//	else
//		printf("%d\n", -1);
//}
//int main()
//{
//	int T;
//	cin >> T;
//	double a, b,c;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> a >> b >> c;
//		Traingle(T, a, b, c);
//		if (i!=T-1)
//		{
//			printf("\n");
//		}
//	}
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
long long fun(long a)
{
	int i;
	for (i = 2; i < a; i++)
	{
		if (a%i == 0)
			return 0;
	}
	return 1;
}
long long fun1(long long n)
{
	long long m = 1;
	int count = 0;
	while (m<n)
	{
		m++;
		if (fun(m)&&n%m==0)
		{
			count++;
		}
		if (count == 2)
			return m;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	cout << fun1(n) << endl;
}

