#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
using namespace std;
//【问题描述】设有n个独立的作业{ 1，2，…，n }，由m台相同的机器{ 1，2，…，m }进行加工处理，
//作业i所需的处理时间为ti（1≤i≤n），每个作业均可在任何一台机器上加工处理，
//但未完工前不允许中断，任何作业也不能拆分成更小的子作业。
//多机调度问题要求给出一种作业调度方案，使所给的n个作业在尽可能短的时间内由m台机器加工处理完成。

//【问题求解】贪心法求解多机调度问题的贪心策略是最长处理时间作业优先，即把处理时间最长的作业分配给最先空闲的机器，
//这样可以保证处理时间长的作业优先处理，从而在整体上获得尽可能短的处理时间。
//问题表示
int n = 7;
int m = 3;
struct NodeType				//优先队列结点类型
{
	int no;					//作业序号
	int t;					//执行时间
	int mno;					//机器序号
	bool operator<(const NodeType& s) const  //一旦重构了操作符，sort会变成【递减排序】，priority_queue也会变成【小根堆】
	{
		return t > s.t;
	}			//按t越小越优先出队
};

struct NodeType A[] = { {1,2},{2,14},{3,4},{4,16},{5,6},{6,5},{7,3} };

void solve()				//求解多机调度问题
{
	NodeType e;
	if (n <= m)
	{
		printf("为每一个作业分配一台机器\n");
		return;
	}
	sort(A, A + n);			//按t递减排序
	priority_queue<NodeType> qu;	//小根堆
	for (int i = 0; i < m; i++)		//先分配m个作业，每台机器一个作业
	{
		A[i].mno = i + 1;			//作业对应的机器编号
		printf("  给机器%d分配作业%d,执行时间为%2d,占用时间段:[%d,%d]\n",
			A[i].mno, A[i].no, A[i].t, 0, A[i].t);
		qu.push(A[i]);
	}
	for (int j = m; j < n; j++)		//分配余下作业
	{
		e = qu.top(); qu.pop();		//出队e
		printf("  给机器%d分配作业%d,执行时间为%2d,占用时间段:[%d,%d]\n",
			e.mno, A[j].no, A[j].t, e.t, e.t + A[j].t);
		e.t += A[j].t;
		qu.push(e);			//e进队
	}
}





