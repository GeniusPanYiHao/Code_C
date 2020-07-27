#pragma once
#define N 64
typedef unsigned int elemtype;
#include<string>
class Md5
{
public:
	//:位运算函数
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
	//：循环左移函数
	elemtype Leftshift(elemtype number, elemtype shiftnumber)
	{
		return (number << shiftnumber) | (number >> 32 - shiftnumber);
	}
	//:初始化
	void init();
	void reset();

	//：一块chunk的Md5运算
	void calMd5(elemtype *chunk);
	//:进行填充再进行Md5运算
	void calFinalMd5();
	//:转换函数:把一个整形数据转化为对应的16进制字符串。
	std::string changeHex(elemtype n);
	std::string getstringMd5(std::string&str);
	std::string getfileMd5(const char*filePath);
private:
	//：循环左移位数
	static int leftshift[64];
	//：k[i]=floor(2^(32)*abs(sin(i+1))
	elemtype k[64];
	//:数据块
	char chunk[N];
	//:最后一块字节数
	elemtype lastbyte;
	//:总的字节数
	elemtype allbyte;
	//:Md5信息 ABCD
	elemtype a;
	elemtype b;
	elemtype c;
	elemtype d;

};