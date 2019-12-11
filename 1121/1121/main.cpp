#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int fun(int N, int M)
{
	int C = M%N;
	int D = M - N;
	int E = 0;
	while (1)
	{
		if (M%N != 0)
		{
			M = N;
			N = C;
		}
		else
			E== D / N;
		return E;
	}
}
 int main()
 {
	 int M, N;
	 scanf("%d %d", &N, &M);
	 cout << fun(N, M) << endl;
	 return 0;
 }