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
	//:所有的删除，保证一个文件不存在副本
	void deleteByname(const string & name);
	void deleteMD5(const string & Md5);
	void deleteAllCopy();
	//:模糊删除：删除所有模糊匹配"matchname"所有文件副本
	void deleteByMatchName(const string &matchname);
	void showcopylist();
	void showAllfile();
	void showMd5map();
private:
	//:扫描的文件保存在容器里：list,vector,map,set
	unordered_set<string> _files;
	//:映射
	//:md5映射文件,md5值可能相同，所以用multimap.
	unordered_multimap<string, string>_md5toFiles;
	//：文件映射MD5
	unordered_map<string, string>_filestoMd5;
	Md5 _md5;
};