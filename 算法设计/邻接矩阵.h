#pragma once
#include<iostream>
using namespace std;
typedef char Infotype;
#define INF 32767;
typedef struct {  
	int no;  //顶点的编号
	Infotype info; //顶点存的信息
}Vertextype;//图中一个顶点

typedef struct {
	int edges[50][50];  //邻接矩阵数组
	int n, e; //n点数，e边数
	Vertextype vexs[50]; //一维数组用于存放顶点
}Matgraph; //一个邻接矩阵

//创建邻接矩阵
void CreatMatgraph(Matgraph *&M, int A[50][50], int n1, int e1) {
	M = (Matgraph *)malloc(sizeof(Matgraph));
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			M->edges[i][j] = A[i][j];
		}
	}
	M->n= n1;
	M->e= e1;
}
//输出邻接矩阵
void dismatgraph(Matgraph M) {
	for (int i = 0; i < M.n; i++) {
		for (int j = 0; j < M.n; j++)
		{
			cout << M.edges[i][j]<<" ";
		}
		cout << endl;
	}
}

