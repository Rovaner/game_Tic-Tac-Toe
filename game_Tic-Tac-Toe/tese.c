#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("*************************\n");
	printf("******** 1. PLAY ********\n");
	printf("*************************\n");
	printf("******** 0. EXIT ********\n");
	printf("*************************\n");
}

//游戏的整个代码实现
void game()
{
	char ret = 0;
	//数组-存放走出的棋盘信息
	char board[ROW][COL] = { 0 };//全部空格
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢！\n");
	}
	else
	{
		printf("平局！\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("Please choose:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Exit game!");
			break;
		default:
			printf("ERROR!Please choose again!\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}