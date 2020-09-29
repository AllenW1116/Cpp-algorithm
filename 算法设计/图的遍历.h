#pragma once
#include<iostream>
#include"邻接表.h"
#include"顺序队.h"
using namespace std;
int visited[50] = { 0 }; //定义全局数组，存放访问过的结点//访问过的置为1


//深度优先遍历
void DFS(AdjGraph *G, int v) {  //入口参数是建立好的邻接表和初始节点
	ArcNode *p;
	visited[v] = 1;
	cout << v;
	p = G->adjlist[v].firstarc;
	while (p != NULL) {
		if (visited[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}


//广度优先遍历
void BFS(AdjGraph *G, int v) {   //入口参数是建立好的邻接表和初始节点
	int w, i; ArcNode *p;
	SqQueue *qu;
	InitQueue(qu);
	int visited[50];
	for (i = 0; i < G->n; i++) { visited[i] = 0; }
	cout << " " << v;
	visited[v] = 1;
	enQueue(qu, v);
	while (!QueueEmpty(qu)) {
		deQueue(qu, w);
		p = G->adjlist[w].firstarc;
		while (p != NULL) {   //这一层循环处理了邻接表的某一行：把那一行的邻接点都访问了，并且都存进了队列！
			if (visited[p->adjvex] == 0) {
				cout << " " << p->adjvex;
				visited[p->adjvex] = 1;
				enQueue(qu, p->adjvex);
			}
			p = p->nextarc;
		}
	}
	cout << endl;
}

//非连通图的遍历：由于某一次遍历只是遍历了图的一个连通分量，所以要循环调用，把每个点都作为初始点遍历一次
void DFS1(AdjGraph *G) {  //多次深度优先遍历
	int i;
	for (i = 0; i < G->n; i++)
		if (visited[i] == 0) { DFS(G, i); cout << endl; }

}
void BFS1(AdjGraph *G) {
	int i;
	for (i = 0; i < G->n; i++)
		if (visited[i] == 0) BFS(G, i);
}