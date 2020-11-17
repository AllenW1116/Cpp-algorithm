#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
using namespace std;
//【问题描述】假设有一个需要使用某一资源的n个活动所组成的集合S，S = { 1，…，n }。该资源任何时刻只能被一个活动所占用，
//活动i有一个开始时间bi和结束时间ei（bi < ei），其执行时间为ei - bi，假设最早活动执行时间为0。
//一旦某个活动开始执行，中间不能被打断，直到其执行完毕。若活动i和活动j有bi≥ej或bj≥ei，则称这两个活动兼容。
//设计算法求一种最优活动安排方案，使得所有安排的活动个数最多。
//【注意】需要先将任务按照结束时间递增排列

//问题表示
struct Action			//活动的类型声明
{
	int b;			//活动起始时间
	int e;			//活动结束时间
	bool operator<(const Action& s) const	//重载<关系函数
	{
		return e <= s.e;		//用于按活动结束时间递增排序
	}
};
int n = 11;
Action A[] = { {0},{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15} };	//下标0不用
//求解结果表示
bool flag[MAX];		//标记选择的活动
int Count = 0;			//选取的兼容活动个数


void solve()				//求解最大兼容活动子集
{
	memset(flag, 0, sizeof(flag));	//初始化为false
	sort(A + 1, A + n + 1);			//A[1..n]按活动结束时间递增排序
	int preend = 0;			//前一个兼容活动的结束时间
	for (int i = 1; i <= n; i++)		//扫描所有活动
	{
		if (A[i].b >= preend)		//找到一个兼容活动
		{
			flag[i] = true;		//选择A[i]活动
			preend = A[i].e;		//更新preend值
		}
	}
}




