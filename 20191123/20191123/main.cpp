#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//int main()
//{
//	//:申请空间
//	int* p1 = (int*)malloc(sizeof(int)* 4);
//	//:调整空间，可扩可减
//	int* p2 = (int*)realloc(p1, sizeof(int)* 1);
//	//:申请空间+0初始化
//	int* p3 = (int*)calloc(4, sizeof(int));
//	int* p4 = (int*)realloc(p3, sizeof(int)* 1);
//	//:只需释放realloc返回的空间
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
//		//:内存池
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

