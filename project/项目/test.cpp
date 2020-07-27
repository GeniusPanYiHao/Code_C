#pragma once
#include<iostream>
#include<string>
#include"User.h"
//ɨ���ļ�
void file_app::scanner()
{
	std::string path;
	std::cout << "�������ļ���Ŀ¼��" << std::endl;
	getline(std::cin, path);
	_fm.scannerDir(path);
}
//��������ɾ��
void file_app::delete_By_name()
{
	std::string name;
	std::cout << "�������ļ����ƣ���·������" << std::endl;
	getline(std::cin, name);
	_fm.deleteByname(name);
}
//ɾ��ģ���ļ������ļ�
void file_app::delete_By_MatchName()
{
	std::string name;
	std::cout << "�������ļ��Ĳ����ַ�����" << std::endl;
	getline(std::cin, name);
	_fm.deleteByMatchName(name);
}
//ɾ�����еĸ���
void file_app::delete_Allcopy()
{
	_fm.deleteAllCopy();
}
//չʾ���и���
void file_app::Showcopylist()
{
	_fm.showcopylist();
}
//չʾ�����ļ�
void file_app::ShowAllfile()
{
	_fm.showAllfile();
}

//չʾ�˵�
void file_app::menu_show()
{
	std::cout << "---------------------------�����ļ�������--------------------------" << std::endl;
	std::cout << "|  0��exit    1��scan   2��delete by name   3��delete by match name |" << std::endl;
	std::cout << "|  4��delete all copy      5��show all copy      6��show all files  |" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------��ѡ��-------------------------------" << std::endl;
}
//�˵�
void file_app::menu()
{
	int input;
	do
	{
		menu_show();
		std::cin >> input;
		std::string garbage;
		getline(std::cin, garbage);
		switch (input)
		{
		case 1:
			scanner();
			break;
		case 2:
			delete_By_name();
			break;
		case 3:
			delete_By_MatchName();
			break;
		case 4:
			delete_Allcopy();
			break;
		case 5:Showcopylist();
			break;
		case 6:ShowAllfile();
			break;
		default:
			break;
		}
	} while (input);
}
