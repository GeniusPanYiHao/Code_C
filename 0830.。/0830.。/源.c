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
	printf("������ϵ��\n");
	if (addr_book->size >= PERSONS_MAX_SIZE)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	printf("��������ϵ������\n");
	Personinfo* p = &addr_book->persons[addr_book->size];
	scanf("%s", p->name);
	printf("��������ϵ�˵绰");
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
	printf("��ǰ��%d����¼\n", addr_book->size);
}
void update(Addrbook*addr_book)
{
	assert(addr_book != NULL);
	printf()
}
int menu()
{
	printf("************************************************\n");
	printf("**********��ӭʹ��ͨѶ¼************************\n");
	printf("**********1.��ʾ��ϵ����Ϣ**********************\n");
	printf("**********2.������ϵ����Ϣ**********************\n");
	printf("**********3.�޸���ϵ����Ϣ**********************\n");
	printf("**********4.ɾ����ϵ����Ϣ**********************\n");
	printf("**********0.�˳�ͨѶ¼**************************\n");
	printf("************************************************\n");
	printf("���������ѡ��");
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
			printf("������������������\n");
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
