#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Clock
{
public:
	void SetTime(int newH = 0, int newM = 0, int newS = 0);
	void ShowTime();
private:
	int hour, minute, second;
};
void Clock::SetTime(int newH, int newM, int newS)
{
	hour = newH;
	minute = newM;
	second = newS;
}
void Clock::ShowTime()
{
	cout<< hour << ":" << minute << ":" << second;
}
int main()
{
	Clock myclock;
	myclock.SetTime(8,30,30);
	myclock.ShowTime();
	return 0;
}