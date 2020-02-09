#define N 100
//typedef int DataType;
//typedef struct SeqList
//{
//	DataType array[N]; // ��������
//	size_t size; // ��Ч���ݵĸ���
//}SeqList;
// ������ɾ��Ľӿ�
#inlcude<stdio.h>
typedef int DateType;

typedef struct SeqList
{
	DateType* _array;//:ָ��
	size_t _size;//:��ʾ����ʵ���ܴ�Ŷ���Ԫ��
	size_t _capa;//:��ʾ���ٶ��Ŀռ�
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
