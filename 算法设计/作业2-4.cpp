
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//4. 设计求解有重复元素的排列问题的算法，设有n个元素a[] = { a0，a1，…，an - 1)，
//其中可能含有重复的元素，求这些元素的所有不同排列。
//如a[] = {1，1，2}，输出结果是（1，1，2)，（1，2，1），（2，1，1）。
//用蛮力法求出所有排列，再加入存放结果的幂集时首先遍历，如果重复就不添加
//测试数据：
int a[] = { 1,2,2,3,4 }; 
int n = 5;

vector<vector<int> > ps;		//存放幂集

bool repeat(vector<int> s, vector < vector<int> > p) {
	vector<vector<int> >::iterator it;
	bool repeatflag = false;
	for (it = p.begin(); it != p.end(); ++it) {
		if ((*it) == s) repeatflag = true;
	}
	return repeatflag;
}

void Insert(vector<int> s, int i, vector<vector<int> > &ps1)
{
	vector<int> s1;
	vector<int>::iterator it;
	for (int j = 0; j < i + 1; j++)	//在s(含i-1个整数)的每个位置插入
	{
		s1 = s;
		it = s1.begin() + j;	//求出插入位置
		s1.insert(it, a[i]);	//插入整数i
		if (!repeat(s1, ps1)) {    //ps1不包含s1
			ps1.push_back(s1);
		}//添加到ps1中
	}
}

void Perm(int a[])			//a[]的所有排列
{
	vector<vector<int> > ps1;		//临时存放子排列
	vector<vector<int> >::iterator it;//全排列迭代器
	vector<int> s, s1;
	s.push_back(a[0]);
	ps.push_back(s);
	for (int i = 1; i < n; i++)		//循环添加
	{
		ps1.clear();			//ps1存放插入i的结果
		for (it = ps.begin(); it != ps.end(); ++it)
		{
			Insert(*it, i, ps1);
		}
		ps = ps1;
	}
}

int main() {
	Perm(a);
	vector<vector<int> >::iterator it;
	vector<int> ::iterator it1;
	for (it = ps.begin(); it != ps.end(); ++it)
	{
		for (it1 = (*it).begin(); it1 != (*it).end(); ++it1) {
			cout << (*it1) << " ";
		}
		cout << endl;
	}
	return 0; //测试通过！
}