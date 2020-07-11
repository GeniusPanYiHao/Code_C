#define _CRT_SECURE_NO_WARNINGS 1
#include"filemanager.h"
#include"findfile.hpp"
using namespace std;
void FileManager::scannerDir(const string& path)
{
	//:清理容器
	_files.clear;
	searchDir(path, _files);//:保存当前目录下的所有文件
	getmd5toFiles();
	getCopyList();
}
void FileManager::getmd5toFiles()
{
	_md5toFiles.clear();
	for (const auto &f : _files)
	{
		_md5.reset();
		_md5toFiles.insert(make_pair(_md5.getfileMd5(f), f));
	}

}
//:只保留内容重复文件的结果
void FileManager::getCopyList()
{
	_filestoMd5.clear();
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end())
	{
		if (_md5toFiles.count(it->first) > 1)
		{
			auto pairit = _md5toFiles.equal_range(it->first);
			auto begin = pairit.first;
			while (begin != pairit.second)
			{
				_filestoMd5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			//；下一个不同的MD5值起始位置
			it = pairit.second;
		}
		//：若没有多个文件
		else
		{
			//:erase 返回值：被删除元素的下一个位置
			it = _md5toFiles.erase(it);
		}
	}
}
//:所有的删除，保证一个文件不存在副本
void FileManager::deleteByname(const string & name)
{

}
void FileManager::deleteMD5(const string & Md5)
{

}
void FileManager::deleteAllCopy()
{

}
//:模糊删除：删除所有模糊匹配"matchname"所有文件副本
void FileManager::deleteByMatchName(const string &matchname)
{

}
void FileManager::showcopylist()
{

}
void FileManager::showAllfile()
{

}
void FileManager::showMd5map()
{

}