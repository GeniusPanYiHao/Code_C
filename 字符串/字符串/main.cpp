//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<math.h>
//using namespace std;
//void Fib(int n)
//{
//	int arr[100000] = { 0, 1, 1 };
//	int i = 2;
//	while (arr[i] <= n)
//	{
//		arr[i+1] = arr[i] + arr[i - 1];
//		i++;
//	}
//	int j = i-1;
//	cout << arr[j] << endl;
//}
//int main()
//{
//	long long n = pow(2, 32) - 1;
//	Fib(100000000000);
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<math.h>
using namespace std;
long long Fib(long long n)
{
	long long f1 = 0;
	long long f2 = 1;
	long long f3 = 1;
	while (f2 <= n)
	{
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}
	return f1;
}
int main()
{
	cout << Fib(10000000000000) << endl;
	return 0;
}


