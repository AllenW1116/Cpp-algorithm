#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【问题描述】给定n个不同的正整数集合w = （w1，w2，…，wn）和一个正整数W，
//要求找出w的子集s，使该子集中所有元素的和为W。
//例如，当n = 4时，w = （11，13，24，7），W = 31，则满足要求的子集为（11，13，7）和（24，7）。
int x[];//解向量
int n=4;
int W = 31;
int w[] = { 11,13,24,7 };
void dfs(int i, int tw, int rw, int x[]) //求解子集和
{
	if (i > n)				//找到一个叶子结点
	{
		if (tw == W)			//找到一个满足条件的解,输出它
			dispasolution(x);
	}
	else					//尚未找完所有整数
	{
		if (tw + w[i] <= W)			//左孩子结点剪枝
		{
			x[i] = 1;			//选取第i个整数
			dfs(i + 1, tw + w[i], rw - w[i], x);
		}
		if (tw + rw - w[i] >= W)		//右孩子结点剪枝
		{
			x[i] = 0;			//不选取第i个整数,回溯
			dfs(i + 1, tw, rw - w[i], x);
		}
	}
}


//判断子集和问题是否存在解
//如果要判断问题是否存在解（一个或者多个），可以将求解函数改为bool类型，
//当找到任何一个解时返回true，否则返回false。需要注意的是当问题没有解时需要搜索所有解空间。

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

bool solve()				//判断子集和问题是否存在解
{
	int rw = 0;
	for (int j = 1; j <= n; j++)		//求所有整数和rw
		rw += w[j];
	return dfs(1, 0, rw);		//i从1开始
}



