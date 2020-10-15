#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include"邻接表.h"
#include"邻接矩阵.h"
#include<queue>
using namespace std;

//首先看一下图的BFS框架
//广度优先搜索的过程是：
//（1）首先访问初始顶点v。
//（2）接着访问顶点v的所有未被访问过的邻接点v1，v2，…，vt。
//（3）然后再按照v1，v2，…，vt的次序，访问每一个顶点的所有未被访问过的邻接点，依次类推，直到图中所有和初始顶点v有路径相通的顶点都被访问过为止。

const int MAXV = 20;

void BFS_M(Matgraph g, int v)			//邻接矩阵的BFS算法
{
	queue<int> qu;			//定义一个队列qu
	int visited[MAXV];			//定义存放结点的访问标志的数组
	int w, i;
	memset(visited, 0, sizeof(visited));	//访问标志数组初始化(全部填入0)
	printf("%3d", v);			//输出被访问顶点的编号
	visited[v] = 1;				//置已访问标记
	qu.push(v);				//v进队
	while (!qu.empty())			//队列不空时循环
	{
		w = qu.front(); qu.pop();		//出队顶点w  queue.front():获取队首元素
		for (i = 0; i < g.n; i++)		//找与顶点w相邻的顶点
			if (g.edges[w][i] != 0 && g.edges[w][i] != 32767 && visited[i] == 0)
			{		//若当前邻接顶点i未被访问
				printf("%3d", i);		//访问相邻顶点
				visited[i] = 1;			//置该顶点已被访问的标志
				qu.push(i);			//该顶点进队
			}
	}
	printf("\n");
}

void BFS_G( AdjGraph *G, int v)		//邻接表的BFS算法
{
	ArcNode *p;
	queue<int> qu;			//定义一个队列qu
	int visited[MAXV], w;			//定义存放顶点的访问标志的数组
	memset(visited, 0, sizeof(visited));	//访问标志数组初始化
	printf("%3d", v);			//输出被访问顶点的编号
	visited[v] = 1; 			//置已访问标记
	qu.push(v);				//v进队
	while (!qu.empty())			//队列不空时循环
	{
		w = qu.front(); qu.pop();		//出队顶点w
		p = G->adjlist[w].firstarc;		//找顶点w的第一个邻接点
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)	//若当前邻接顶点未被访问
			{
				printf("%3d", p->adjvex);	//访问相邻顶点
				visited[p->adjvex] = 1;	//置该顶点已被访问的标志
				qu.push(p->adjvex);		//该顶点进队
			}
			p = p->nextarc;			//找顶点w的下一个邻接点
		}
	}
}

//【例4.8】假设图G采用邻接表存储，设计一个算法，求不带权无向连通图G中从顶点u到顶点v的一条最短路径。
//解：图G是不带权的无向连通图，一条边的长度计为1，因此，求顶点u和顶点v的最短路径即求距离顶点u到顶点v的边数最少的顶点序列。
//利用广度优先遍历算法，从u出发一层一层地向外扩展，扩展到某个顶点时记录其前驱顶点，
//当第一次找到顶点v时队列中便隐含从顶点u到顶点v最近的路径，再利用队列输出最短路径。


void ShortPath(AdjGraph *G, int u, int v, vector<int> &path)
//求图G中从顶点u到顶点v的最短（逆）路径path
{
	ArcNode *p; int w;
	queue<int> qu;			//定义一个队列qu
	int pre[MAXV];			//表示前驱关系
	int visited[MAXV];			//定义存放顶点的访问标志的数组
	memset(visited, 0, sizeof(visited));	//访问标志数组初始化
	qu.push(u);				//顶点u进队
	visited[u] = 1;
	pre[u] = -1;				//起始顶点的前驱置为-1
	while (!qu.empty())			//队不空时循环
	{
		w = qu.front(); qu.pop();		//出队顶点w
		if (w == v)				//找到v时输出路径之逆并退出
		{
			//Findpath(pre, v, path);
			return;
		}
		p = G->adjlist[w].firstarc;		//找w的第一个邻接点
		while (p != NULL)   //相邻节点没有全部进队时循环
		{
			if (visited[p->adjvex] == 0)
			{
				visited[p->adjvex] = 1;	//访问w的邻接点
				qu.push(p->adjvex);		//将w的邻接点进队
				pre[p->adjvex] = w;		//设置p->adjvex顶点的前驱为w
			}
			p = p->nextarc;			//找w的下一个邻接点
		}
	}
}
