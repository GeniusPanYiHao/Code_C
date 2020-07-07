#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<string>
#include<unordered_set>
#include<unordered_map>
#include"Md5.h"
using namespace std;
class FileManager
{
public :
	void scannerDir(const string& path);
	void getmd5toFiles();
	void getCopyList();
	//:���е�ɾ������֤һ���ļ������ڸ���
	void deleteByname(const string & name);
	void deleteMD5(const string & Md5);
	void deleteAllCopy();
	//:ģ��ɾ����ɾ������ģ��ƥ��"matchname"�����ļ�����
	void deleteByMatchName(const string &matchname);
	void showcopylist();
	void showAllfile();
	void showMd5map();
private:
	//:ɨ����ļ������������list,vector,map,set
	unordered_set<string> _files;
	//:ӳ��
	//:md5ӳ���ļ�,md5ֵ������ͬ��������multimap.
	unordered_multimap<string, string>_md5toFiles;
	//���ļ�ӳ��MD5
	unordered_map<string, string>_filestoMd5;
	Md5 _md5;
};