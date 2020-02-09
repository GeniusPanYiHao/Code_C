#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _eos(nullptr)
	{}

	void PushBack(const T& val)
	{
		//����
		if (_finish == _eos)
		{
			size_t newC == _start == nullptr ? 1:2 * Capacity();
			Reserve(newC);
		}
		*_finish = val;
		++_finish;
	}
	size_t Capacity()const
	{
		return _eos - _start;
	}
	void Reserve(size_t n)
	{
		int sz = Size();
		if (n > Capacity())
		{
			//:���ռ�
			T* tmp = new T[n];
			//:����
			memcpy(tmp, _start, sizeof(T)*Size());
			//:�ͷ�ԭ�еĿռ�
			delete[] _start;

			_start = tmp;
			_finish = _start + sz;
			_eos = _start + n;
		}
	}
	size_t Size() const
	{
		return _finish - _start;
	}

	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}

	 const T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}
private:
	iterator _start;
	iterator _finish;//:���һ��Ԫ�ص���һ��λ��
	iterator _eos;
};
template<class T>
void PrintVec(const Vector<T>& vec)
{
	for (size_t i = 0; i < vec.Size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void TestVec1()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	PrintVec(v);
}

int main()
{
	TestVec1();
	return 0;
}