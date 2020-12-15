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
//弗洛伊德算法基于【动态规划】方法。
//采用一个二维数组A存放当前顶点之间的最短路径长度，即分量A[i][j]表示当前顶点i到顶点j的【最短路径长度】，
//通过递推产生一个矩阵序列A0、A1、…、Ak、…、An - 1。
//其中Ak[i][j]表示从顶点i到顶点j的路径上所经过的顶点编号不大于k的最短路径长度。
void Floyd(Matgraph g)
{
    int A[MAXV][MAXV],path[MAXV][MAXV];
    int i,j,k;
    for (i = 0; i < g.n; i++)  //初始化
        for (j = 0; j < g.n; j++)
        {
            A[i][j] = g.edges[i][j];
            if (i != j && g.edges[i][j] < INF)
                path[i][j] = i;		//顶点i到j有边时
            else
                path[i][j] = -1;		//顶点i到j没有边时
        }
    for (k = 0; k < g.n; k++) //循环意义：第k个递推矩阵
    {
        for (i = 0; i < g.n; i++)
            for (j = 0; j < g.n; j++)
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];	//修改最短路径
                }
    }
    //Dispath(g,A,path);			//输出最短路径
}
