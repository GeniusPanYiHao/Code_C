template<calss T,size_t bufferLen=20>
struct DequeIterator
{
	T& operator*()
	{
		return *cur;
	}
	DequeIterator<T>& operator++()
	{
		++cur;
		if (cur == last)
		{
			++node;
			cur = *node;
			first = cur;
			last = first + bufferLen;
		}
		return *this;
	}

	T* cur;//��ǰԪ��λ��
	T* first;//buffer���׵�ַ
	T* last;//bufferĩβ
	T** node;//ָ��map��һ��λ��
};

template<class T>
class Deque
{
	public��
	typedef DequeIterator<T> iterator;
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return finish;
	}
private:
	//�п�
	T** map;
	iterator _start;
	iterator _finish;

};
//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		//��ջ�ͳ�ջ��Ԫ�ظ���������ͬ
//		if (pushV.size() != popV.size())
//			return false;
//
//		// ��s��ģ����ջ���ջ�Ĺ���
//		int outIdx = 0;
//		int inIdx = 0;
//		stack<int> s;
//
//		while (outIdx < popV.size())
//		{
//			// ���s�ǿգ�����ջ��Ԫ�����ջ��Ԫ�ز���ȣ�����ջ
//			while (s.empty() || s.top() != popV[outIdx])
//			{
//				if (inIdx < pushV.size())
//					s.push(pushV[inIdx++]);
//				else
//					return false;
//			}
//
//			// ջ��Ԫ�����ջ��Ԫ����ȣ���ջ
//			s.pop();
//			outIdx++;
//		}
//
//		return true;
//	}
//};