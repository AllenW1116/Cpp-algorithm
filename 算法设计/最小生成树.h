#pragma once
#include<iostream>
#include"邻接矩阵.h"
using namespace std;
//Prim算法
void Prim(Matgraph g, int v) {
	int lowcost[50];
	int MIN;
	int closet[50], i, j, k;
	for (i = 0; i < g.n; i++) { //先对closet【】和lowcost【】初始化
		lowcost[i] = g.edges[v][i];
		closet[i] = v;
	}
	for (i = 1; i < g.n; i++) { //循环要进行n-1次，使得V-U中的n-1个点都进入U中
		MIN = INF;
		for (j = 0; j < g.n; j++) { //这层循环是要在V-U中找到距U最近的点j
			if (lowcost[j] != 0 && lowcost[j] < MIN) {
				MIN = lowcost[j];
				k = j;  //点j的编号存进k中
			}
		}
		cout << "边（" << k << "," << closet[k] << ")权值为" << MIN;
		lowcost[k] = 0;

		for (j = 0; j < g.n; j++) {   //对U进行调整，确保V-U中的每个点到U的距离都是最近的
			if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j]) {
				lowcost[j] = g.edges[k][j];
				closet[j] = k;
			}
		}
	}
	
}

//Kruskal算法
typedef struct {
	int u;//起点
	int v;//终点
	int w;//权值
}Edge;   //定义结构体Edge
void KruskalInsertSort(Edge E[], int n) {  //算法中需要一次直插排序来对边权值进行递增排序
	int i, j;Edge tmp;
	for (i = 1; i < n; i++) {
		if (E[i].w < E[i - 1].w) {
			tmp = E[i];
			j = i - 1;
			do { E[j + 1] = E[j]; j--; } while (j >= 0 && E[j].w > tmp.w);
			E[j + 1] = tmp;
		}
	}
}
void Kruskal(Matgraph g) {//入口参数为一个存好的邻接矩阵
	int i, j, u1, v1, sn1, sn2, k;
	int vest[50];
	Edge E[50];    //存放图中的边
	k = 0;
	for (i = 0; i < g.n; i++) {  //用邻接矩阵g把E[]初始化
		for(j=0;j<=i;j++)
			if (g.edges[i][j] != 0 && g.edges[i][j] != 32767)
			{
				E[k].u = i; E[k].v = j; E[k].w = g.edges[i][j];
			}
	}
	KruskalInsertSort(E, g.e);
	for (i = 0; i < g.n; i++) {
		vest[i] = i;    //初始化辅助数组
	}
	k = 1;   //k表示当前构造最小生成树的第几条边，从1开始
	j = 0;  //E[]中结构体edge的下标，从0开始
	while (k < g.n) {
		u1 = E[j].u; v1 = E[j].v;
		sn1 = vest[u1];
		sn2 = vest[v1];
		if (sn1 != sn2)
		{
			cout << "(" << u1 << "," << v1 << ")" << ":" << E[j].w << endl;
			k++;
			for(i=0;i<g.n;i++){  //vest为sn2的点现在都和u1属于一个连通分量了！
				if (vest[i] == sn2)
					vest[i] = sn1;
			}
			
		}
		j++;

	}
}


//Djkstra算法
void Dispath(Matgraph g, int dist[], int path[], int S[], int v);
void Dijkstra(Matgraph g, int v) {//v是出发点!
	int dist[50], path[50];//dist[j]中存放源点到j点的最短路；path[j]存放到j的最短路径的上一个点
	int S[50]; S[v] = 1;//S[i]=0表示i点在U中，=1表示在V中；
	int MINdis, i, j, u;
	for (i = 0; i < g.n; i++) {
		dist[i] = g.edges[v][i];
		S[i] = 0;//除了源点，其它的一开始都在U中
		if (g.edges[v][i] != 32767)
			path[i] = v;
		else
			path[i] = -1;//表示源点到i点没路
	}
	path[v] = 0;
	for (i = 0; i < g.n; j++) {
		MINdis = 32767;
		for(j=0;j<g.n;j++)
		{
			if (S[j] == 0 && dist[j] < MINdis) {  //从V中选出距离源点最近的j点
				u = j;  //u中存放即将加入S的j点
				MINdis = dist[j];
			}
		}
		S[u] = 1; //存入S中
		for (j = 0; j < g.n; j++)  //修改V中顶点的path[]和dist[]
		{
			if (S[j] == 0) {
				if (dist[u] + g.edges[u][j] < dist[j]) {
					dist[j] = dist[u] + g.edges[u][j];
					path[j] = u;
				}
			}

		}


	}
	Dispath(g, dist, path, S, v);

}

void Dispath(Matgraph g, int dist[], int path[], int S[], int v) {//输出path中存的路径
	int i, j, k;
	int apath[50], d;//apath[]里存着倒着的路径
	for(i=0;i<g.n;i++)
		if (S[i] == 1 && i != v) {
			cout << "从" << v << "到" << i << "的最短路径长度为" << dist[i] << ";具体路径为：";
			d = 0; apath[d] = i;//apath[]中存放的路径是反序的，故第一个点为终点i
			k = path[i]; //k中存放着“上一个”点
			if (k == -1)
				cout << "无路径！\n";
			else {
				while (k != v) {
					d++; apath[d] = k;
					k = path[k];
				}
				d++; apath[d] = v;//apath[]中最后一个点是起点v
				cout << apath[d];
				for (j = d - 1; j >= 0; j--)
					cout << "," << apath[i];
				cout << endl;
			}

		}

}


//Floyd算法
void Floyddispath(Matgraph g,int dist[50][50],int path[50][50]);
void Floyd(Matgraph g) {
	int dist[50][50], path[50][50];
	int i, j, k;
	for(i=0;i<g.n;i++)    //对dist[]和path[]进行初始化
		for (j = 0; j < g.n; j++) {
			dist[i][j] = g.edges[i][j];
			if (i != j && g.edges[i][j] < 32767)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}

	for (k = 0; k < g.n; k++) {   //更新dist[][]和path[][]
		for(i=0;i<g.n;i++)
			for (j = 0; j < g.n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
	}
	Floyddispath(g,dist,path);

}

void Floyddispath(Matgraph g, int dist[50][50], int path[50][50]) {
	int i, j, k, s;
	int apath[50], d;
	for(i=0;i<g.n;i++)
		for (j = 0; j < g.n; j++) {
			if (dist[i][j] != 32767 && i != j) {//有一条路径，则进行输出（当前源点为i点）
				cout << "从" << i << "到" << j << "的最短路径长度为" << dist[i][j] << ";具体路径为：";
				d = 0; apath[d] = j;//apath[]中存放的路径是反序的，故第一个点为终点j
				k = path[i][j]; //k中存放着“上一个”点
				if (k == -1)
					cout << "无路径！\n";
				else {
					while (k != i) {
						d++; apath[d] = k;
						k = path[i][k];
					}
					d++; apath[d] = i;//apath[]中最后一个点是当前起点i
					cout << apath[d];
					for (j = d - 1; j >= 0; j--)
						cout << "," << apath[i];
					cout << endl;
			}
		}

}



