#pragma once
#define N 64
typedef unsigned int elemtype;
#include<string>
class Md5
{
public:
	//:λ���㺯��
	/*
	F(x,y,z) = (x & y) | ((~x) & z)
	G(x,y,z) = (x & z) | ( y & (~z))
	H(x,y,z) = x ^ y ^ z
	I(x,y,z) = y ^ (x | (~z))
	*/
	Md5();
	elemtype F(elemtype b, elemtype c, elemtype d)
	{
		return (b&c)| ((~b)&d);
	}
	elemtype G(elemtype b, elemtype c, elemtype d)
	{
		return(b&d) | (c&(~d));
	}
	elemtype H(elemtype b, elemtype c, elemtype d)
	{
		return b^c^d;
	}
	elemtype I(elemtype b, elemtype c, elemtype d)
	{
		return c ^ (b | (~d));
	}
	//��ѭ�����ƺ���
	elemtype Leftshift(elemtype number, elemtype shiftnumber)
	{
		return (number << shiftnumber) | (number >> 32 - shiftnumber);
	}
	//:��ʼ��
	void init();
	void reset();

	//��һ��chunk��Md5����
	void calMd5(elemtype *chunk);
	//:��������ٽ���Md5����
	void calFinalMd5();
	//:ת������:��һ����������ת��Ϊ��Ӧ��16�����ַ�����
	std::string changeHex(elemtype n);
	std::string getstringMd5(std::string&str);
	std::string getfileMd5(const char*filePath);
private:
	//��ѭ������λ��
	static int leftshift[64];
	//��k[i]=floor(2^(32)*abs(sin(i+1))
	elemtype k[64];
	//:���ݿ�
	char chunk[N];
	//:���һ���ֽ���
	elemtype lastbyte;
	//:�ܵ��ֽ���
	elemtype allbyte;
	//:Md5��Ϣ ABCD
	elemtype a;
	elemtype b;
	elemtype c;
	elemtype d;

};