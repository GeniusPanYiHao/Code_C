#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define PERSONS_MAX_SIZE 1000
#define NAME_MAX_SIZE 1024
#define PHONE_MAX_SIZE 1024
typedef struct Personinfo
{
	char name[NAME_MAX_SIZE];
	char phone[PHONE_MAX_SIZE];
}Personinfo;
typedef struct Addrbook
{
	Personinfo persons[PERSONS_MAX_SIZE];
	int size;
}Addrbook;
void init(Addrbook* addr_book)
{
	assert(addr_book != NULL);
	addr_book->size = 0;
	for (int i = 0; i <= PERSONS_MAX_SIZE; ++i)
	{
		memset(addr_book->persons[i].name, 0, NAME_MAX_SIZE);
		memset(addr_book->persons[i].phone, 0, PHONE_MAX_SIZE);
	}
}
void add(Addrbook*addr_book)
{
	assert(addr_book != NULL);
	printf("新增联系人\n");
	if (addr_book->size >= PERSONS_MAX_SIZE)
	{
		printf("通讯录已满\n");
		return;
	}
	printf("请输入联系人姓名\n");
	Personinfo* p = &addr_book->persons[addr_book->size];
	scanf("%s", p->name);
	printf("请输入联系人电话");
	scanf("%s", p->phone);
	++addr_book->size;
}

int remove(Addrbook*addr_book)
{
	assert(addr_book != NULL);
}
void printall(Addrbook*addr_book)
{
	assert(addr_book != NULL);
	for (int i = 0; i <= addr_book->size; ++i)
	{
		Personinfo* p = &addr_book->persons[i];
		printf("[%d] %s: %s\n", i, p->name, p->phone);
	}
	printf("当前有%d条记录\n", addr_book->size);
}
void update(Addrbook*addr_book)
{
	assert(addr_book != NULL);
	printf()
}
int menu()
{
	printf("************************************************\n");
	printf("**********欢迎使用通讯录************************\n");
	printf("**********1.显示联系人信息**********************\n");
	printf("**********2.新增联系人信息**********************\n");
	printf("**********3.修改联系人信息**********************\n");
	printf("**********4.删除联系人信息**********************\n");
	printf("**********0.退出通讯录**************************\n");
	printf("************************************************\n");
	printf("请输入你的选择");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
Addrbook addr_book;
typedef void(*Func)(Addrbook*);
int main()
{
	init(&addr_book);
	Func func_table[] =
	{
		NULL,
		printall,
		add,
		remove,
		update
	};
	while (1)
	{
		int choice = menu();
		if (choice<0 || choice>4)
		{
			printf("输入有误，请重新输入\n");
			continue;
		}
		if (choice == 0)
		{
			printf("byebye\n");
			break;
		}
		system("cls");
		func_table[choice](&addr_book);
	}
	return 0;
}
}
