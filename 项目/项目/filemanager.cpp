#pragma once
#include"filemanager.h"
#include"findfile.hpp"
using namespace std;
void FileManager::scannerDir(const string& path)
{
	//:清理容器
	_files.clear();
	searchDir(path, _files);//:保存当前目录下的所有文件
	getmd5toFiles();
	getCopyList();
}
void FileManager::getmd5toFiles()
{
	_md5toFiles.clear();
	for (const auto& f : _files)
	{
		_md5.reset();
		_md5toFiles.insert(make_pair(_md5.getfileMd5(f.c_str()), f));
	}

}
//:只保留内容重复文件的结果
void FileManager::getCopyList()
{
	_filestoMd5.clear();
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end())
	{
		//:查找每一个md5对应的所有文件结果

		if (_md5toFiles.count(it->first) > 1)
		{
			auto pairit = _md5toFiles.equal_range(it->first);//:equal_range返回值：pair<beginIt,endIt>:[beginIt,endIt)    迭代器遍历时连续
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
		std::string num = _filestoMd5[name];
		if (_md5toFiles.count(num) <= 1)
		{
			std::cout << "没有多余的文件可以删除！" << std::endl;
			return;
		}
		auto pairIt = _md5toFiles.equal_range(num);
		auto begin = pairIt.first;
		//需要删除的文件数量
		int count = _md5toFiles.count(num) - 1;
		while (begin != pairIt.second)
		{
			if (begin->second != name)

			{
				_filestoMd5.erase(begin->second);
				_files.erase(begin->second);
				deletefile(begin->second.c_str());
				_md5toFiles.erase(begin);
				pairIt = _md5toFiles.equal_range(num);
				begin = pairIt.first;
			}
			else
			{
				++begin;
			}
		}
		std::cout << "一共有" << count + 1 << "个和" << name << "内容相同的文件" << std::endl;
		std::cout << "一共删除了" << count << "个文件" << std::endl << std::endl;

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
	int count = 0;
	auto it = _md5toFiles.begin();
	int total = _md5toFiles.size();
	while (it != _md5toFiles.end())
	{
		//:md5值相同的显示在一起
		int idx = 1;
		auto pairIt = _md5toFiles.equal_range(it->first);
		auto curIt = pairIt.first;
		std::cout << "cur MD5:" << it->first << std::endl;
		while (curIt != pairIt.second)
		{
			std::cout << "\t第" << idx << "个文件：";
			std::cout << curIt->second << std::endl;
			count++;
		}
		it = pairIt.second;
	}
	std::cout << "文件总数：" << total << "\t" << count << std::endl;
	
}
void FileManager::showAllfile()
{

}
void FileManager::showMd5map()
{

}