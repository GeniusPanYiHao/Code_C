#include<iostream>
#include<string>
using namespace std;
int StrToInt(const char *ch)
{
	bool m_stat = false;
	long num = 0;
	int m_flag = 1;
	while (isspace(*ch))
		++ch;
	if (*ch == '-')
		m_flag = -1;
	if (*ch == '-' || *ch == '+')
		++ch;
	while (isdigit(*ch) && *ch)
	{
		num = num * 10 + m_flag*(*ch - '0');
		if ((m_flag == 1 && num < 0)
			|| (m_flag == -1 && num >0))	//ÅÐ¶ÏÒç³ö
		{
			num = 0;
			break;
		}
		++ch;
		if (*ch == '\0')
			m_stat = true;
	}
	if (m_stat)
		cout << "SUCCESS" << endl;
	else
		cout << "FAIL" << endl;
	return num;
}