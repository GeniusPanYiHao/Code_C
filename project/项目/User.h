#pragma once
#include"filemanager.h"

class file_app
{
public:
	//展示菜单
	void menu_show();
	//菜单
	void menu();
	//扫描文件
	void scanner();
	//按照名字删除
	void delete_By_name();
	//删除模糊匹配文件名的文件
	void delete_By_MatchName();
	//删除所有的副本
	void delete_Allcopy();
	//展示所有副本
	void Showcopylist();
	//展示所有文件
	void ShowAllfile();
private:
	FileManager _fm;
};
