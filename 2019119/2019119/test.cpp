#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	char arr[3];
	int sum = 0;
	int A = 0;
	int B = 0;
	int C = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum % 2 == 0)
	{
		A = sum / 2;
		B = sum / 2;
		C = sum - A-B;
	}
	if (sum % 2 != 0);
	{
		printf("NO");
	}
	cout << A << B << C;
	return 0;
}