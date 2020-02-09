#include <iostream>
#include <list>
#include<cstring>
using namespace std;

struct student{
	char name[32];
	int age;
	int classid;
	bool sex;
};
//bool cmpEql(student a, student b)
//{
//	return a.age == b.age;
//}
bool cmpEqlname(student a, student b)
{
	return strcmp(a.name, b.name) ? false : true;
}
bool cmpEqlsex(student a, student b)
{
	return !(a.sex^b.sex);
}
int countS(student* st, int n, student value, bool(*cmp)(student, student) = cmpEqlsex)
{
	int i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (cmp(st[i], value))
		{
			count++;
		}
	}
	return count;
}


int main()
	{
	student st[] = { { "A", 18, 1, true },
	{ "B", 18, 1, false },
	{ "C", 20, 2, true },
	{ "D", 22, 2, true },
	{ "F", 22, 2, true },
	};
	student test = { "A", 18, 1, true };
	cout << countS(st, 7, test, cmpEqlsex) << endl;
	return 0;
}