#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class UnusualAdd {
public:
	int addAB(int A, int B) {
		if (B == 0)
			return A;
		int sum = A^B;
		int C = (A&B) << 1;
		return addAB(sum, C);
	}
};
int main()
{
	UnusualAdd c;
		cout << c.addAB(8, 2) << endl;
	return 0;
}