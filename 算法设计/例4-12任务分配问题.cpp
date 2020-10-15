#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【问题描述】有n（n≥1）个任务需要分配给n个人执行，每个任务只能分配给一个人，每个人只能执行一个任务。
//第i个人执行第j个任务的成本是c[i][j]（1≤i，j≤n）。求出总成本最小的分配方案。
//【问题求解】所谓一种分配方案就是由第i个人执行第j个任务，用（a1，a2，…，an）表示，
//即第1个人执行第a1个任务，第2个人执行第a2个任务，以此类推。全部的分配方案恰好是1～n的全排列。
//这里采用增量穷举法求出所有的分配方案ps（全排列），再计算出每种方案的成本，比较求出最小成本的方案，即最优方案。




//先来例4-11中的蛮力求全排列算法：
vector<vector<int> > ps;		//存放幂集

void Insert(vector<int> s, int i, vector<vector<int> > &ps1)
//在每个集合元素中间插入i得到ps1
{
	vector<int> s1;
	vector<int>::iterator it;
	for (int j = 0; j < i; j++)	//在s(含i-1个整数)的每个位置插入i
	{
		s1 = s;
		it = s1.begin() + j;	//求出插入位置
		s1.insert(it, i);	//插入整数i
		ps1.push_back(s1);	//添加到ps1中
	}
}

void Perm(int n)			//求1～n的所有全排列
{
	vector<vector<int> > ps1;		//临时存放子排列
	vector<vector<int> >::iterator it;//全排列迭代器
	vector<int> s, s1;
	s.push_back(1);
	ps.push_back(s);			//添加{1}集合元素
	for (int i = 2; i <= n; i++)		//循环添加1～n
	{
		ps1.clear();			//ps1存放插入i的结果
		for (it = ps.begin(); it != ps.end(); ++it)
			Insert(*it, i, ps1);		//在每个集合元素中间插入i得到ps1
		ps = ps1;
	}
}

//先得列出人员、任务分配矩阵
int c[][4] = { {9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4} };


void Allocate(int n, int &mini, int &minc)  //此例n应=4
//求任务分配问题的最优方案
{
	Perm(n);				//求出全排列ps
	for (int i = 0; i < ps.size(); i++)	//求每个方案的成本
	{
		int cost = 0;
		for (int j = 0; j < ps[i].size(); j++)
			cost += c[j][ps[i][j] - 1];   //c是人员、任务分配矩阵
		if (cost < minc)			//比较求最小成本的方案
		{
			minc = cost;
			mini = i;
		}
	}
}


