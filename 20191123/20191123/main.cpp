#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//int main()
//{
//	//:����ռ�
//	int* p1 = (int*)malloc(sizeof(int)* 4);
//	//:�����ռ䣬�����ɼ�
//	int* p2 = (int*)realloc(p1, sizeof(int)* 1);
//	//:����ռ�+0��ʼ��
//	int* p3 = (int*)calloc(4, sizeof(int));
//	int* p4 = (int*)realloc(p3, sizeof(int)* 1);
//	//:ֻ���ͷ�realloc���صĿռ�
//	//free(p1);
//	free(p2);
//	//free(p3);
//	free(p4);
//}
//struct ListNode
//{
//	ListNode* _next;
//	int _date;
//	//void *_CRTDECL operator new(size_t size)
//	void* operator new(size_t size)
//	{
//		//:�ڴ��
//		void* p = allocator<ListNode>().allocate(1);
//		cout << "mempool allocate ListNode" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//			cout << "mempool deallocate ListNode" << endl;
//	}
//};
//void testListNode()
//{
//	ListNode* ln2 = new ListNode;
//	delete[] ln2;
//}
//int main()
//{
//	testListNode();
//	return 0;
//}

