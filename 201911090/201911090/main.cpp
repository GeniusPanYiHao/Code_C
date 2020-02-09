//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include <cstdio>
//using namespace std;
//int main£¨£©
//{
//	int A = 0;
//	cin >> A;
//	if ((A - B + B - C + A + B + B + C) % 2 == 0)
//	{
//		cout << A << B << C;
//	}
//	else
//		cout << "NO";
//}
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	//freopen("1.in","r",stdin);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int x; scanf("%d", &x);
			ans += x;
		}
	}
	cout << ans << endl;
	return 0;
}