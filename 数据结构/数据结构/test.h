#define N 100
//typedef int DataType;
//typedef struct SeqList
//{
//	DataType array[N]; // 定长数组
//	size_t size; // 有效数据的个数
//}SeqList;
// 基本增删查改接口
#inlcude<stdio.h>
typedef int DateType;

typedef struct SeqList
{
	DateType* _array;//:指针
	size_t _size;//:表示现在实际能存放多少元素
	size_t _capa;//:表示开辟多大的空间
}SeqList;
void SeqListInit(SeqList* sl, size_t capacity);
void SeqListDestory(SeqList* sl);
void CheckCapacity(SeqList* sl);
void SeqListPushBack(SeqList* sl, DateType x);
void SeqListPopBack(SeqList* sl);
void SeqListPushFront(SeqList* psl, DateType x);
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, DateType x);
void SeqListInsert(SeqList* psl, size_t pos, DateType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, DateType x);
void SeqListModify(SeqList* psl, size_t pos, DateType x);
void SeqListPrint(SeqList* psl);
