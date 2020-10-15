#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include"邻接表.h"
#include"邻接矩阵.h"
#include<queue>
using namespace std;

//【问题描述】有如下8 * 8的迷宫图：
//OXXXXXXX
//OOOOOXXX
//XOXXOOOX
//XOXXOXXO
//XOXXXXXX
//XOXXOOOX
//XOOOOXOO
//XXXXXXXO
//其中，O表示通路方块，X表示障碍方块。
//假设入口是位置（0，0），出口为右下角方块位置（7，7）。
//设计一个程序采用递归方法求指定入口到出口的一条迷宫路径。
//
//【问题求解】用n表示迷宫大小，二维数组Maze存放迷宫，
//从（x，y）方块可以试探上下左右4个方位，假设总是从方位0到方位3的顺序试探，
//各方位对应的水平方向偏移量H[4] = { 0，1，0， - 1 }，垂直偏移量V[4] = { -1，0，1，0 }。（上右下左的顺时针顺序）
//一个移动方向需要两个坐标来确定
//图解ppt104



//深度优先：
//为了避免重复，每走过一个方块，将对应的迷宫值由'O'改为' '（空字符），当回过来时将其迷宫值恢复为'O'。

//问题表示
int n = 8;				//迷宫大小
char Maze[8][8] =
{ {'O','X','X','X','X','X','X','X'},
	{'O','O','O','O','O','X','X','X'},
	{'X','O','X','X','O','O','O','X'},
	{'X','O','X','X','O','X','X','O'},
	{'X','O','X','X','X','X','X','X'},
	{'X','O','X','X','O','O','O','X'},
	{'X','O','O','O','O','X','O','O'},
	{'X','X','X','X','X','X','X','O'}
};
int H[4] = { 0, 1, 0, -1 };	//水平偏移量,下标对应方位号0～3
int V[4] = { -1, 0, 1, 0 };	//垂直偏移量

void DFS(int x, int y)	 	//求从(x,y)出发的一条迷宫路径
{
	if (x == n - 1 && y == n - 1) 		//找到一条路径,输出
	{
		Maze[n - 1][n - 1] = ' ';
		//disppath();
		return;
	}
	else
	{
		for (int k = 0; k < 4; k++)		//试探每一个方位
			if (x >= 0 && y >= 0 && x < n && y < n && Maze[x][y] == 'O')
			{	//若(x,y)方块的可走的
				Maze[x][y] = ' ';	//将该方块迷宫值设置为空字符
				DFS(x + V[k], y + H[k]);	//查找(x,y)周围的每一个相邻方块
				Maze[x][y] = 'O';
				//若从该相邻方块出发没有找到路径,恢复(x,y)迷宫值
			}
	}
}




//广度优先
//解法2：采用广度优先遍历方式，从（x，y）出发（初始为入口）搜索目标（出口）。
//由于STL中queue不能顺序遍历，这里采用一个数组作为非循环队列，
//front和rear分别为队头和队尾（初始时均设置为 - 1），每个进队元素有唯一的下标。

//问题表示
int n = 8;			//迷宫大小
char Maze[8][8] =
{ {'O','X','X','X','X','X','X','X'},
   {'O','O','O','O','O','X','X','X'},
   {'X','O','X','X','O','O','O','X'},
   {'X','O','X','X','O','X','X','O'},
   {'X','O','X','X','X','X','X','X'},
   {'X','O','X','X','O','O','O','X'},
   {'X','O','O','O','O','X','O','O'},
   {'X','X','X','X','X','X','X','O'}
};
int H[4] = { 0, 1, 0, -1 };	//水平偏移量,下标对应方位号0～3
int V[4] = { -1, 0, 1, 0 };	//垂直偏移量
struct Position		//队列元素类型
{
	int x, y;			//当前方块位置
	int pre;			//前驱方块的下标
};


Position qu[10];		//定义一个队列qu（position数组充当队列）
int front = -1, rear = -1;		//定义队头和队尾


void BFS(int x, int y)		//求从(x,y)出发的一条迷宫路径
{
	Position p, p1, p2;
	p.x = x; p.y = y; p.pre = -1;			//建立入口结点
	Maze[p.x][p.y] = '*';			//改为'*'避免重复查找
	rear++; qu[rear] = p;			//入口方块进队
	while (front != rear)			//队不空循环
	{
		front++; p1 = qu[front];			//出队方块p1
		if (p1.x == n - 1 && p1.y == n - 1)		//找到出口
		{
			//disppath(front);			//输出路径
			return;
		}
		for (int k = 0; k < 4; k++)			//试探p1的每个相邻方位
		{
			p2.x = p1.x + V[k];			//找到p1的相邻方块p2
			p2.y = p1.y + H[k];
			if (p2.x >= 0 && p2.y >= 0 && p2.x < n && p2.y < n
				&& Maze[p2.x][p2.y] == 'O')
			{					//方块p2有效并且可走
				Maze[p2.x][p2.y] = '*';		//改为'*'避免重复查找
				p2.pre = front;
				rear++;	qu[rear] = p2;		//方块p2进队
			}
		}
	}
}