#pragma once
#include"filemanager.h"

class file_app
{
public:
	//չʾ�˵�
	void menu_show();
	//�˵�
	void menu();
	//ɨ���ļ�
	void scanner();
	//��������ɾ��
	void delete_By_name();
	//ɾ��ģ��ƥ���ļ������ļ�
	void delete_By_MatchName();
	//ɾ�����еĸ���
	void delete_Allcopy();
	//չʾ���и���
	void Showcopylist();
	//չʾ�����ļ�
	void ShowAllfile();
private:
	FileManager _fm;
};
