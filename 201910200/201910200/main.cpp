#include<iostream.h>
#include<time.h>
struct Student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout<< _name << " " << _gender << " " << _age << endl;
	}

	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s;
	s.SetStudentInfo("Peter", "��", 18);
	return 0;
}