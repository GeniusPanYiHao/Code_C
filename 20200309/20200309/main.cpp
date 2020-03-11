#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Clock
{
public:
	Clock(int newH = 1, int newM = 2, int newS = 3)
	{
		hour = newH;
		minute = newM;
		second = newS;
		cout << hour << ":" << minute << ":" << second;
	}
	Clock(const Clock &d);
	void ShowTime();
private:
	int hour, minute, second;
};
//Clock(const Clock &SetTime);
Clock::Clock(const Clock &S)
{
	hour = S.hour;
	minute =S.minute;
	second =S.second;
	cout << hour << ":" << minute << ":" << second;
}
//void Clock::SetTime(int newH, int newM, int newS)
//{
//	hour = newH;
//	minute = newM;
//	second = newS;
//}
void Clock::ShowTime()
{
	cout<< hour << ":" << minute << ":" << second;
}
int main()
{
	/*Clock myclock;
	myclock.SetTime(8,30,30);
	myclock.ShowTime();*/
	Clock d1;
	Clock d2(d1);
	return 0;
}