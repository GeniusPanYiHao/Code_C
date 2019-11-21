//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	/*ostream& operator<<(ostream& _cout)
//	{
//		_cout <<_year << "-" << _month << "-" << _day;
//		return _cout;
//	}*/
//private:
//	friend ostream operator<<(ostream& _cout, const Date& d);
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout,const Date& d)
//{
//	_cout << d.year << "-" << d.month << "-" <<d.day;
//	return _cout;
//}
//int main()
//{
//	Date d(2019, 11, 21);
//	d << cout;
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//
//	return _cout;
//}
//istream& operator>>(istream& _cin,Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	int d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class F;
	class E
{
		friend class F;
		int _e = 10;
public:
	class G
	{
	public:
		void Display(const E& e)
		{
			cout << e._e << endl;
		}
	};
};
	class F
	{
	public:
		void Display(const E& e)
		{
			cout << e._e << endl;
		}
	};
	int main()
	{
		E e;
		F f;
		f.Display(e);
		E::G g;
		g.Display(e);
		return 0;
	}