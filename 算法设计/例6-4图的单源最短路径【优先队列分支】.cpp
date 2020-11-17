#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
using namespace std;
struct NodeType		//队列结点类型
{
	int vno;			//顶点编号
	int length;			//原点到该点的路径长度

	bool operator<(const NodeType& node) const
	{
		return length > node.length;	//length越小越优先出队
	}

};
void bfs(int v)			//求解算法
{
    NodeType e, e1;
    priority_queue<NodeType> pqu;	//定义优先队列
    e.vno = v;				//建立源点结点e
    e.length = 0;
    pqu.push(e);			//源点结点e进队
    dist[v] = 0;
    while (!pqu.empty())		//队列不空循环
    {
        e = pqu.top(); pqu.pop();		//出队列结点e
        for (int j = 0; j < n; j++)
        {
            if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j])
            {  //剪枝：e.vno到顶点j有边并且路径长度更短
                dist[j] = e.length + a[e.vno][j];
                prev[j] = e.vno;
                e1.vno = j;			//建立相邻顶点j的结点e1
                e1.length = dist[j];
                pqu.push(e1);		//结点e1进队
            }
        }
    }
}




