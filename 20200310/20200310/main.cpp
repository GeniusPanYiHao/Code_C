//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class Clock
//{
//public:
//	Clock(int newH, int newM, int newS)
//		:hour(newH)
//		, minute(newM)
//		, second(newS)
//	{
//		cout << hour << ":" << minute << ":" << second;
//	}
////	Clock(const Clock &d);
////	void ShowTime();
//private:
//	int hour, minute, second;
//};
////Clock::Clock(const Clock &d)
////{
////	hour= d.hour;
////	minute = d.minute;
////	second = d.second;
////	cout << hour << ":" << minute << ":" << second;
////}
//int main()
//{
//	/*Clock d1;
//	Clock d2(d1);*/
//	Clock(8, 30, 30);
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Clock
{
public:
	//:���캯��
	Clock(int newH, int newM, int newS);
private:
	int hour, minute, second;
};
//:���캯��ʵ��
Clock::Clock(int newH, int newM, int newS)
{
	hour = newH;
	minute = newM;
	second = newS;
	cout << hour << ":" << minute << ":" << second;
}
int main()
{
	Clock c(0, 0, 0);//���Զ����ù��캯��
	return 0;
}