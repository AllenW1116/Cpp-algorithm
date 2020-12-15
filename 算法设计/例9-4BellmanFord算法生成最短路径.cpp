#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
#include"邻接矩阵.h"
using namespace std;
#define INF 32767
//求单源的最短路径（有点动态规划那味儿）
//算法过程：ppt44页
void BellmanFord(Matgraph g,int v)
{
    int i,k,u;
    int dist[MAXV],path[MAXV];
    for (i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v][i];		//对dist(1)[i]初始化
        if (i != v && dist[i] < INF)
            path[i] = v;			//对path(1)[i]初始化
        else
            path[i] = -1;
    }
    for (k = 2; k < g.n; k++)//循环意义：求第二轮及以后的dist
        //从dist1[u]递推出dist2[u]， …，distn-1[u]循环n-1次
    {
        for (u = 0; u < g.n; u++)		//循环意义：这一轮中每个顶点的dist和path.
        {
            if (u != v)
            {
                for (i = 0; i < g.n; i++)	//循环意义：求每一个顶点的dist path，需要考虑上一轮所有顶点的dist path
                {
                    if (g.edges[i][u]<INF &&
                        dist[u]>dist[i] + g.edges[i][u])
                    {
                        dist[u] = dist[i] + g.edges[i][u];
                        path[u] = i;
                    }
                }
            }
        }
    }
    //Dispath(g，dist，path，v);	//输出最短路径及长度
}
