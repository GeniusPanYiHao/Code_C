#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//:打印棋盘
void InitBoard(char board[][3], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void ShowBoard(char board[][3], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)//:遍历二维数组
		{

			printf(" %c ", board[i][j]);

			if (j < col - 1)

			{

				printf("|");//:每打印一个元素打印一个竖杠

			}

		}

		printf("\n");
		if (i < row - 1)//:控制横线

		{

			for (j = 0; j < col; j++)

			{

				printf("---");

				if (j < col - 1)//：控制竖杠

				{

					printf("|");
				}

			}

			printf("\n");

		}

	}

}


//:玩家开始移动
void PlayerMove(char board[][3], int row, int col)

{

	int x = 0;

	int y = 0;//:玩家坐标

	while (1)

	{

		printf("请输入1-3的坐标：");//X

		scanf("%d%d", &x, &y);

		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)

		{

			if (board[x - 1][y - 1] == ' ')

			{

				board[x - 1][y - 1] = 'X';

				break;

			}

			else

			{

				printf("此位置已经被占用了\n");

			}

		}

		else // :若输入坐标不在范围内

		{

			printf("坐标位置不合法\n");

		}

	}

}



static int IsFull(char board[][3], int row, int col)

{

	int i = 0;

	for (i = 0; i < row; i++)

	{

		int j = 0;

		for (j = 0; j < col; j++)

		{

			if (board[i][j] == ' ')

			{

				return 0;//没有满

			}

		}

	}

	return 1;//满

}


//如何赢
char IsWin(char board[][3], int row, int col)

{

	int i = 0;

	for (i = 0; i < row; i++)

	{

		//行

		if (board[i][0] == board[i][1]

			&& board[i][1] == board[i][2]

			&& board[i][0] != ' ')

		{

			return board[i][0];

		}

		//列

		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]

			&& board[0][i] != ' ')

		{

			return board[0][i];

		}

		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]

			&& board[0][0] != ' ')

		{

			return board[0][0];

		}



		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]

			&& board[0][0] != ' ')

		{

			return board[0][2];

		}



		//平局

		if (IsFull(board, row, col) == 1)

		{

			return 'Q';

		}

	}

	//即没有赢，也没有平局

	return ' ';

}


//:电脑如何走
void ComputerMove(char board[][3], int row, int col)

{



	int x = 0;

	int y = 0;

	printf("电脑移动\n");

	while (1)

	{

		x = rand() % row + 1;//3  [0-3)   [1-3]

		y = rand() % col + 1;

		if (board[x - 1][y - 1] == ' ')

		{

			board[x - 1][y - 1] = 'O';

			break;

		}

	}

}
