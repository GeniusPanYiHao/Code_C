#define _CRT_SECURE_NO_WARNINGS 1
#include<array>
#include<iostream>
using namespace std;

//#define N 100
//template<class T,size_t N>
//class array
//{
//private:
//	T _arr[N];
//};
//void testArray()
//{
//	array<int, 100>  arr;
//	array<int, 20> arr2;
//	array<int, 10000> arr3;
//}
//template <class T>
//bool isBig(T& a, T& b)
//{
//	return a > b;
////}
////
//template<>
//bool isBig<char*>(char* &a, char* &b)
//{
//	return strcmp(a, b) > 0;
//}
//
//void testString()
//{
//	char* str1 = "123";
//	char* str2 = "456";
//	bool ret = isBig(str1, str2);
//	int a = 1;
//	int b = 2;
//	ret = isBig(a, b);
//}
//int main()
//{
//	testArray();
//	return 0;
//}
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; };
private:
	int _d1;
	int _d2;
};
void TestVector()
{
	Data<int, int> d1;
	Data<int, char> d2;
}





















