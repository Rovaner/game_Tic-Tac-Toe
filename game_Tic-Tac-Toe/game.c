#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//棋盘初始化
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//效果图
//   |   |
//---|---|---
//   |   |   
//---|---|---
//   |   |   
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < row; i++)
//	{
//		//1.打印一行的数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if (i < row - 1)
//			//2.打印分割行
//			printf("---|---|---\n");
//	}
//}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//1.打印一行的数据
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//玩家移动
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家走：>\n");
	while(1)
	{
		printf("请输入要走的坐标：");
		scanf("%d%d", &x, &y);
		//判断x，y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用！");
			}
		}
		else
		{
			printf("非法坐标，请重新输入！\n");
		}
	}
}

//电脑移动
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//判断棋盘是否满，返回1表示满，返回0表示未满
int IsFull(char board[ROW][COL], int row, int col )
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;//未满
		}
	}
	return 1;//满
}

//判断是否赢且返回
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//竖三行
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//判断是否平局
	if (1 == IsFull(board, ROW, COL))
	{
		return 'D';
	}
	return 'C';
}