//;ͷ�ļ�
#ifndef  __GAME_H__

#define __GAME_H__

#include<string.h>

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

void InitBoard(char board[][3], int row, int col);

void ShowBoard(char board[][3], int row, int col);

void PlayerMove(char board[][3], int row, int col);//:����ƶ�

char IsWin(char board[][3], int row, int col);

void ComputerMove (char board[][3], int row, int col);//:�����ƶ�

#endif//__GAME_H__
