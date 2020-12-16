#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【问题描述】有一个2k×2k（k > 0）的棋盘，恰好有一个方格与其他方格不同，称之为特殊方格。
//现在要用如下的L型骨牌覆盖除了特殊方格外的其他全部方格，骨牌可以任意旋转，并且任何两个骨牌不能重叠。请给出一种覆盖方法。
//具体是怎么覆盖的需要看一下ppt chap3 80页
//用（tr，tc）表示一个象限左上角方格的坐标（最左上角），（dr，dc）是特殊方格所在的坐标，size是棋盘的行数和列数。
//用二维数组board存放覆盖方案，用tile全局变量表示L型骨牌的编号（从整数1开始），board中3个相同的整数表示一个L型骨牌。

#define MAX 1025
//问题表示
int k;				//棋盘大小
int x, y;				//特殊方格的位置
//求解问题表示
int board[MAX][MAX];
int tile = 1;   //骨牌编号 从1开始


void ChessBoard(int tr, int tc, int dr, int dc, int size) //tr tc坐标左上角（源点） dr dc特殊方格坐标
{
	if (size == 1) return;			//递归出口
	int t = tile++;			//取一个L型骨，其牌号为tile
	int s = size / 2;			//分割棋盘
	//考虑左上角象限
	if (dr < tr + s && dc < tc + s)		//特殊方格在此象限中
		ChessBoard(tr, tc, dr, dc, s);
	else					//此象限中无特殊方格
	{
		board[tr + s - 1][tc + s - 1] = t;		//用t号L型骨牌覆盖右下角（特殊方格不在第一象限，缺角肯定不在这，先给它填上）
		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
		//将右下角作为特殊方格继续处理该象限（它不能再填了，可以作为这个象限的特殊方格）
	}
	//考虑右上角象限
	if (dr < tr + s && dc >= tc + s)
		ChessBoard(tr, tc + s, dr, dc, s);	//特殊方格在此象限中 
	else					//此象限中无特殊方格
	{
		board[tr + s - 1][tc + s] = t;		//用t号L型骨牌覆盖左下角
		ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
		//将左下角作为特殊方格继续处理该象限
	}
	//处理左下角象限
	if (dr >= tr + s && dc < tc + s)		//特殊方格在此象限中
		ChessBoard(tr + s, tc, dr, dc, s);
	else					//此象限中无特殊方格
	{
		board[tr + s][tc + s - 1] = t;  		//用t号L型骨牌覆盖右上角
		ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
		//将右上角作为特殊方格继续处理该象限
	}
	//处理右下角象限
	if (dr >= tr + s && dc >= tc + s)	//特殊方格在此象限中
		ChessBoard(tr + s, tc + s, dr, dc, s);
	else				//此象限中无特殊方格
	{
		board[tr + s][tc + s] = t;  	//用t号L型骨牌覆盖左上角
		ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
		//将左上角作为特殊方格继续处理该象限
	}
}

