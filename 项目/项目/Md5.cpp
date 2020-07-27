#pragma once
#include"Md5.h"
#include<math.h>
#include<iostream>
#include<fstream>
//:��ʼ��static��Ա
int Md5::leftshift[] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };
Md5::Md5()
{
	init();
}
//:��ʼ��
void Md5::init()
{
	for (int i = 0; i < 64; i++)
	{
		k[i] = static_cast<elemtype>(abs(sin(i + 1.0)*pow(2.0, 32)));
	}
	reset();
}
//:��ʼ��A,B,C,D
void Md5::reset()
{
	a= 0x67452301;
	b= 0xefcdab89;
	c= 0x98badcfe;
	d= 0x10325476;
	//:��ʼ��chunk
	memset(chunk, 0, N);
	//����ʼ����������Ϣ
	lastbyte = allbyte = 0;
}

//��һ��chunk��Md5����
void Md5::calMd5(elemtype *chunk)
{
	int A = a, B = b, C = c, D = d;
	int f, g, i;
	//:4byteΪһ��Ԫ
	//��������,64��
	for (int i = 0; i < 64; i++)
	{
		//��λ���㣬FGHI
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
		//:���£��ӷ���ѭ������
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
//:��������ٽ���Md5����
void Md5::calFinalMd5()
{
	//:���������Ϣ����һ������λ��1��ʣ����0��
	//:�κ�����¶���Ҫ�������1byte��������Ϣ
	//:��ȡ��һ��������λ��
	char *p = chunk + lastbyte;
	//���������1byte��������Ϣ
	*p++ =0x80;

	int remainbyte = N - lastbyte - 1;
	//:���ʣ���ֽ�������8byte��64bite),������䳤����Ϣ
	//:�ȴ���һ�����ݣ���ȥ����һ���µ����ݿ飬ǰ448λ��0�����64λ�����Ϣ
	if (remainbyte < 8)
	{
		memset(p, 0, remainbyte);
		calMd5((elemtype*)chunk);
		//������һ���µ����ݿ�
		memset(chunk, 0, N);
	}
	else
	{
		memset(p, 0, remainbyte);
	}
	//:�����ݿ�����64λ���ԭʼ������Ϣ
	unsigned long long allbytes = allbyte;
	allbytes *= 8;
	((unsigned long long*)chunk)[7] = allbytes;
	calMd5((elemtype*)chunk);
}
//:ת������:��һ����������ת��Ϊ��Ӧ��16�����ַ�����
std::string Md5:: changeHex(elemtype n)
{
	static std::string stringMap = "0123456789abcdef";
	std::string ret;
	//����ȡÿһ���ֽ�����
	for (int i = 0; i < 4; i++)
	{
		//:��ȡһ���ֽ�����
		int curByte = (n >> (i * 8)) & 0xff;
		//:����ת��Ϊ16����
		std::string curRet;
		//:��16 ��λ��ģ16 ��λ���ֽ��ڲ�����
		curRet += stringMap[curByte / 16];
		curRet += stringMap[curByte % 16];
		//���ֽ�֮������
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
		//	//:ȫ��������,�ռ任ʱ�䣬ʱ��Ч�ʸ�
		//	fin.seekg(0, fin.end);
		//	elemtype length = fin.tellg;
		//	fin.seekg(0, fin.beg);
		//	char* alldate = new char[length];
		//	fin.read(alldate, length);
		//}

		//:ÿ��ֻ��ȡһ�����ݣ�ʱ�任�ռ�
	{
		fin.read(chunk, N);
		//���Ƿ����64�ֽ�
		if (N != fin.gcount())
		{
			break;
		}
		allbyte += N;
		calMd5((elemtype*)chunk);
	}
	//:gcount:���Ե��ö�Σ������ص������һ�ζ�����ֽ���
	lastbyte = fin.gcount();
	allbyte += lastbyte;
	calFinalMd5();
	return changeHex(a).append(changeHex(b)).append(changeHex(c)).append(changeHex(d));
}