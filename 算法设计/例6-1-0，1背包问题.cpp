#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>
#define MAXN 2			
using namespace std;


//问题表示：ppt18页
struct NodeType		//队列中的结点类型
{
	int no;			//结点编号，从1开始
	int i;			//当前结点在搜索空间中的层次
	int w;			//当前结点的总重量
	int v;			//当前结点的总价值
	int x[MAXN];		//当前结点包含的解向量
	double ub;			//上界
};
int w[]; //重量数组
int v[]; //价值数组
int bestx[]; //解向量
int W; //最大重量

//对于第i个物品而言：e.w表示结点e时已装入的总重量，用e.v表示已装入的总价值：
//如果所有剩余的物品都能装入背包，那么价值的上界e.ub = e.v + (v[i + 1] + … + v[n])
//如果所有剩余的物品不能全部装入背包，那么价值的上界e.ub = e.v + (v[i + 1] + … + v[k]) + (物品k + 1装入的【部分重量】)×物品k + 1的【单位价值】
void bound(NodeType& e)			//计算分枝结点e的上界
{
	int i = e.i + 1;				//考虑结点e的余下物品
	int sumw = e.w;				//求已装入的总重量
	double sumv = e.v;				//求已装入的总价值
	while ((sumw + w[i] <= W) && i <= n)
	{
		sumw += w[i];				//计算背包已装入载重
		sumv += v[i];				//计算背包已装入价值
		i++;
	}
	if (i <= n)					//余下物品只能部分装入
		e.ub = sumv + (W - sumw) * v[i] / w[i];
	else						//余下物品全部可以装入
		e.ub = sumv;
}

void EnQueue(NodeType e, queue<NodeType>& qu)
//结点e进队qu
{
	if (e.i == n)					//到达叶子结点
	{
		if (e.v > maxv)				//找到更大价值的解
		{
			maxv = e.v;
			for (int j = 1; j <= n; j++)
				bestx[j] = e.x[j];
		}
	}
	else qu.push(e);				//非叶子结点进队
}

void bfs()				//求0/1背包的最优解
{
	int j;
	NodeType e, e1, e2;			//定义3个结点
	queue<NodeType> qu;		//定义一个队列


	e.i = 0;				//根结点置初值，其层次计为0
	e.w = 0; e.v = 0;
	e.no = total++;
	for (j = 1; j <= n; j++)
		e.x[j] = 0;
	bound(e);				//求根结点的上界
	qu.push(e);				//根结点进队


	while (!qu.empty())				//队不空循环
	{
		e = qu.front(); qu.pop();			//出队结点e
		if (e.w + w[e.i + 1] <= W)			//剪枝：检查左孩子结点 ：可以装入
		{
			e1.no = total++; e1.i = e.i + 1;		//建立左孩子结点
			e1.w = e.w + w[e1.i];
			e1.v = e.v + v[e1.i];
			for (j = 1; j <= n; j++)			//复制解向量
				e1.x[j] = e.x[j];
			e1.x[e1.i] = 1; //上一层结点的解向量肯定比这一层少一维，所以要手动设置为1
			bound(e1);				//求左孩子结点的上界
			EnQueue(e1, qu);			//左孩子结点进队操作
		}
		e2.no = total++;				//建立右孩子结点：该物品不选
		e2.i = e.i + 1;
		e2.w = e.w; e2.v = e.v;
		for (j = 1; j <= n; j++)			//复制解向量
			e2.x[j] = e.x[j];
		e2.x[e2.i] = 0;
		bound(e2);				//求右孩子结点的上界
		if (e2.ub > maxv)		//若右孩子结点可行,则进队,否则被剪枝
			EnQueue(e2, qu);
	}
}