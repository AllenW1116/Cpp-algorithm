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



//采用直接蛮力法求解，将1～n的存放在数组a中，求解问题变为构造集合a的所有子集。
//设集合a[0..2] = { 1，2，3 }，其所有子集对应的二进制位及其十进制数如下。
void inc(int b[], int n)	//将b表示的【二进制数增1】
{
	for (int i = 0; i < n; i++)	//遍历数组b
	{
		if (b[i])		//将元素1改为0
			b[i] = 0;
		else			//将元素0改为1并退出for循环
		{
			b[i] = 1;
			break;
		}
	}
}
void PSet(int a[], int b[], int n)	//求幂集
{
	int i, k;
	int pw = (int)pow(2, n);		//求2^n
	printf("1～%d的幂集:\n  ", n);
	for (i = 0; i < pw; i++)			//执行2^n次
	{
		printf("{ ");
		for (k = 0; k < n; k++)		//执行n次
			if (b[k])
				printf("%d ", a[k]);
		printf("} ");
		inc(b, n);			//b表示的二进制数增1
	}
	printf("\n");
}

