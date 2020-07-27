#pragma once
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
		//:����ÿһ��md5��Ӧ�������ļ����

		if (_md5toFiles.count(it->first) > 1)
		{
			auto pairit = _md5toFiles.equal_range(it->first);//:equal_range����ֵ��pair<beginIt,endIt>:[beginIt,endIt)    ����������ʱ����
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
		std::string num = _filestoMd5[name];
		if (_md5toFiles.count(num) <= 1)
		{
			std::cout << "û�ж�����ļ�����ɾ����" << std::endl;
			return;
		}
		auto pairIt = _md5toFiles.equal_range(num);
		auto begin = pairIt.first;
		//��Ҫɾ�����ļ�����
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
		std::cout << "һ����" << count + 1 << "����" << name << "������ͬ���ļ�" << std::endl;
		std::cout << "һ��ɾ����" << count << "���ļ�" << std::endl << std::endl;

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
	
}
void FileManager::showAllfile()
{

}
void FileManager::showMd5map()
{

}