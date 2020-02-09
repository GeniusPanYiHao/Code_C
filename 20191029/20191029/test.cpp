//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//namespace N
//{
//	int a = 1;
//	int b = 2;
//	int ADD(int right, int left)
//	{
//		return left + right;
//	}
//		int Sub(int right, int left)
//		{
//			return left - right;
//		}
//}
//using namespace N;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	printf("%d\n", ADD(10, 20));
//	printf("%d\n", Sub(10, 20));
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "Hello Word!!!";
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a;
//	double b;
//	char c;
//
//	cin >> a;
//	cin >> b >> c;
//
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//void TestFunc(int a = 0)
//{
//	cout << a;
//}
//int main()
//{
//	TestFunc(); // 没有传参时，使用参数的默认值
//	TestFunc(10); // 传参时，使用指定的实参
//}//#include <iostream>
//using namespace std;//void TestFunc(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}//int main()//{//	TestFunc(10,20,30);//}//#include <iostream>
//using namespace std;//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}//#include <iostream>//using namespace std;//class HeapOnly//{//public://	static HeapOnly* getHeapOnly()//	{//		return new HeapOnly;//	}//private://	HeapOnly()//	{//		cout << "HeapOnly" << endl;//	}//	//:防拷贝，只声明不实现//	HeapOnly(const  HeapOnly&h);//};//int main()//{//	HeapOnly *pa = HeapOnly::getHeapOnly();//}//:只能在栈上创建对象的类//:构建函数私有化//:提供一个公有的static接口创建对象//#include <iostream>//using namespace std;//class Stackonly//{//public://	Stackonly getStackonly()//	{//		return Stackonly();//	}//private://	Stackonly()//	{//		cout << "Stackonly()" << endl;//	}//};//int main()//{//	Stackonly s = Stackonly::getStackonly();//}//:单例模式//:饿汉模式//饿汉：对象在第一次使用之前已经存在//1.构造函数私有化//2.提供一个公有的static公有接口返回对象//3.定义一个static自身成员//4。防拷贝//#include <iostream>//using namespace std;//class singleton//{//public://	static singleton* getInstance()//	{//		return &_instance;//	}//private://	singleton()//	{//		cout << "singleton()" << endl;//	}//	//:防拷贝//	singleton(const singleton& s);//	static singleton _instance;//};//singleton singleton::_instance;//int main()//{//	singleton* ps = singleton::getInstance();//	singleton* ps1 = singleton::getInstance();//	singleton* ps2 = singleton::getInstance();//	singleton* ps3 = singleton::getInstance();//}// 懒汉
// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
// 缺点：复杂
//1;构造函数私有化
//2：防拷贝
//3.提供公有的static接口，接口第一次调用时创建对象
//4.定义一个static的指针
//5.线程安全：双检查
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class Singleton
{
public:
	static Singleton* getInstance() {
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		//:双检查
		//:外部检查：提高效率
		if (nullptr == _pInstance)		{			_mtx.lock();//:加锁			//:内部检查：保证线程安全			if (nullptr == _pInstance){				cout << "creat obj" << endl;				_pInstance = new Singleton;			}			_mtx.unlock();		}		return _pInstance;	}private:
	Singleton()	{		cout << "singleton()" << endl;	}	//:防拷贝	Singleton(const Singleton &s);	static Singleton*_pInstance;	static mutex _mtx;	//static Garba _gc;};Singleton* Singleton::_pInstance = nullptr;mutex Singleton::_mtx;//Singleton::Garba Singleton::_gc;void fun(int n)
{
	for (int i = 0; i < n; ++i)
	{
		Singleton* ps = Singleton::getInstance();
	}
}



//int main()
//{
//	/*Singleton* ps = Singleton::getInstance();
//	Singleton* ps1 = Singleton::getInstance();
//	Singleton* ps2 = Singleton::getInstance();
//	Singleton* ps3 = Singleton::getInstance();*/
//
//	int n;
//	cin >> n;
//	thread t1(fun, n);
//	thread t2(fun, n);
//	thread t3(fun, n);
//	thread t4(fun, n);
//
//	t1.join();
//	t2.join();
//	t3.join();
//	t4.join();
//	/*fun(n);
//	fun(n);*/
//	return 0;
//}

int main()
{
	/*char* pc = new char[0xffffffff];
	cout << (int*)pc << endl;*/
	return 0;
}