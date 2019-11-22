//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cmath>
//#include<vector>
//#include<algorithm>
//using namespace std;
//void QiuYueshu(int n, vector<int>&yueshu);
//int main(){
//	int N, M;
//	cin >> N >> M;
//	vector<int> res(M + 1, 0);
//	res[N] = 1;
//		for (int i = N; i <= M; i++)
//		{
//			vector<int>yueshu;
//			if (res[i] == 0)
//			{
//				continue;
//				QiuYueshu(i, yueshu);
//			}
//			for (int j = 0; j < yueshu.size(); j++)
//			{
//				if ((yueshu[j] + i) <= M)
//				{
//					if (res[yueshu[j] + i] == 0)
//						res[yueshu[j] + i] = res[i] + 1;
//					else
//						res[yueshu[j] + i] = (res[i] + 1) < res[yueshu[j] + i] ? (res[i] + 1) : res[yueshu[j] + i];
//				}
//				}
//			}
//		if (res[M] == 0)
//			cout<< -1;
//		else
//			cout<< res[M] - 1;
//	}
//		void QiuYueshu(int n, vector<int>&yueshu){
//			for (int i = 2; i <= sqrt(n); i++)
//			{
//				if (n%i == 0)
//					yueshu.push_back(i);
//					if (n / i != i)
//						yueshu.push_back(i);
//			}
//		}

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void calYueshu(int n, vector<int> &yueshu);
int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> steps(M + 1, 0);
	steps[N] = 1;

	for (int i = N; i <= M; ++i){
		if (steps[i] == 0)continue;  
		vector<int> yueshu;
		calYueshu(i, yueshu);
		for (int j = 0; j<yueshu.size(); ++j){  
			if (yueshu[j] + i <= M){
				if (steps[yueshu[j] + i] == 0)    
					steps[yueshu[j] + i] = steps[i] + 1;
				else                         
					steps[yueshu[j] + i] = (steps[i] + 1)<steps[yueshu[j] + i] ? (steps[i] + 1) : steps[yueshu[j] + i];
			}
		}
	}

	if (steps[M] == 0)
		cout << -1 << endl;
	else
		cout << steps[M] - 1 << endl;
	return 0;
}
void calYueshu(int n, vector<int> &yueshu){
	for (int i = 2; i <= sqrt(n); ++i){
		if (n%i == 0){
			yueshu.push_back(i);
			if (n / i != i)
				yueshu.push_back(n / i);
		}
	}
}