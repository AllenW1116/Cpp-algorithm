#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【问题描述】有n个重量分别为{ w1，w2，…，wn }的物品，它们的价值分别为{ v1，v2，…，vn }，给定一个容量为W的背包。
//设计从这些物品中选取一部分物品放入该背包的方案，每个物品要么选中要么不选中，
//要求选中的物品不仅能够放到背包中，而且满足重量限制具有最大的价值。
//第4章采用蛮力法求解（求幂集），这里采用回溯法求解该问题。
//
//
//
//#####1. 装入背包中物品重量和恰好为W

//用w[1..n] / v[1..n]存放物品信息，x[1..n]数组存放最优解，
//其中每个元素取1或0，x[i] = 1表示第i个物品放入背包中，x[i] = 0表示第i个物品不放入背包中。
//这是一个求最优解问题。找到更优解(op, tv) (x, maxv)。
//
//解空间是一棵子集树！
//对第i层上的某个分枝结点，对应的状态为dfs(i，tw，tv，op)，
//其中tw表示装入背包中的物品总重量，tv表示背包中物品总价值，
//op记录一个解向量。该状态的两种扩展如下：
//选择第i个物品：op[i] = 1， tw = tw + w[i]，tv = tv + v[i]
//不选择第i个物品：op[i] = 0 tw不变 tv不变

//问题表示
int n = 4;			//4种物品
int W = 6;			//限制重量为6
int w[] = { 0,5,3,2,1 };		//存放4个物品重量,不用下标0元素（根节点啥都不是，第一层考虑是否选第一个物品）
int v[] = { 0,4,4,3,1 };		//存放4个物品价值,不用下标0元素
//求解结果表示
int x[5];			//存放最终解
int maxv;
void dfs(int i, int tw, int tv, int op[])
{
	if (i > n)				//找到一个叶子结点
	{
		if (tw == W && tv > maxv)		//找到一个满足条件的更优解,保存 
		{
			maxv = tv;
			for (int j = 1; j <= n; j++)
				x[j] = op[j];
		}
	}
	else					//尚未找完所有物品
	{
		op[i] = 1;				//选取第i个物品
		dfs(i + 1, tw + w[i], tv + v[i], op);
		op[i] = 0;				//不选取第i个物品,回溯
		dfs(i + 1, tw, tv, op);
	}
}



int maxw;
//改进1：左剪枝：对于第i层的有些结点，tw + w[i]已超过了W（ W = 6），显然再选择w[i]是不合适的。
void dfs(int i, int tw, int tv, int op[])
{
	if (i > n)				//找到一个叶子结点
	{
		if (tw == W && tv > maxv) 		//找到一个满足条件的更优解,保存
		{
			maxv = tv;
			maxw = tw;
			for (int j = 1; j <= n; j++)
				x[j] = op[j];
		}
	}
	else					//尚未找完所有物品
	{
		if (tw + w[i] <= W)		//左孩子结点剪枝
		{
			op[i] = 1;			//选取第i个物品
			dfs(i + 1, tw + w[i], tv + v[i], op);
		}
		op[i] = 0;				//不选取第i个物品,回溯
		dfs(i + 1, tw, tv, op);
	}
}

//改进2：右剪枝：rw = w[i] + w[i + 1] + … + w[n]。
//当不选择物品i时：rw - w[i] = w[i + 1] + … + w[n]，若tw + rw - w[i] < W，
//也就是说即使选择后面的所有物品，重量也不会达到W，因此不必要再考虑扩展这样的结点。
//仅仅扩展满足tw + rw - w[i]≥W的右孩子结点
void dfs(int i, int tw, int tv, int rw, int op[])
{  //初始调用时rw为所有物品重量和
	int j;
	if (i > n)				//找到一个叶子结点
	{
		if (tw == W && tv > maxv) 		//找到一个满足条件的更优解,保存
		{
			maxv = tv;
			for (j = 1; j <= n; j++)		//复制最优解
				x[j] = op[j];
		}
	}
	else					//尚未找完所有物品
	{
		if (tw + w[i] <= W)			//左孩子结点剪枝
		{
			op[i] = 1;			//选取第i个物品
			dfs(i + 1, tw + w[i], tv + v[i], rw - w[i], op);
		}
		if (tw + rw - w[i] >= W)
		{
			op[i] = 0;			 //不选取第i个物品,回溯
			dfs(i + 1, tw, tv, rw - w[i], op);
		}
	}
}






//#####2. 装入背包中物品重量和不超过W

//首先：将所有物品以单位重量价值递减排列（既然不要求一定装到某个重量，那肯定先装值钱的！）
int bound(int i, int tw, int tv)	//求价值上界
{
	i++;					//从i+1开始
	while (i <= n && tw + A[i].w <= W)	//若序号为i的物品可以整个放入
	{
		tw += A[i].w;
		tv += A[i].v;
		i++;
	}
	if (i <= n)
		return tv + (W - tw)*A[i].p;	//序号为i的物品不能整个放入（p是单位价值）
	else
		return tv;
}

//左剪枝：仅仅扩展tw + w[i]≤W的左孩子结点
//右剪枝：仅仅扩展bound(i, tw, tv) > maxv的右孩子结点
void dfs(int i, int tw, int tv, int op[])  //求解0/1背包问题
{
	if (i > n)				   //找到一个叶子结点
	{
		maxv = tv;				   //存放更优解
		for (int j = 1; j <= n; j++)
			x[j] = op[j];
	}
	else					   //尚未找完所有物品
	{
		if (tw + A[i].w <= W)  		   //左孩子结点剪枝
		{
			op[i] = 1;			   //选取序号为i的物品
			dfs(i + 1, tw + A[i].w, tv + A[i].v, op);
		}
		if (bound(i, tw, tv) > maxv)	   //右孩子结点剪枝
		{
			op[i] = 0;			   //不选取序号为i的物品,回溯
			dfs(i + 1, tw, tv, op);
		}
	}
}

















