#include<stdio.h>
#include<string.h>
#define NAME_MAX 15
#define SEX_MAX 3
#define AGE_MAX 100
#define TEL_MAX 15
#define ADDR_MAX 20
#define PEOPLE_MAX 1000

typedef struct LINK
{
	char name[15];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}linkman;

typedef struct PEOPLE
{
	int num;
	linkman count[1000];
}*people;


//在通讯录里模糊搜索遍历到指定联系人
static int _search(people cou, const char *name)
{
	int number = 0;

	for (int i = 0; i < cou->num; i++)
	{
		if ((strstr((cou->count[i]).name, name) != NULL) || (strstr((cou->count[i]).tel, name) != NULL))
		{
			printf("%s\t%s\t%d\t%s\t%s\t",
				(cou->count[i]).name,
				(cou->count[i]).sex,
				(cou->count[i]).age,
				(cou->count[i]).tel,
				(cou->count[i]).addr);
			printf("\n");
			number++;
		}
	}

	if (number == 0)
	{
		printf("此联系人不存在，查找失败！\n");
	}

}

//在通讯录里遍历到指定联系人
static int search(people cou, const char *name)
{
	for (int i = 0; i < cou->num; i++)
	{
		if (strcmp(name, (cou->count[i]).name) == 0)
		{
			return i;
		}
	}

	return -1;
}


//添加联系人
void add_linkman(people cou)
{
	if (cou->num == 1000)
	{
		printf("通讯录已满，无法录入信息！\n");
	}

	printf("please input name:\n");
	scanf("%s",(cou->count[cou->num]).name);
	printf("please input sex:\n");
	scanf("%s", (cou->count[cou->num]).sex);
	printf("please input age:\n");
	scanf("%d", &(cou->count[cou->num]).age);
	printf("please input telephone:\n");
	scanf("%s", (cou->count[cou->num]).tel);
	printf("please input address:\n");
	scanf("%s", (cou->count[cou->num]).addr);

	cou->num++;
}

//删除联系人
void delete_linkman(people cou)
{
	char name[NAME_MAX];
	int i = 0;

	if (cou->num == 0)
	{
		printf("通讯录已空，无法删除信息！\n");
		return;
	}

	printf("请输入要删除人的名字:");
	scanf("%s", &name);
	printf("\n");

	int ret = search(cou, name);//找到要删除的联系人

	if (ret == -1)
	{
		printf("此人不存在，删除失败！\n");
	}
	else
	{
		for (i = ret; i<cou->num; i++)
		{
			cou->count[i] = cou->count[i + 1];
		}
		cou->num--;
		printf("删除成功！\n");
	}
}

//修改指定联系人信息
void change_linkman(people cou)
{
	char name[NAME_MAX];
	int i = 0;
	printf("请输入要修改人的名字:");
	scanf("%s", name);

	if (cou->num == 0)
	{
		printf("当前通讯录为空，修改失败！\n");
		return;
	}

	int ret = search(cou, name);//找到要修改信息的联系人

	if (ret != -1)
	{
		printf("please input name again:\n");
		scanf("%s", (cou->count[ret]).name);
		printf("please input the sex：\n");
		scanf("%s", (cou->count[ret]).sex);
		printf("please input the age：\n");
		scanf("%d", &(cou->count[ret]).age);
		printf("please input the telephone：\n");
		scanf("%s", (cou->count[ret]).tel);
		printf("please input the address：\n");
		scanf("%s", (cou->count[ret]).addr);
	}
	printf("修改信息成功！\n");
}

//查找联系人
void find_linkman(people cou)
{
	char name[NAME_MAX];
	int i = 0;

	printf("请输入要查找人的名字或电话号码:");
	scanf("%s", name);

	if (cou->num == 0)
	{
		printf("当前通讯录为空，查找失败！\n");
		return;
	}

	_search(cou, name);//找到要查找的联系人

}

//显示所有联系人信息
void display_linkman(people cou)
{
	int i = 0;
	if (cou->num == 0)
	{
		printf("当前通讯录为空，显示失败！\n");
		return;
	}

	for (i = 0; i<cou->num; i++)
	{
		printf("%s\t%s\t%d\t%s\t%s",
			(cou->count[i]).name,
			(cou->count[i]).sex,
			(cou->count[i]).age,
			(cou->count[i]).tel,
			(cou->count[i]).addr);
		printf("\n");
	}
}

void empty_linkman(people cou)//清空所有联系人
{
	cou->num = 0;
}

struct stu
{
	char name[15];
};

void name_sort(people cou)//按名字顺序排序所有人
{
	int i = 0;
	int j = 0;
	if (cou->num == 0)
	{
		printf("当前通讯录为空，排序失败！\n");
		return;
	}

	for (i = 0; i<cou->num - 1; i++)//冒泡实现联系人的排序
	{
		for (j = 0; j<cou->num - i - 1; j++)
		{
			if (strcmp(cou->count[j].name, (cou->count[j + 1]).name)>0)
			{
				linkman tmp = cou->count[j];
				cou->count[j] = cou->count[j + 1];
				cou->count[j + 1] = tmp;
			}
		}
	}

	printf("排序成功！\n");
}

//菜单界面
void menu()
{
	printf("************************************\n");
	printf("*********1.添加联系人信息***********\n");
	printf("*********2.删除指定联系人信息*******\n");
	printf("*********3.查找指定联系人信息*******\n");
	printf("*********4.修改指定联系人信息*******\n");
	printf("*********5.显示所有联系人信息*******\n");
	printf("*********6.清空所有联系人***********\n");
	printf("*********7.以名字排序所有联系人*****\n");
	printf("*********0.退出*********************\n");
	printf("************************************\n");
}

int main()
{
	int opp = 1;
	struct PEOPLE cou;
	cou.num = 0;

	while (opp)
	{
		menu();
		printf("请选择>:");
		scanf("%d", &opp);
		switch (opp)
		{
		case 0:
			break;
		case 1:
			add_linkman(&cou);
			break;
		case 2:
			delete_linkman(&cou);
			break;
		case 3:
			find_linkman(&cou);
			break;
		case 4:
			change_linkman(&cou);
			break;
		case 5:
			display_linkman(&cou);
			break;
		case 6:
			empty_linkman(&cou);
			break;
		case 7:
			name_sort(&cou);
			break;
		default:
		{
				   printf("输入有误，请重新输入>：\n");
				   break;
		}
		}
	}

	getchar();
	return 0;
}

