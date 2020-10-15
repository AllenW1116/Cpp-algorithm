#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【问题描述】对于给定的正整数n（n≥1），求1～n构成的集合的所有子集（幂集）。
//
//采用增量蛮力法求解1～n的幂集。过程见ppt45页。
//最开始一个空集合，
//每次加一个元素进去，并求出全部幂集；
//再加一个新元素，再求幂集……
//在实现算法时，用一个vector<int>容器表示一个集合元素，用vector<vector<int> >容器存放幂集（即集合的集合）。


vector<vector<int> > ps;		//存放幂集（应当是一个全局变量，存最终的结果）
void PSet(int n)			//求1～n的幂集ps
{
	vector<vector<int> > ps1;		//子幂集
	vector<vector<int> >::iterator it;//幂集迭代器
	vector<int> s;					//一个空集合
	ps.push_back(s);			//添加{}空集合元素
	for (int i = 1; i <= n; i++)		//循环添加1～n
	{
		ps1 = ps;				//ps1存放上一步得到的幂集
		for (it = ps1.begin(); it != ps1.end(); ++it)
			(*it).push_back(i);		//在ps1的每个集合元素末尾添加i
		for (it = ps1.begin(); it != ps1.end(); ++it)
			ps.push_back(*it);		//将ps1的每个集合元素添加到ps中
	}
}


