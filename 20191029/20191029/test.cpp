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
//	TestFunc(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	TestFunc(10); // ����ʱ��ʹ��ָ����ʵ��
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
//}//#include <iostream>//using namespace std;//class HeapOnly//{//public://	static HeapOnly* getHeapOnly()//	{//		return new HeapOnly;//	}//private://	HeapOnly()//	{//		cout << "HeapOnly" << endl;//	}//	//:��������ֻ������ʵ��//	HeapOnly(const  HeapOnly&h);//};//int main()//{//	HeapOnly *pa = HeapOnly::getHeapOnly();//}//:ֻ����ջ�ϴ����������//:��������˽�л�//:�ṩһ�����е�static�ӿڴ�������//#include <iostream>//using namespace std;//class Stackonly//{//public://	Stackonly getStackonly()//	{//		return Stackonly();//	}//private://	Stackonly()//	{//		cout << "Stackonly()" << endl;//	}//};//int main()//{//	Stackonly s = Stackonly::getStackonly();//}//:����ģʽ//:����ģʽ//�����������ڵ�һ��ʹ��֮ǰ�Ѿ�����//1.���캯��˽�л�//2.�ṩһ�����е�static���нӿڷ��ض���//3.����һ��static�����Ա//4��������//#include <iostream>//using namespace std;//class singleton//{//public://	static singleton* getInstance()//	{//		return &_instance;//	}//private://	singleton()//	{//		cout << "singleton()" << endl;//	}//	//:������//	singleton(const singleton& s);//	static singleton _instance;//};//singleton singleton::_instance;//int main()//{//	singleton* ps = singleton::getInstance();//	singleton* ps1 = singleton::getInstance();//	singleton* ps2 = singleton::getInstance();//	singleton* ps3 = singleton::getInstance();//}// ����
// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
// ȱ�㣺����
//1;���캯��˽�л�
//2��������
//3.�ṩ���е�static�ӿڣ��ӿڵ�һ�ε���ʱ��������
//4.����һ��static��ָ��
//5.�̰߳�ȫ��˫���
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class Singleton
{
public:
	static Singleton* getInstance() {
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		//:˫���
		//:�ⲿ��飺���Ч��
		if (nullptr == _pInstance)		{			_mtx.lock();//:����			//:�ڲ���飺��֤�̰߳�ȫ			if (nullptr == _pInstance){				cout << "creat obj" << endl;				_pInstance = new Singleton;			}			_mtx.unlock();		}		return _pInstance;	}private:
	Singleton()	{		cout << "singleton()" << endl;	}	//:������	Singleton(const Singleton &s);	static Singleton*_pInstance;	static mutex _mtx;	//static Garba _gc;};Singleton* Singleton::_pInstance = nullptr;mutex Singleton::_mtx;//Singleton::Garba Singleton::_gc;void fun(int n)
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