#include<iostream>
using namespace std;
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		if(n % 2 != 0)
			return false;
		int count = 0;
		int i = 0;
		for (i; i<n; i++)
		{
			if (A[i] == '(')
			{
				count++;
			}
			else if (A[i] == ')')
			{
				count--;
			}
		}
		if (count == 0)
			return true;
		else
			return false;
	}
};
int main()
{
	Parenthesis p;
	cout << p.chkParenthesis("()()()", 6);
	return 0;
}
