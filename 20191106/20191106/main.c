//Fibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N��
//���������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int f1 = 0, f2 = 1, f3 = f1 + f2;
	while (1)
	{
		if (n == f2)
		{
			printf("%d",0);
			break;
		}
		else if (f2 > n)
		{
			if (abs(f2 - n) > abs(f1 - n))
			{
				printf("%d", abs(f1 - n));
			}
			else
			{
				printf("%d", abs(f2 - n));
			}
			break;
		}
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}
	return 0;
}
