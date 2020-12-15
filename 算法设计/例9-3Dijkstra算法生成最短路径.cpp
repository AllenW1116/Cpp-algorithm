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
//算法过程：ppt32页
//求单源多重点最短路径。结果是源点到每一个顶点的最短距离。

//设置一个数组dist[0..n - 1]，dist[i]用来保存从源点v到顶点i的目前最短路径长度，
//它的初值为<v，i>边上的权值，若顶点v到顶点i没有边，则权值定为∞。
//以后每考虑一个新的中间点时，dist[i]的值可能被修改而变小。
//设置一个数组path[0..n - 1]用于保存最短路径。
//path[j]保存当前最短路径中的前一个顶点的编号，它的初值为源点v的编号（顶点v到顶点j有边时）或 - 1（顶点v到顶点i无边时）。
void Dijkstra(Matgraph g, int v)		//Dijkstra算法
{
    int dist[MAXV], path[MAXV];
    int S[MAXV];  //S[i]=1:i点在S中。为0在V中。
    int mindis, i, j, u;
    for (i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v][i];		//距离初始化
        S[i] = 0;				//S[]置空
        if (g.edges[v][i] < INF)		//路径初始化
            path[i] = v;	//顶点v到顶点i有边时，置顶点i的前一个顶点为v
        else
            path[i] = -1;	//顶点v到顶点i没边时，置顶点i的前一个顶点为-1
    }
    S[v] = 1; path[v] = 0;			//源点编号v放入s中
    for (i = 0; i < g.n; i++)	//循环直到所有顶点的最短路径都求出
    {
        mindis = INF;		//mindis求最小路径长度
        for (j = 0; j < g.n; j++)	//选取不在s中且具有最小距离的顶点u
            if (S[j] == 0 && dist[j] < mindis)
            {
                u = j;
                mindis = dist[j];
            }
        S[u] = 1;				//顶点u加入s中
        for (j = 0; j < g.n; j++)		//修改不在S中的顶点的距离
            if (S[j] == 0)
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]) //第一个条件其实可以不加
                {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
    }
    //Dispath(g,dist,path,S,v);	输出最短路径
}
void Dispath(Matgraph g, int *dist, int *path,int* S, int v) {
    int cur = 0;
    vector<int> apath;
    vector<int>::reverse_iterator it;  //定义反向迭代器
    for (int i = 0; i < g.n; i++) {//输出源点到每一个顶点的路径
        cout << "源点到顶点" << i << "的路径："<<endl;
        cur = i;
        while (path[cur] != 0 || path[cur] != -1) {
            apath.push_back(cur);
            cur = path[cur];
        }
        //path[cur]==0,cur=v
        if (cur == v) {//has path
            apath.push_back(v);
            for (it = apath.rbegin(); it != apath.rend(); ++it) {//反向输出
            cout << *it << " ";
             }
        }
        //path[cur]==-1,cur=nonsense
        cout << endl;
    }
}



