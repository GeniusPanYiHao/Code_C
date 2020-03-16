#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class clock
{
public:
	clock(int hour, int minute, int second);
	void showtime()const;
	clock& operator ++();//:前置单目运算符重载
	clock operator ++(int);//:后置单目运算符重载
private:
	int hour;
	int minute;
	int second;
};
clock::clock(int hour, int minute, int second)
{
	if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
	else
		printf("time error");
}
void clock::showtime()const
{
	cout << hour << ":" << minute << ":" << second << endl;
}
clock & clock:: operator ++()
{
	if (second >= 60)
	{
		second -= 60;
		minute++;
		if (minute >= 60)
		{
			minute -= 60;
			hour = (hour + 1) % 24;
		}
	}
	return *this;
}
clock clock::operator ++(int)
{
	clock old = *this;
	++(*this);
	return old;
}
int main()
{
	clock myclock(23, 59,59);
	cout << "the first time:" << endl;
	myclock.showtime();
	cout << "show myclock++:" << endl;
	(myclock++).showtime();
	cout << "show ++myclock:" << endl;
	(++myclock).showtime();
	return 0;
}