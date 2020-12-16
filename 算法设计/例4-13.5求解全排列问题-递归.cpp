#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
vector<vector<int> > ps;		//存放全排列
void Insert(vector<int> s, int i, vector<vector<int> >& ps1)
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