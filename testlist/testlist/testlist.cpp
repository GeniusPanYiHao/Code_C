#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
using namespace std;
int main()
{
	std::list<int> l1; // 构造空的l1
	std::list<int> l2(4, 100); // l2中放4个值为100的元素
	std::list<int> l3(l2.begin(), l2.end()); // 用l2的[begin(), end()）左闭右开的区间构造l3
	std::list<int> l4(l3); // 用l3拷贝构造l4	// 以数组为迭代器区间构造l5
	int array[] = { 16, 2, 77, 29 };
	std::list<int> l5(array, array + sizeof(array) / sizeof(int));
	// 用迭代器方式打印l5中的元素
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;

	// C++11范围for的方式遍历
	for (auto& e : l5)
		std::cout << e << " ";

	std::cout << endl;
	return 0;
}
