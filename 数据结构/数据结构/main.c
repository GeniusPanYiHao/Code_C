#include"test.h"
#include<stdio.h>
void SeqListInit(SeqList sl)
{
	sl._array = NULL;
	sl._size = 0;
	sl._capacity = 0;
}
//void SListInsertAfter(SeqList* pos, SLDataType x)
//{
//	assert(pos);
//	//:�������
//	SeqListCheckCapacity(pos);
//	//:�ƶ�Ԫ��  ��ǰ���
//	size_t end = pos->_size;
//	while (end > 0)
//	{
//		pos->_array[end] = pos->_array[end-1]
//	}
//}
