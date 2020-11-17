#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
using namespace std;
//【问题描述】设有编号为1、2、…、n的n个物品，它们的重量分别为w1、w2、…、wn，价值分别为v1、v2、…、vn，
//其中wi、vi（1≤i≤n）均为正数。有一个背包可以携带的最大重量不超过W。
//求解目标：在不超过背包负重的前提下，使背包装入的总价值最大（即效益最大化），
//与0 / 1背包问题的区别是，这里的每个物品可以取一部分装入背包。
//例解：ppt26页！
//很容易想到，这个问题下一定要考量【物品的单位价值】！
//因为要将物品【按照单位价值降序排列】
//贪心策略：选择单位重量价值最大的物品。
//每次从物品集合中选择单位重量价值最大的物品，如果其重量小于背包容量，
//就可以把它装入，并将背包容量减去该物品的重量，然后就面临了一个最优子问题——
//它同样是背包问题，只不过背包容量减少了，物品集合减少了。
//因此背包问题具有最优子结构性质。


//问题表示
int n = 5;
double W = 100;				//限重
struct NodeType
{
	double w;
	double v;
	double p;				//p=v/w
	bool operator<(const NodeType& s) const
	{
		return p > s.p;			//按p递减排序
	}
};
NodeType A[] = { {0},{10,20},{20,30},{30,66},{40,40},{50,60} };						//下标0不用
//求解结果表示
double V;				//最大价值
double x[MAXN];     //注意是double！因为很可能装入一部分！
void Knap()			//求解背包问题并返回总价值
{
	V = 0;				//V初始化为0
	double weight = W;		//背包中能装入的【余下重量】；也就是说该值在算法过程中是不断减小的！
	memset(x, 0, sizeof(x));	//初始化x向量
	int i = 1;
	while (A[i].w < weight)	//物品i能够全部装入时循环
	{
		x[i] = 1;			//装入物品i
		weight -= A[i].w;		//减少背包中能装入的余下重量
		V += A[i].v;		//累计总价值
		i++;			//继续循环
	}
	if (weight > 0)		//当余下重量大于0
	{
		x[i] = weight / A[i].w;	//将物品i的一部分装入
		V += x[i] * A[i].v;		//累计总价值
	}
}








