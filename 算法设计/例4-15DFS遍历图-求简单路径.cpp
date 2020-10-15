#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include"邻接表.h"
#include"邻接矩阵.h"
using namespace std;


//首先看一下图的DFS框架
//（1）从图中某个初始顶点v出发，首先访问初始顶点v。
//（2）然后选择一个与顶点v相邻且没被访问过的顶点w为初始顶点，再从w出发进行深度优先搜索。
//（3）重复直到图中与当前顶点v邻接的所有顶点都被访问过为止。显然，这个搜索过程是个递归过程。

int visited[] = { 0 };

//以邻接矩阵为存储结构的深度优先搜索算法
void DFS_M(Matgraph g, int v)	//邻接矩阵的DFS算法
{
	int w;
	printf("%3d", v);		//输出被访问顶点的编号
	visited[v] = 1;		//置已访问标记
	for (w = 0; w < g.n; w++)	//找顶点v的所有相邻点
		if (g.edges[v][w] != 0 && g.edges[v][w] != 32767
			&& visited[w] == 0)
			DFS_M(g, w);		//找顶点v的未访问过的相邻点w
}

//以邻接表为存储结构的深度优先搜索算法：
void DFS_G( AdjGraph *G, int v)	//邻接表的DFS算法
{
	ArcNode *p;
	printf("%3d", v);		//输出被访问顶点的编号
	visited[v] = 1;		//置已访问标记
	p = G->adjlist[v].firstarc;	//p指向顶点v的第一个邻接点
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0) //若p->adjvex顶点未访问,递归访问它
			DFS_G(G, p->adjvex);
		p = p->nextarc;		//p指向顶点v的下一个邻接点
	}
}







//【例4.6】假设图G采用邻接表存储，设计一个算法判断图G中从顶点u到v是否存在简单路径。

bool ExistPath ( AdjGraph *G,int u, int v)
//判断G中从顶点u到v是否存在简单路径
{
	int w; ArcNode *p;
	visited[u] = 1;		//置已访问标记
	if (u == v)			//找到了一条路径，返回true
		return true;
	p = G->adjlist[u].firstarc;	//p指向顶点u的第一个相邻点
	while (p != NULL)
	{
		w = p->adjvex;		//w为顶点u的相邻顶点
		if (visited[w] == 0)	//若w顶点未访问,递归访问它
		{
			bool flag = ExistPath(G, w, v);
			if (flag) return true;
		}
		p = p->nextarc;		//p指向顶点u的下一个相邻点
	}
	return false;		//没有找到v，返回false
}


//【例4.7】假设图G采用邻接表存储，设计一个算法输出图G中从顶点u到v的一条简单路径（假设图G中从顶点u到v至少有一条简单路径）。
//解：采用深度优先遍历的方法，f(G，u，v，apath，path)搜索图G中从顶点u到v的一条简单路径path。
//通过顶点u在图G中搜索，当u = v时说明找到一条从u到v的简单路径，将apath复制到path中并返回。否则继续深度优先遍历。

void FindaPath (AdjGraph *G, int u, int v, vector<int> apath,
	vector<int> &path)
{
	int w;
	ArcNode *p;
	visited[u] = 1;
	apath.push_back(u);		//顶点u加入到apath路径中
	if (u == v)				//找到一条路径
	{
		path = apath;			//将apath复制到path
		return;				//返回true
	}
	p = G->adjlist[u].firstarc;		//p指向顶点u的第一个相邻点
	while (p != NULL)
	{
		w = p->adjvex;			//相邻点的编号为w
		if (visited[w] == 0)
			FindaPath(G, w, v, apath, path);
		p = p->nextarc;			//p指向顶点u的下一个相邻点
	}
}

