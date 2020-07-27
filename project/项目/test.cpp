#pragma once
#include<iostream>
#include<string>
#include"User.h"
//扫描文件
void file_app::scanner()
{
	std::string path;
	std::cout << "请输入文件夹目录：" << std::endl;
	getline(std::cin, path);
	_fm.scannerDir(path);
}
//按照名字删除
void file_app::delete_By_name()
{
	std::string name;
	std::cout << "请输入文件名称（带路径）：" << std::endl;
	getline(std::cin, name);
	_fm.deleteByname(name);
}
//删除模糊文件名的文件
void file_app::delete_By_MatchName()
{
	std::string name;
	std::cout << "请输入文件的部分字符串：" << std::endl;
	getline(std::cin, name);
	_fm.deleteByMatchName(name);
}
//删除所有的副本
void file_app::delete_Allcopy()
{
	_fm.deleteAllCopy();
}
//展示所有副本
void file_app::Showcopylist()
{
	_fm.showcopylist();
}
//展示所有文件
void file_app::ShowAllfile()
{
	_fm.showAllfile();
}

//展示菜单
void file_app::menu_show()
{
	std::cout << "---------------------------磁盘文件管理工具--------------------------" << std::endl;
	std::cout << "|  0、exit    1、scan   2、delete by name   3、delete by match name |" << std::endl;
	std::cout << "|  4、delete all copy      5、show all copy      6、show all files  |" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------请选择-------------------------------" << std::endl;
}
//菜单
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
