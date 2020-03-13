#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
double average1(const vector<double> &arr)
{
	double sum = 0;
	for (unsigned i = 0; i < arr.size; i++)
	{
		sum += arr[i];
		return sum / size;
	}
}
int main()
{
	unsigned n;
	cout << "n="<<endl;
	cin >> n>>endl;
	vector<double>arr[n];//：创建数组对象
	cout << n << endl;
	for (unsigned i = 0; i < arr.size; i++)
	{
		cin >> arr[i];
	}
	cout << average1(arr) << endl;
}