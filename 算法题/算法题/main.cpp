#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//int singleNumber(int a[],int n)
//{
//	int number = 0;
//	for (int i = 0; i < n; i++)
//	{
//		number = a[i] ^ number;
//	}
//	return number;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int a[10000] = {0};
//	for (int i = 0; i <n; i++)
//	{
//		scanf("%d", &a[i]);
//		getchar();
//	}
//	cout<<singleNumber(a, n) << endl;;
//	return 0;
//}












#include<iostream>
#include<vector>
using namespace std;
int a[400];
int sum[400];
int dp[400][400];
int minmerge(int l, int r)
{
	int min = 1;
	for (int k = l; k < r; ++k)
	{
		min = min < (dp[l][k] + dp[k + 1][r]) ? min:(dp[l][k] + dp[k + 1][r]);
	}
	return min;
}

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			dp[i][i] = 0;
		}
		sum[0] = a[0];
		for (int i = 1; i < n; ++i)
		{
			if (a[i] = sum[i - 1])
			{
				sum[i] = a[i] + sum[i - 1];
			}
		}
		for (int j = 1; j < n; ++j)
		for (int i = 0; i < n - j; ++i)
		{
			if (i) dp[i][i + j] = minmerge(i, i + j) + sum[j + i] - sum[i - 1];
			else dp[i][i + j] = minmerge(i, i + j) + sum[j + i];
		}
		printf("%d\n", dp[0][n - 1]);
	}
	return 0;
}
//void sort(int *a, int n)
//{
//	int c=0;
//	int d = 0;
//	int b[100] = {};
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == a[i + 1])
//		{
//			d = a[i] + 1;
//			b[c] = d;
//			c++;
//			i++;
//			count++;
//		}
//		else
//		{
//			b[c] = a[i];
//			c++;
//		}
//	}
//	for (int d = 0; d < n - count; d++)
//	{
//		cout << b[d] << endl;
//	}
//}
//int main()
//{
//	int a[7] = {4,3,2,2,3};
//	int b[7] = {};
//	int n;
//	scanf("%d", &n);
//	sort(a,n);
//}