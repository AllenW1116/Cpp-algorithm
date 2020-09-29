#pragma once
#include<iostream>
using namespace std;
const int INF =32767;
typedef char Infotype;
typedef struct ANode { //边结点类型
	int adjvex; //与i邻接的顶点编号	
	struct ANode *nextarc; //指向下个边结点
	int weight;
}ArcNode;
typedef struct VNode {  //每个单链表的头结点类型
	Infotype info;  //名称等信息
	ArcNode *firstarc; //指向第一个边结点
}VNode;
typedef struct { //完整的邻接表
	VNode adjlist[50]; //最多存50个结点
	int n, e; 
}AdjGraph;

//创建邻接表
void CreatAdj(AdjGraph *&G, int A[50][50], int n, int e) {//入口参数是一个空的邻接表G，
	                                                      // 一个存好的邻接矩阵
	int i, j;
	ArcNode *p;
	G = (AdjGraph *)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++) {
		for(j=n-1;j>=0;j--)
			if (A[i][j] != 0 && A[i][j] != INF) {
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc; //头插法插入结点
				G->adjlist[i].firstarc = p;
			}
	}
	G->n = n; G->e = e;

}
//输出邻接表
void DispAdj(AdjGraph *G) {
	int i; ArcNode *p;
	for (i = 0; i < G->n; i++) {
		p = G->adjlist[i].firstarc;
		cout << i << " :";
		while (p != NULL) {
			cout << p->adjvex << "[" << p->weight << "]" << "->";
			p = p->nextarc;
		}
		cout << endl;
	}
}

//销毁图
void DestroyAdj(AdjGraph *G) {
	int i;
	ArcNode *pre, *p;
	for (i = 0; i < G->n; i++) {
		pre = G->adjlist[i].firstarc;
		if (pre != NULL) {   //若不是空表
			p = pre->nextarc;
			while (p != NULL) {  //释放第i个单链表
				free(pre);
				pre = p; p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);    //free头结点
}

