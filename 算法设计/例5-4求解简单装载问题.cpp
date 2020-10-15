#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【问题描述】有n个集装箱要装上一艘载重量为W的轮船，其中集装箱i（1≤i≤n）的重量为wi。
//不考虑集装箱的体积限制，现要从这些集装箱中选出重量和小于等于W的若干装上轮船。
//例如，n = 5，W = 10，w = { 5，2，6，4，3 }时，
//其最佳装载方案是（1，1，0，0，1）或者（0，0，1，1，0），maxw = 10。
//【问题求解】采用带剪枝的回溯法求解。问题的表示如下：
int w[] = { 0,5,2,6,4,3 }; //各集装箱重量，不用下标0的元素
int n = 5,W = 10;
//求解的结果表示如下：
int maxw = 0;		   //存放最优解的总重量
int x[5];		   //存放最优解向量
//将上述数据设计为全局变量。
void dfs(int i, int tw, int rw, int op[]) //求解简单装载问题
{
	if (i > n)				//找到一个叶子结点
	{
		if (tw > maxw)
		{
			maxw = tw;			//找到一个满足条件的更优解,保存它
			for (int j = 1; j <= n; j++)	//复制最优解
				x[j] = op[j];
		}
	}
	else					//尚未找完所有集装箱
	{
		if (tw + w[i] <= W)			//左孩子结点剪枝
		{
			op[i] = 1;			//选取第i个集装箱
			dfs(i + 1, tw + w[i], rw - w[i], op);
		}
		if (tw + rw - w[i] > maxw)		//右孩子结点剪枝
		{
			op[i] = 0;			//不选取第i个集装箱,回溯
			dfs(i + 1, tw, rw - w[i], op);
		}
	}
}


