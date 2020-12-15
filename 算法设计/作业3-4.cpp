//4.给出一种方法求无环带权连通图（所有权值非负）中从顶点s到顶点t的一条最长简单路径。
//使用贝尔曼福特算法，将正权值置为负数求最短路径，即求得了最长路径
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<vector>
#define MAXV 10
#define INF 500
using namespace std;
typedef struct {
    int edges[50][50];  //邻接矩阵数组
    int n, e; //n点数，e边数
    //Vertextype vexs[50]; //一维数组用于存放顶点
}MGraph; //一个邻接矩阵
void Dispath(MGraph g, int* dist, int* path, int v, int t);
void BellmanFord(MGraph g, int v, int t) //dist[t]即为答案
{
    int i, k, u;
    int dist[MAXV], path[MAXV];
    for (i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v][i];		//对dist(1)[i]初始化
        if (i != v && dist[i] < INF)
            path[i] = v;			//对path(1)[i]初始化
        else
            path[i] = -1;
    }
    for (k = 2; k < g.n; k++)
        //从dist1[u]递推出dist2[u]， …，distn-1[u]循环n-1次
    {
        for (u = 0; u < g.n; u++)		//修改每个顶点的dist和path
        {
            if (u != v)
            {
                for (i = 0; i < g.n; i++)	//考虑其他每个顶点
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
    Dispath(g, dist, path, v, t);	//输出最短路径及长度
}
void Dispath(MGraph g, int* dist, int* path, int v, int t) {
    int n = g.n;//顶点个数
    int end = t;

    vector<int> apath;
    apath.push_back(t);
    //倒序输出path
    while (path[t] != 0) {

        apath.push_back(path[t]);
        t = path[t];
    }
    if (path[apath.back()] == v) {  //原点可以到达该点
        apath.push_back(v);//将源点加入
        cout << "最长路径为：";
        vector<int>::reverse_iterator it;		//定义反向迭代器
        for (it = apath.rbegin(); it != apath.rend(); ++it) {//反向输出
            cout << *it << " ";
        }
        cout << "长度为" << -dist[end];
    }
}
int main() {
    MGraph M = { { {0,3,4,INF,17},
        {INF,0,8,5,11},
        {INF,INF,0,INF,10},
        {INF,INF,INF,0,5},
        {INF,INF,INF,INF,0} },5,8 };
    //邻接矩阵置负
    for (int i = 0; i < M.n; i++) {
        for (int j = 0; j < M.n; j++) {
            if (M.edges[i][j] != INF) { M.edges[i][j] = -M.edges[i][j]; }
        }
    }
    BellmanFord(M, 0, 4);
    return 0;
}
