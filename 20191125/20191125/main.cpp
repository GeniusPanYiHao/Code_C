#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
////:只能在堆上创建对象的类
////：1.构造函数私有化
////:2.提供一个共有的static接口创建对象的对象
////:3.防拷贝
//class HeapOnly
//{
//public:
//	static HeapOnly* getHeapOnly()
//	{
//		/*HeapOnly *ph = new HeapOnly;
//		copy:栈上
//		HeapOnly copy(*ph);*/
//		return new HeapOnly;
//	}
//	
//private:
//	HeapOnly()
//	{
//		cout << "HeapOnly()" << endl;
//	}
//	HeapOnly(const HeapOnly& h);
////:防拷贝：只声明不实现
//	//:
//};
////A ga;
//int main()
//{
//	//A a;
//	HeapOnly* pa = HeapOnly::getHeapOnly();
//	//:copy:栈上
////	HeapOnly copy(*pa);
//	return 0;
//}

//只能在栈上创建对象的类
//1:构造函数私有化
//2.提供一个共有的static接口创建对象
//class StackOnly
//{
//public:
//	static StackOnly getStackOnly()
//	{
//		return StackOnly();
//	}
//
//private:
//	StackOnly()
//	{
//		cout << "StackOnly()" << endl;
//	}
//};
//
//int main()
//{
//	//StackOnly* ps = new StackOnly;
//	StackOnly s = StackOnly::getStackOnly();
//}




//懒汉:对象第一次使用时创建
//1.构造函数私有
//2.防拷贝
//3.提供公有的static接口，接口第一次调用时创建对象
//4.定义一个static指针
//5.线程安全：双检查
#include<mutex>
#include<thread>
class singleton
{
public:
	static singleton* getInstance()
	{
		//双检查
		//外部检查：提高效率
		if (_pInstance == nullptr)
		{
			_mtx.lock;
			//内部检查，保证线程安全
			if (_pInstance == nullptr)
			{
				_pInstance = new singleton;
			}
			_mtx.unlock;
		}
		return _pInstance;

	}
private:
	singleton()
	{
		cout << "singleton" << endl;
	}
	//：防拷贝
	singleton(const singleton* s);
	static singleton* _pInstance;
	static mutex _mtx;
};

singleton* singleton::_pInstance = nullptr;
mutex singleton::_mtx;


int main()
{
	singleton* ps = singleton::getInstance();
	singleton* ps1 = singleton::getInstance();
	singleton* ps2 = singleton::getInstance();
	singleton* ps3 = singleton::getInstance();
	return 0;
}




