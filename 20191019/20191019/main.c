#include <reg52.h>
#include <intrins.h>
#include <absacc.h> 

#define uchar unsigned char
#define uint unsigned int


sbit rs = P3 ^ 5;
sbit wr = P3 ^ 6;
sbit lcden = P3 ^ 4;
sbit WR12 = P2 ^ 1;
sbit CS = P2 ^ 0;
sbit CLK = P3 ^ 1;
sbit DIO = P3 ^ 2;
sbit CS1 = P3 ^ 3;

uchar table1[] = "input";
uchar table2[] = "0000MA";
uchar keyflag;
uchar c;
bit set, jia, jian, right;
uchar m;
uchar keyvalue;
sbit k1 = P2 ^ 2;
sbit k2 = P2 ^ 3;
sbit k3 = P2 ^ 4;
sbit k4 = P2 ^ 5;

uchar s;


void delay(uint x)
{
	uint a, b;
	for (a = x; a>0; a--)
	for (b = 10; b>0; b--);
}
void delay20ms(void)
{
	unsigned char a, b;
	for (b = 215; b>0; b--)
	for (a = 45; a>0; a--);

}
/******************延时函数*******************************/
void delay1(uint x)
{
	uint a, b;
	for (a = x; a>0; a--)
	for (b = 100; b>0; b--);
}

void write_com(uchar com)
{
	P0 = com;
	rs = 0;
	lcden = 0;
	delay(10);
	lcden = 1;
	delay(10);
	lcden = 0;
}

void write_date(uchar date)
{
	P0 = date;
	rs = 1;
	lcden = 0;
	delay(10);
	lcden = 1;
	delay(10);
	lcden = 0;

}

void init()
{

	wr = 0;
	write_com(0x38);
	delay(20);
	write_com(0x0c);
	delay(20);

	write_com(0x01);
	delay(20);

}
/*****************按键程序***********************************/
void keyscan()
{
	if (k1 == 0)
	{
		delay20ms();
		if (k1 == 0)
		{
			while (!k1);
			keyvalue = 1;
			set = 1;
			m++;
		}
	}
	if (k2 == 0)
	{
		delay20ms();
		if (k2 == 0)
		{
			while (!k2);
			keyvalue = 2;
			right = 1;
		}
	}
	if (k3 == 0)
	{
		delay20ms();
		if (k3 == 0)
		{
			while (!k3);
			keyvalue = 3;
			jia = 1;
		}
	}
	if (k4 == 0)
	{
		delay20ms();
		if (k4 == 0)
		{
			while (!k4);
			keyvalue = 4;
			jian = 1;
		}
	}
}

/****************ad采集并返回******************/
unsigned char  A_D()
{
	unsigned char i, dat;
	CS1 = 1;
	CLK = 0;
	CS1 = 0;

	DIO = 1;
	CLK = 1;
	CLK = 0;
	DIO = 1;
	CLK = 1;
	CLK = 0;
	DIO = 0;
	CLK = 1;
	CLK = 0;
	DIO = 1;
	CLK = 1;
	for (i = 0; i<8; i++)
	{
		CLK = 1;
		CLK = 0;
		dat <<= 1;
		dat |= (unsigned char)DIO;
	}
	CS1 = 1;
	return dat;
}
/***************************************主函数*******************************/
void main()
{
	uchar a, s, q = 0, w = 0, e = 0, r = 0, aa, bb;
	uint cc;
	CS = 0;
	WR12 = 0;
	init();
	write_com(0x80 + 0x00);
	delay(20);
	for (a = 0; a<5; a++)
	{
		write_date(table1[a]);
		delay(20);
	}
	write_com(0xc0 + 0x00);
	delay(50);
	for (a = 0; a<6; a++)
	{
		write_date(table2[a]);
		delay(40);
	}

	/*	write_com(0x80+0x08);
	delay(50);
	for(a=0;a<6;a++)
	{
	write_date(table3[a]);
	delay(40);
	}


	write_com(0xc0+0x08);
	delay(50);
	for(a=0;a<6;a++)
	{
	write_date(table4[bb]);
	delay(40);
	}*/


	while (1)
	{

		keyscan();
		if ((keyvalue == 1) && (m % 2 == 1))
		{
			write_com(0xc0 + 0x00);
			write_com(0x0f);
		}
		else if ((keyvalue == 1) && (m % 2 == 0))
		{
			write_com(0x0c);
		}
		if (set == 1)
		{
			switch (keyvalue)
			{
			case 2:c++;
				if (c == 4)
				{
					c = 0;
				}
				write_com(0xc0 + 0x00 + c);
				write_com(0x0f);
				break;
			case 3:table2[c]++;
				if (table2[c]>'9')
				{
					table2[c] = '0';
				}
				//table3[c]++;

				if (c == 0)
				{
					q++;
				}
				if (c == 1)
				{
					w++;
				}
				if (c == 2)
				{
					e++;
				}
				if (c == 3)
				{
					r++;
				}
				write_com(0xc0 + 0x00 + c);
				write_date(table2[c]);
				write_com(0xc0 + 0x00 + c);
				write_com(0x0f);
				break;
			case 4:	table2[c]--;
				if (table2[c]<'0')
				{
					table2[c] = '9';
				}

				//table3[c]--;
				if (c == 0)
				{
					q--;
				}
				if (c == 1)
				{
					w--;
				}
				if (c == 2)
				{
					e--;
				}
				if (c == 3)
				{
					r--;
				}
				write_com(0xc0 + 0x00 + c);
				write_date(table2[c]);
				write_com(0xc0 + 0x00 + c);
				write_com(0x0f);
				break;
			}
			keyvalue = 0;
		}


		cc = (1000 * q + 100 * w + 10 * e + r);
		// cc=cc*34;
		//s=(uchar)(cc>>8);
		s = (uchar)(cc*0.130 * 2);
		// CS=1;
		P1 = s;
		aa = A_D();
		bb = aa / 2.5;
		if (bb>cc)
			s--;
		else if (bb<cc)
			s++;
	}
}
