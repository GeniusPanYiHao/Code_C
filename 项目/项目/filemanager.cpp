#define _CRT_SECURE_NO_WARNINGS 1
#include"filemanager.h"
#include"findfile.hpp"
using namespace std;
void FileManager::scannerDir(const string& path)
{
	//:��������
	_files.clear();
	searchDir(path, _files);//:���浱ǰĿ¼�µ������ļ�
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
//:ֻ���������ظ��ļ��Ľ��
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
			//����һ����ͬ��MD5ֵ��ʼλ��
			it = pairit.second;
		}
		//����û�ж���ļ�
		else
		{
			//:erase ����ֵ����ɾ��Ԫ�ص���һ��λ��
			it = _md5toFiles.erase(it);
		}
	}
}
//:���е�ɾ������֤һ���ļ������ڸ���
void FileManager::deleteByname(const string & name)
{

}
void FileManager::deleteMD5(const string & Md5)
{

}
void FileManager::deleteAllCopy()
{

}
//:ģ��ɾ����ɾ������ģ��ƥ��"matchname"�����ļ�����
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
		//:md5ֵ��ͬ����ʾ��һ��
		int idx = 1;
		auto pairIt = _md5toFiles.equal_range(it->first);
		auto curIt = pairIt.first;
		std::cout << "cur MD5:" << it->first << std::endl;
		while (curIt != pairIt.second)
		{
			std::cout << "\t��" << idx << "���ļ���";
			std::cout << curIt->second << std::endl;
			count++;
		}
		it = pairIt.second;
	}
	std::cout << "�ļ�������" << total << "\t" << count << std::endl;
	;
}
void FileManager::showAllfile()
{

}
void FileManager::showMd5map()
{

}