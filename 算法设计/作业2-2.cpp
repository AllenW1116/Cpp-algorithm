#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//2. 设计一个算法求解简单装载问题，设有一批集装箱要装上一艘载重量为W的轮船，
//其中编号为i（0≤i≤n - 1）的集装箱的重量为wi。现要从n个集装箱中选出若干装上轮船，
//使它们的重量之和正好为W。如果找到任一种解返回true，否则返回false。

//这是一个子集求和的问题
//当找到任何一个解时返回true，否则返回false。需要注意的是当问题没有解时需要搜索所有解空间。
//样例数据：
int n = 5;
int W = 40;
int w[] = { 11,13,24,7,9 };

bool dfs(int i, int tw, int rw)	  		//求解子集和
{
	if (i > n)					//找到一个叶子结点
	{
		if (tw == W)				//找到一个满足条件的解
			return true;
	}
	else						//尚未找完所有物品
	{
		if (tw + w[i] <= W)				//左孩子结点剪枝
			return dfs(i + 1, tw + w[i], rw - w[i]);	//选取第i个整数
		if (tw + rw - w[i] >= W)			//右孩子结点剪枝
			return dfs(i + 1, tw, rw - w[i]);		//不选取第i个整数,回溯
	}
	return false;
}

int main() {
	int i = 0;
	int tw = 0;
	int rw = 64;
	cout << dfs(i, tw, rw); //输出1 通过
	return 0;
}