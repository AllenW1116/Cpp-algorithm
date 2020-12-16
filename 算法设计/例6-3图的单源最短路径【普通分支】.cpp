#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>
#define MAXN 2			
using namespace std;
//【问题描述】给定一个【带权有向】图G = （V，E），其中每条边的权是一个正整数。
//另外，还给定V中的一个顶点v，称为源点。计算从源点到其他所有顶点的最短路径长度。这里的长度是指路上各边权之和。
struct NodeType		//队列结点类型
{
	int vno;			//顶点编号
	int length;			//原点到该点的路径长度
};
//用dist数组存放源点v出发的最短路径长度，dist[i]表示源点v到顶点i的最短路径长度，初始时所有dist[i]值为∞。
//用prev数组存放最短路径，prev[i]表示源点v到顶点i的最短路径中顶点i的【前驱顶点。】
//问题图解：ppt37页！

//问题表示
int n;			//图顶点个数
int a[MAXN][MAXN];	//图的邻接矩阵
int v;			//源点
//求解结果表示
int dist[MAXN];	//dist[i]源点到顶点i的最短路径长度
int prev[MAXN];	//prev[i]表示源点到j的最短路径中顶点j的前驱顶点

void bfs(int v)			//求解算法
{
	NodeType e, e1;
	queue<NodeType> pqu;
	e.vno = v;				//建立源点结点e（根结点）
	e.length = 0;
	pqu.push(e);			//源点结点e进队
	dist[v] = 0;
	while (!pqu.empty())		//队列不空循环
	{
		e = pqu.front(); pqu.pop();	//出队列结点e
		for (int j = 0; j < n; j++)
		{
			if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j])
			{	//剪枝：e.vno到顶点j有边并且路径长度更短
				dist[j] = e.length + a[e.vno][j];
				prev[j] = e.vno;
				e1.vno = j;		//建立相邻顶点j的结点e1
				e1.length = dist[j];
				pqu.push(e1);		//结点e1进队
			}
		}
	}
}

