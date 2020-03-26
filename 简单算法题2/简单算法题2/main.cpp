#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void input1(int n,int a[])
{
	int count = 0;
	if (n<10)
	{
		a[count++] = n%10;
	}
	else
	{
		a[count++] = n / 10;
		input1(n / 10, a);
	}
}
int main()
{
	int a[1000];
	input1(12345, a);
	for (int j = 0; j < 6; j++)
	{
		cout << a[j] << endl;
	}
}
void input(int S,int T)
{
	int i = 0;
	int b = S;
	int count1 = 1;
	int a[100000];
	int c[100000];
	for (i = S; i <= T; i++)
	{
		a[i] = b;
		b++;
	}
	for (int i = S; i <= T; i++)
	{
		while ((a[i] / 10) != 0)
		{
			count1++;
		}
		if (a[i] % 10 == 0)
		{
			count1 = 1;
		}
		c[count1] = input1(a[i]);
	}
	for (i = 0; i < count1; i++)
	{
		cout << c[i] << endl;
	}
}
int input(int S, int T)
{
	int i = 0;
	int j = 0;
	int b = S;
	int count = 0;
	int count1 = 1;
	int c[100000000];
	int a[100000000];
	for (i= S; i <= T; i++)
	{
		a[i] = b;
		b++;
	}
	for (int i = S; i <= T; i++)
	{
		/*while ((a[i] / 10) != 0)
		{
			count1++;
		}
		if (a[i] % 10 == 0)
		{
			count1 = 1;
		}*/
		c[count1] = input1(a[i]);
		for (int i = 0; i < count1 -2; i++)
		{
			if (c[i] == 6 &&c[i + 1] == 6 && c[i + 2] == 6)
				count++;
		}
	}
	return count;
}
int main()
{
	int n1;
	scanf("%d", &n1);
	getchar();
	int n2;
	scanf("%d", &n2);
	getchar();
	input(n1, n2);

}