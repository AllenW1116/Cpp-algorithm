#pragma once
#include<iostream>
#include"邻接矩阵.h"
//Djkstra算法
void DJDispath(Matgraph g, int dist[], int path[], int S[], int v);
void Djkstra(Matgraph g, int v) { //v为起始点
	int dist[50], path[50];
	int S[50];
	int MINdis, i, j, u;
	for (i = 0; i < g.n; i++) {
		dist[i] = g.edges[v][i]; //距离初始化
		S[i] = 0; //初始时都放在U中
		if (g.edges[v][i] < 32767)
			path[i] = v; //第一次迭代：顶点v到顶点i有边时，置顶点i的前一个顶点为v
		else
			path[i] = -1;//第一次迭代：顶点v到顶点i没有边，置为-1

	}
	S[v] = 1; path[v] = 0;  //源点v放入S；v的上一个结点置为0（不是-1！-1代表没路，0代表是v本身）

	for (i = 0; i < g.n - 1; i++) {//循环n-1次，直到v到所有其他结点的路径都被输出
		MINdis = INF;
		for (j = 0; j < g.n; j++) {  //选取不在S中且具有最小最短路长的顶点u
			if (S[j] == 0 && dist[j] < MINdis) {
				u = j;  //u存放即将加入S中的j结点
				MINdis = dist[j];
			}
		}
		S[u] = 1; //u加入S中
		for (j = 0; j < g.n; j++)
			if (S[j] == 0)
				if (dist[u] + g.edges[u][j] < dist[j]) {
					dist[j] = dist[u] + g.edges[u][j];
					path[j] = u;
				}
	}
	DJDispath(g, dist, path, S, v);

}

void DJDispath(Matgraph g, int dist[], int path[], int S[], int v) {
	int i, j, k;
	int apath[50], d;
	for (i = 0; i < g.n; i++)
		if (S[i] == 1 && i != v) {
			cout << "从顶点" << v << "到顶点" << i << "的路径长度为：" << dist[i] << " ";
			cout << "路径为：";
			d = 0; apath[d] = i;
			k = path[i];
			if (k == -1)
				cout << "无路径" << endl;
			else {
				while (k != v) { d++; apath[d] = k; k = path[k]; } //这层循环过后，v点到
															  //i点的路径上除了起始点v的
												 //其他点包括终点都倒着输入进apath【】中了
				d++; apath[d] = v;
				cout << apath[d]<<" ";
				for (j = d - 1; j >= 0; j--) { cout << apath[j] << " "; }
				cout << endl;

			}

		}
}


//Floyed算法(若距离为∞，请手动把距离输入为32767)
void FYDispath(Matgraph g, int A[50][50], int path[50][50]);
void Floyd(Matgraph g) {
	int A[50][50], path[50][50];
	int i, j, k;
	for(i=0;i<g.n;i++)   
		for (j = 0; j < g.n; j++) {  //双层循环给A【】【】和path【】【】初始化；
			A[i][j] = g.edges[i][j];
			if (i != j && g.edges[i][j] < 32767)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	for (k = 0; k < g.n; k++){
		for(i=0;i<g.n;i++)
			for (j = 0; j < g.n; j++) {
				if (A[i][k] + A[k][j] < A[i][j]) {  //更新
					A[i][j] = A[i][k] + A[k][j];   //修改dist【】
					path[i][j] = path[k][j];   //修改路径
				}
			}

	}
	FYDispath(g, A, path);
}

void FYDispath(Matgraph g, int A[50][50], int path[50][50]) {
	int i, j, k, s;
	int apath[50], d;
	for(i=0;i<g.n;i++)
		for (j = 0; j < g.n; j++) {
			if (A[i][j] != 32767 && i != j) {
				cout << i << "->" << j << "路径为：";
				k = path[i][j];
				d = 0; apath[d] = j; //添加路径终点
				while (k != -1) {  //添加路径中间点
					d++; apath[d] = k;
					k = path[i][k];
				}
				d++; apath[d] = i; //路径添加起点
				cout << apath[d]<<" "; //输出起点
				for (s = d - 1; s >= 0; s--) //循环输出其它点
					cout << apath[d]<<" ";

				cout << "该条路径长度为" << A[i][j]<<endl;

			}
		}
}