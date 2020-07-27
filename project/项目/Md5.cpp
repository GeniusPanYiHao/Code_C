#pragma once
#include"Md5.h"
#include<math.h>
#include<iostream>
#include<fstream>
//:初始化static成员
int Md5::leftshift[] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };
Md5::Md5()
{
	init();
}
//:初始化
void Md5::init()
{
	for (int i = 0; i < 64; i++)
	{
		k[i] = static_cast<elemtype>(abs(sin(i + 1.0)*pow(2.0, 32)));
	}
	reset();
}
//:初始化A,B,C,D
void Md5::reset()
{
	a= 0x67452301;
	b= 0xefcdab89;
	c= 0x98badcfe;
	d= 0x10325476;
	//:初始化chunk
	memset(chunk, 0, N);
	//；初始化填充相关信息
	lastbyte = allbyte = 0;
}

//：一块chunk的Md5运算
void Md5::calMd5(elemtype *chunk)
{
	int A = a, B = b, C = c, D = d;
	int f, g, i;
	//:4byte为一单元
	//：共进行,64次
	for (int i = 0; i < 64; i++)
	{
		//：位运算，FGHI
		if (i >= 0 && i < 16)
		{
			f = F(B, C, D);
			g = i;
		}
		else if (i >= 16 && i < 32)
		{
			f = G(B, C, D);
			g = (5 * i + 1) % 16;
		}
		else if (i >= 32 && i < 48)
		{
			f = H(B, C, D);
			g = (3 * i + 5) % 16;
		}
		else
		{
			f = I(B, C, D);
			g = (7 * i) % 16;
		}
		//:更新，加法，循环左移
		int tmp = D;
		D= C;
		C = B;
		B = B + Leftshift((A + f + k[i] + chunk[g]), leftshift[i]);
		A = tmp;
	}
	a = a + A;
	b = b + B;
	c = c + C;
	D = d + D;


}
//:进行填充再进行Md5运算
void Md5::calFinalMd5()
{
	//:填充冗余信息，第一个比特位填1，剩余填0；
	//:任何情况下都需要填充至少1byte的冗余信息
	//:获取第一个待填充的位置
	char *p = chunk + lastbyte;
	//：首先填充1byte的冗余信息
	*p++ =0x80;

	int remainbyte = N - lastbyte - 1;
	//:如果剩余字节数不够8byte（64bite),不能填充长度信息
	//:先处理一块数据，再去构建一个新的数据块，前448位填0，最后64位填长度信息
	if (remainbyte < 8)
	{
		memset(p, 0, remainbyte);
		calMd5((elemtype*)chunk);
		//：创建一个新的数据块
		memset(chunk, 0, N);
	}
	else
	{
		memset(p, 0, remainbyte);
	}
	//:给数据块的最后64位填充原始长度信息
	unsigned long long allbytes = allbyte;
	allbytes *= 8;
	((unsigned long long*)chunk)[7] = allbytes;
	calMd5((elemtype*)chunk);
}
//:转换函数:把一个整形数据转化为对应的16进制字符串。
std::string Md5:: changeHex(elemtype n)
{
	static std::string stringMap = "0123456789abcdef";
	std::string ret;
	//：获取每一个字节数据
	for (int i = 0; i < 4; i++)
	{
		//:获取一个字节数据
		int curByte = (n >> (i * 8)) & 0xff;
		//:数据转化为16进制
		std::string curRet;
		//:除16 高位，模16 底位，字节内不逆序
		curRet += stringMap[curByte / 16];
		curRet += stringMap[curByte % 16];
		//；字节之间逆序
		ret += curRet;
	}
	return ret;
}
std::string Md5::getstringMd5(std::string&str)
{
	if (str.empty())
	{
		return changeHex(a).append(changeHex(b)).append(changeHex(c)).append(changeHex(d));
	}
	allbyte = str.size();
	elemtype chuankNumber = allbyte / N;
	const char *strPtr = str.c_str();
	for (int i = 0; i < chuankNumber; i++)
	{
		memcpy(chunk, strPtr + i*N, N);
		calMd5((elemtype*)chunk);
	}
	lastbyte = allbyte % N;
	memcpy(chunk, strPtr + chuankNumber*N, lastbyte);
	calFinalMd5();
	return changeHex(a).append(changeHex(b)).append(changeHex(c)).append(changeHex(d));
}
std::string Md5::getfileMd5(const char* filePath)
{
	std::ifstream fin(filePath,std::ifstream::binary);
	if (!fin.is_open())
	{
		std::cout << filePath;
		perror("file open failed");
		return "";
	}
	while (!fin.eof())
		//{
		//	//:全部读进来,空间换时间，时间效率高
		//	fin.seekg(0, fin.end);
		//	elemtype length = fin.tellg;
		//	fin.seekg(0, fin.beg);
		//	char* alldate = new char[length];
		//	fin.read(alldate, length);
		//}

		//:每次只读取一块数据，时间换空间
	{
		fin.read(chunk, N);
		//；是否读到64字节
		if (N != fin.gcount())
		{
			break;
		}
		allbyte += N;
		calMd5((elemtype*)chunk);
	}
	//:gcount:可以调用多次，但返回的是最近一次读入的字节数
	lastbyte = fin.gcount();
	allbyte += lastbyte;
	calFinalMd5();
	return changeHex(a).append(changeHex(b)).append(changeHex(c)).append(changeHex(d));
}