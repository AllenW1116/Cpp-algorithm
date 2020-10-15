#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【问题描述】对于给定的正整数n（n≥1），求1～n的所有全排列。
//【问题求解】这里采用增量蛮力法求解。见ppt57页。
//每一层的每个排列是一个集合（ 第n层由n个数进行排列；第n层的排列个数c（n）=c（n-1）*n  ）；
//全部排列构成一个幂集、最终的结果就是密集


vector<vector<int> > ps;		//存放幂集

void Insert(vector<int> s, int i, vector<vector<int> > &ps1)  //第i层正好插i个  参数：被插的集合 要插的元素（同时也是该元素插入的次数） 结果存在哪
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

