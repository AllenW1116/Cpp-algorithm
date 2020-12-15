#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
#include"邻接矩阵.h"
using namespace std;
#define INF 32767;

//克鲁斯卡尔（Kruskal）算法是一种按权值的递增次序选择合适的边来构造最小生成树的方法。
//算法步骤见 ppt15页
//实现克鲁斯卡尔算法的关键是如何判断选取的边是否与生成树中已有的边形成回路，这可以通过【并查集】来解决。　
//【并查集】见ppt18页

//并查集模型：
//类型定义：
typedef struct node
{
    int data;		//结点对应数据
    int rank;		//结点对应秩（可以体现所在的树层数，又不完全是
    int parent;	    //结点对应双亲下标
} UFSTree;
//基本运算：
void MAKE_SET(UFSTree t[], int n)	//初始化并查集树
{
    for (int i = 0; i < n; i++)			//顶点编号为0～(n-1)
    {
        t[i].rank = 0;				//秩初始化为0
        t[i].parent = i;				//双亲初始化指向自已
    }
}
int FIND_SET(UFSTree t[], int x)	//在x所在子树中查找集合的编号
{
    if (x != t[x].parent)			//若双亲不是自已（节点在t[]中的数组下标就是该点的编号？）
        return(FIND_SET(t, t[x].parent));	//递归在双亲中找x
    else
        return(x);				//若双亲是自已,返回x
}
void UNION(UFSTree t[], int x, int y)	//将x和y所在的子树合并
{
    x = FIND_SET(t, x);
    y = FIND_SET(t, y);
    if (t[x].rank > t[y].rank)		//x结点的秩大于y结点的秩
        t[y].parent = x;			//将x结点作为y的双亲结点
    else					//y结点的秩大于等于x结点的秩
    {
        t[x].parent = y;			//将y结点作为x的双亲结点
        if (t[x].rank == t[y].rank)	//x和y结点的秩相同
            t[y].rank++;			//y结点的秩增1
    }
}


//接下来我们来看Kruskal算法具体是如何实现的
//存放Edge
typedef struct
{
    int u;		//边的起始顶点
    int v;		//边的终止顶点
    int w;		//边的权值
} Edge;
//用一个数组E[]存放图G中的所有边，要求它们是【按权值】从小到大的顺序【排列】的，
//为此先从图G的【邻接矩阵】中获取所有边集E，再采用【推排序法】对边集E按权值递增排序。
void Kruskal(Matgraph g)	//Kruskal算法
{
    int i, j, k, u1, v1, sn1, sn2;
    UFSTree t[MaxSize];
    Edge E[MaxSize];
    k = 0;
    for (i = 0; i < g.n; i++)	//由g下三角部分产生的边集E（没有排序，就是存进去了）
        for (j = 0; j < i; j++)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
            {
                E[k].u = i; E[k].v = j; E[k].w = g.edges[i][j];
                k++;
            }//循环结束后，k==节点个数

    sort(E, E + k);		//调用STL的sort()算法按w递增排序
    MAKE_SET(t, g.n);		//初始化并查集树t
    k = 1;				//k表示当前构造生成树的第几条边,初值为1
    j = 0;				//E中边的下标,初值为0
    while (k < g.n)		//生成的边数小于n时循环
    {
        u1 = E[j].u;
        v1 = E[j].v;		//取一条边的头尾顶点编号u1和v2
        sn1 = FIND_SET(t, u1);
        sn2 = FIND_SET(t, v1);	//分别得到两个顶点所属的集合编号
        if (sn1 != sn2)
            //添加该边不会构成回路,将其作为最小生成树的一条边输出
        {
            printf("  (%d,%d):%d\n", u1, v1, E[j].w);
            k++;			//生成边数增1
            UNION(t, u1, v1);	//将u1和v1两个顶点合并
        }
        j++;			//扫描下一条边
    }
}

