#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class UnusualAdd {
public:
	int addAB(int A, int B) {
		cin >> A >> B;
		int C = A | B;
		cout << C;
	}
};
int main()
{
	UnusualAdd addAB();
	return 0;
}