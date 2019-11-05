//
//#include<iostream>
//#include <cstdio>
//#include<algorithm>
//using namespace std;
//const int maxn = 30010;
//int a[maxn];
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int i;
//	for (i = 0; i < 3 * n; i++)
//	{
//		cin >> a[i];
//	}
//		sort(a,a+3*n);
//	int ans = 0;
//	for (i = 0; i<3 * n; i++)
//	{
//		ans += a[n + 2 * i];
//	}
//	cout << ans << endl;
//}
#include <algorithm>
#include<iostream>
using namespace std;
bool compare(int a, int b)
{return a > b; }
int main()
{
	int i;
	int arr[10] = { 2, 4, 1, 23, 5, 76, 0, 43, 24, 65 };
	sort(arr, arr + 10,compare);
	for (i = 0; i<10; i++)
		cout << arr[i] << endl;
	return 0;
}