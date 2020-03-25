#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void input(int n, int m)
{
	int a = 0;
	int first =-m;
	int second= 0;
	while (first < n&&second < n)
	{
		first = first + 2*m;
		if (first < n)
		{
			second = first + m;
		}
	}
	if (first >= n)
		cout << "first" << endl;
	if (second >= n)
		cout<<"second"<<endl;
}
int main()
{
	int N;
	int n;
	int m;
	int i = 1;
	scanf("%d", &N);
	getchar();
	while (i <= N)
	{
		scanf("%d%d",&n,&m);
		getchar();
		i++;
		input(n, m);
	}
	return 0;
}