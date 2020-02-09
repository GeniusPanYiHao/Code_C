#define _CRT_SECURE_NO_WARNINGS 1
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};int operator-(const Date& d);bool operator>(const Date&d)const{	if (_year > d._year)		return true;	if (year == d.year)	{		if (month > d.month)			return true;		else if (month == d.month)		{		}	}}