#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//之前我们用循环的方式求解了幂集问题。现使用递归：
//大问题：f(i，n)用于添加i～n整数（共需添加n - i + 1个整数）产生的幂集ps。
//小问题：f(i + 1，n)用于添加i + 1～n的整数（共需添加n - i个整数）产生的幂集ps。
//f(1，n)就是生成1～n的整数集合对应的幂集ps。
//即：把一次单独的插入操作拿出来，用它来递归



vector<vector<int> > ps;			//存放幂集

void Inserti(int i)
//向幂集ps中每个集合元素添加i并插入到ps中
{
	vector<vector<int> > ps1;			//子幂集
	vector<vector<int> >::iterator it;	//幂集迭代器
	ps1 = ps;					//ps1存放原来的幂集
	for (it = ps1.begin(); it != ps1.end(); ++it)
		(*it).push_back(i);	//在ps1的每个集合元素末尾添加i
	for (it = ps1.begin(); it != ps1.end(); ++it)
		ps.push_back(*it);	//将ps1的每个集合元素添加到ps中
}

void PSet(int i, int n)   //求1～n的幂集ps
{
	if (i <= n)
	{
		Inserti(i);	//将i插入到现有子集中产生新子集
		PSet(i + 1, n);	//递归调用
	}
}


