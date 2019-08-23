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


//��ͨѶ¼��ģ������������ָ����ϵ��
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
		printf("����ϵ�˲����ڣ�����ʧ�ܣ�\n");
	}

}

//��ͨѶ¼�������ָ����ϵ��
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


//�����ϵ��
void add_linkman(people cou)
{
	if (cou->num == 1000)
	{
		printf("ͨѶ¼�������޷�¼����Ϣ��\n");
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

//ɾ����ϵ��
void delete_linkman(people cou)
{
	char name[NAME_MAX];
	int i = 0;

	if (cou->num == 0)
	{
		printf("ͨѶ¼�ѿգ��޷�ɾ����Ϣ��\n");
		return;
	}

	printf("������Ҫɾ���˵�����:");
	scanf("%s", &name);
	printf("\n");

	int ret = search(cou, name);//�ҵ�Ҫɾ������ϵ��

	if (ret == -1)
	{
		printf("���˲����ڣ�ɾ��ʧ�ܣ�\n");
	}
	else
	{
		for (i = ret; i<cou->num; i++)
		{
			cou->count[i] = cou->count[i + 1];
		}
		cou->num--;
		printf("ɾ���ɹ���\n");
	}
}

//�޸�ָ����ϵ����Ϣ
void change_linkman(people cou)
{
	char name[NAME_MAX];
	int i = 0;
	printf("������Ҫ�޸��˵�����:");
	scanf("%s", name);

	if (cou->num == 0)
	{
		printf("��ǰͨѶ¼Ϊ�գ��޸�ʧ�ܣ�\n");
		return;
	}

	int ret = search(cou, name);//�ҵ�Ҫ�޸���Ϣ����ϵ��

	if (ret != -1)
	{
		printf("please input name again:\n");
		scanf("%s", (cou->count[ret]).name);
		printf("please input the sex��\n");
		scanf("%s", (cou->count[ret]).sex);
		printf("please input the age��\n");
		scanf("%d", &(cou->count[ret]).age);
		printf("please input the telephone��\n");
		scanf("%s", (cou->count[ret]).tel);
		printf("please input the address��\n");
		scanf("%s", (cou->count[ret]).addr);
	}
	printf("�޸���Ϣ�ɹ���\n");
}

//������ϵ��
void find_linkman(people cou)
{
	char name[NAME_MAX];
	int i = 0;

	printf("������Ҫ�����˵����ֻ�绰����:");
	scanf("%s", name);

	if (cou->num == 0)
	{
		printf("��ǰͨѶ¼Ϊ�գ�����ʧ�ܣ�\n");
		return;
	}

	_search(cou, name);//�ҵ�Ҫ���ҵ���ϵ��

}

//��ʾ������ϵ����Ϣ
void display_linkman(people cou)
{
	int i = 0;
	if (cou->num == 0)
	{
		printf("��ǰͨѶ¼Ϊ�գ���ʾʧ�ܣ�\n");
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

void empty_linkman(people cou)//���������ϵ��
{
	cou->num = 0;
}

struct stu
{
	char name[15];
};

void name_sort(people cou)//������˳������������
{
	int i = 0;
	int j = 0;
	if (cou->num == 0)
	{
		printf("��ǰͨѶ¼Ϊ�գ�����ʧ�ܣ�\n");
		return;
	}

	for (i = 0; i<cou->num - 1; i++)//ð��ʵ����ϵ�˵�����
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

	printf("����ɹ���\n");
}

//�˵�����
void menu()
{
	printf("************************************\n");
	printf("*********1.�����ϵ����Ϣ***********\n");
	printf("*********2.ɾ��ָ����ϵ����Ϣ*******\n");
	printf("*********3.����ָ����ϵ����Ϣ*******\n");
	printf("*********4.�޸�ָ����ϵ����Ϣ*******\n");
	printf("*********5.��ʾ������ϵ����Ϣ*******\n");
	printf("*********6.���������ϵ��***********\n");
	printf("*********7.����������������ϵ��*****\n");
	printf("*********0.�˳�*********************\n");
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
		printf("��ѡ��>:");
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
				   printf("������������������>��\n");
				   break;
		}
		}
	}

	getchar();
	return 0;
}

