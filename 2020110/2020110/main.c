#define _CRT_SECURE_NO_WARNINGS 1
//ʵ�ֺ��� ToLowerCase() ���ú�������һ���ַ������� str ���������ַ����еĴ�д��ĸת����Сд��ĸ�� ֮�󷵻��µ��ַ���
#include<stdio.h>
int input(char* str)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (str[i]>= 'A' && str[i]<='Z')
		{
			str[i] = str[i] + 32;
		}
		else
			str[i] = str[i];
		return str[i];
	}
}
int main()
{
	char str = 'ABCD';
	input(str);
	printf("%s",str);
}
