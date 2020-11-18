#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//算法过程：ppt7页
//两个数组closest和lowcost，它们记录从U到V - U具有最小权值的边，
//对于某个j∈V - U，closest[j]存储该边依附的在U中的顶点编号（j点离集合U最近的那条边连着的是哪个点），lowcost[j]存储该边的权值。ppt6页！
//数据结构：邻接矩阵（带权）
typedef struct {
	int no;  //顶点的编号
	Infotype info; //顶点存的信息
}Vertextype;//图中一个顶点

typedef struct {
	int edges[50][50];  //邻接矩阵数组
	int n, e; //n点数，e边数
	Vertextype vexs[50]; //一维数组用于存放顶点
}MGraph; //一个邻接矩阵

void Prim(MGraph g, int v)	   //Prim算法 v为源点
{
	int lowcost[MAXV];
	int mincost;
	int closest[MAXV], i, j, k;
	for (j = 0; j < g.n; j++)	   //给初始化lowcost和closest数组，初始时集合U只包含源点
	{
		lowcost[j] = g.edges[v][j];
		closest[j] = v;
	}
	for (i = 1; i < g.n; i++)		//找出(n-1)个顶点
	{
		mincost = INF;
		for (j = 0; j < g.n; j++)		//在(V-U)中找出离U最近的顶点k
			if (lowcost[j] != 0 && lowcost[j] < mincost)
			{
				mincost = lowcost[j];
				k = j;			//k记录最近顶点的编号，准备把该节点加入U
			}
		printf(" 最短边(%d,%d)权为:%d\n", closest[k], k, mincost);
		lowcost[k] = 0;			//标记k已经加入U：lowcost=0，说明该节点已加入U！
		for (j = 0; j < g.n; j++)		//修改数组lowcost和closest：由于U中新加入了k节点，V-U中的节点距离U的最近距离可能就是它和k节点的距离
			if (g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])
			{
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
	}
}



