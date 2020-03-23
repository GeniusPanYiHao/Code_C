#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
struct Matrix2by2
{
	Matrix2by2
	(
	long long m_00,
	long long  m_01,
	long long m_10,
	long long m_11
	)
	:m00(m_00), m01(m_01), m10(m_10), m11(m_11)
	{
	}
	 long long m00;
	long long m01;
	long long m10;
	long long m11;
};
Matrix2by2 MatrixMultiply(const Matrix2by2& matrix1, const Matrix2by2& matrix2)
{
	Matrix2by2 matrix12(1, 1, 1, 0);
	matrix12.m00 = matrix1.m00 * matrix2.m00 + matrix1.m01 * matrix2.m10;
	matrix12.m01 = matrix1.m00 * matrix2.m01 + matrix1.m01 * matrix2.m11;
	matrix12.m10 = matrix1.m10 * matrix2.m00 + matrix1.m11 * matrix2.m10;
	matrix12.m11 = matrix1.m10 * matrix2.m01 + matrix1.m11 * matrix2.m11;
	return matrix12;

}
Matrix2by2 MatrixPower(long long n)
{
	Matrix2by2 matrix(1, 1, 1, 0);
	if (n == 1)
	{
		matrix = Matrix2by2(1, 1, 1, 0);
	}
	else if (n % 2 == 0)
	{
		matrix = MatrixPower(n / 2);
		matrix = MatrixMultiply(matrix, matrix);
	}
	else if (n % 2 == 1)
	{
		matrix = MatrixPower((n - 1) / 2);
		matrix = MatrixMultiply(matrix, matrix);
		matrix = MatrixMultiply(matrix, Matrix2by2(1, 1, 1, 0));
	}
	return matrix;
}
long long Fibonacci(long long n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	Matrix2by2 fibMatrix = MatrixPower(n - 1);
	return fibMatrix.m00;
}

int main()
{
	cout << Fibonacci(92) << endl;
	return 0;
}