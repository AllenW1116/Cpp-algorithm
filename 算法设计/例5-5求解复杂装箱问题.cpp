#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【问题描述】有一批共n个集装箱要装上两艘载重量分别为c1和c2的轮船，
//其中集装箱i的重量为wi，且w1 + w2 + … + wn≤c1 + c2。
//装载问题要求确定是否有一个合理的装载方案可将这些集装箱装上这两艘轮船。如果有，找出一种装载方案。
//【问题求解】如果一个给定的复杂装载问题有解，则可以采用如下方式得到一个装载方案：
//首先将第一艘轮船尽可能装满，然后将剩余的集装箱装在第二艘轮船上。
//求解过程：
//（1）将尽可能多的集装箱装到第一艘轮船上，得到解向量x。
//（2）累计第一艘轮船装完后剩余的集装箱重量sum。
//（3）若sum <= c2，表示第二艘轮船可以装完，返回true；否则表示第二艘轮船不能装完，返回false。

//问题表示
int w[] = { 0,10,40,40 };		//各集装箱重量,不用下标0的元素
int n = 3;
int c1 = 50, c2 = 50;
int maxw = 0;			//存放第一艘轮船最优解的总重量
int x[4];			//存放第一艘轮船最优解向量(也就是dfs的op参数，为1时表示该箱子被装，为0表示没被装

void dfs(int i, int tw, int rw, int op[]) 	//求第一艘轮船的最优解
{
	if (i > n)					//找到一个叶子结点
	{
		if (tw > maxw)
		{
			maxw = tw;				//找到一个满足条件的更优解
			for (int j = 1; j <= n; j++)		//复制最优解
				x[j] = op[j];
		}
	}
	else						//尚未找完所有集装箱
	{
		if (tw + w[i] <= c1)			//左孩子结点剪枝
		{
			op[i] = 1;				//选取第i个集装箱
			dfs(i + 1, tw + w[i], rw - w[i], op);
		}
		if (tw + rw - w[i] > maxw)			//右孩子结点剪枝
		{
			op[i] = 0;				//不选取第i个集装箱,回溯
			dfs(i + 1, tw, rw - w[i], op);
		}
	}
}


//在第一艘轮船装满后考虑第2艘轮船是否能够装完剩余的集装箱？
bool solve()			//求解复杂装载问题
{
	int sum = 0;			//累计第一艘轮船装完后剩余的集装箱重量
	for (int j = 1; j <= n; j++)
		if (x[j] == 0)
			sum += w[j];
	if (sum <= c2)		//第二艘轮船可以装完
		return true;
	else				//第二艘轮船不能装完
		return false;
}




