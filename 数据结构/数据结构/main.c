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
//	//:检查容量
//	SeqListCheckCapacity(pos);
//	//:移动元素  从前向后
//	size_t end = pos->_size;
//	while (end > 0)
//	{
//		pos->_array[end] = pos->_array[end-1]
//	}
//}
