#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【问题描述】有n个重量分别为{ w1，w2，…，wn }的物品，它们的价值分别为{ v1，v2，…，vn }，
//给定一个容量为W的背包。设计从这些物品中选取一部分物品放入该背包的方案，
//每个物品要么选中要么不选中，要求选中的物品不仅能够放到背包中，而且具有最大的价值。
//
//【问题求解】对于n个物品、容量为W的背包问题，采用前面求幂集的方法求出所有的物品组合。
//对于每一种组合，计算其总重量sumw和总价值sumv，当sumw小于等于W时，该组合是一种解，
//并通过比较将最佳方案保存在maxsumw和maxsumv中，最后输出所有的解和最佳解。
//若有1234四个物品，{12}{23}{123}分别代表“”“”“”。
//所有的选择方案，自然就是{1 2 3 4}的幂集。幂集中的每个集合是一种解决方案，也对应一个sumw和sumv

vector<vector<int> > ps;		//存放幂集
void PSet(int n)			//求1～n的幂集ps
{
	vector<vector<int> > ps1;		//子幂集
	vector<vector<int> >::iterator it;//幂集迭代器
	vector<int> s;
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

void Knap(int w[], int v[], int W)	//求所有的方案和最佳方案；物品重量数组 物品价值数组 背包容量
{
	int count = 0;			//方案编号
	int sumw, sumv;			//当前方案的总重量和总价值
	int maxi, maxsumw = 0, maxsumv = 0;	//最佳方案的编号、总重量和总价值
	vector<vector<int> >::iterator it;	//幂集迭代器
	vector<int>::iterator sit;			//幂集里的集合元素迭代器
	printf("  序号\t选中物品\t总重量\t总价值\t能否装入\n");// \t是制表
	for (it = ps.begin(); it != ps.end(); ++it)	//扫描ps中每一个集合元素
	{
		printf("  %d\t", count + 1);
		sumw = sumv = 0;
		printf("{");
		for (sit = (*it).begin(); sit != (*it).end(); ++sit)
		{
			printf("%d ", *sit);
			sumw += w[*sit - 1];			//w数组下标从0开始，而ps中的下标从1开始
			sumv += v[*sit - 1];			//v数组下标从0开始，而ps中的下标从1开始
		}
		printf("}\t\t%d\t%d  ", sumw, sumv);
		if (sumw <= W)
		{
			printf("能\n");
			if (sumv > maxsumv)			//比较求最优方案
			{
				maxsumw = sumw;
				maxsumv = sumv;
				maxi = count;
			}
		}
		else printf("否\n");
		count++;					//方案编号增加1
	}
	printf("最佳方案为: ");
	printf("选中物品");
	printf("{ ");
	for (sit = ps[maxi].begin(); sit != ps[maxi].end(); ++sit)
		printf("%d ", *sit);
	printf("},");
	printf("总重量:%d,总价值:%d\n", maxsumw, maxsumv);
}

	





