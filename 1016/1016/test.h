#define _CRT_SECURE_NO_WARNINGS 1
// 顺序表的静态存储
#define N 100
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType array[N]; // 定长数组
	size_t size; // 有效数据的个数
}SeqList;
void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);
void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);