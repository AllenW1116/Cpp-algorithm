#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//【问题描述】有n个重量分别为{ w1，w2，…，wn }的物品，它们的价值分别为{ v1，v2，…，vn }，给定一个容量为W的背包。
//设计从这些物品中选取一部分物品放入该背包的方案，每个物品要么选中要么不选中，要求选中的物品不仅能够放到背包中，而且重量和【为W】具有最大的价值。
//设二维动态规划数组dp，dp[i][r]表示背包剩余容量为r（1≤r≤W），已考虑物品1、2、…、i（1≤i≤n）时背包装入物品的最优价值。显然对应的状态转移方程如下：
//dp[i][0] = 0（背包不能装入任何物品，总价值为0）  边界条件dp[i][0] = 0（1≤i≤n）―边界条件
//dp[0][r] = 0（没有任何物品可装入，总价值为0）    边界条件dp[0][r] = 0（1≤r≤W）―边界条件
//dp[i][r] = dp[i - 1][r]     	当r < w[i]时，物品i放不下
//dp[i][r] = MAX{ dp[i - 1][r]，dp[i - 1][r - w[i]] + v[i] }    否则在不放入和放入物品i之间选最优解
//
//这样， dp[n][W]便是0 / 1背包问题的最优解。
//
//当dp数组计算出来后，推导出解向量x的过程十分简单，从dp[n][W]开始：
//（1）若dp[i][r]≠dp[i - 1][r]，说明物品i放了，置x[i] = 1，累计总价值maxv += v[i]，递减剩余重量r = r - w[i]。（往回推到）
//（2）若dp[i][r] = dp[i - 1][r]，表示物品i放不下或者不放入物品i，置x[i] = 0。

//问题表示
int n = 5,W = 10;				//5种物品，限制重量不超过10
int w[MAXN] = { 0,2,2,6,5,4 };	//下标0不用
int v[MAXN] = { 0,6,3,5,4,6 };	//下标0不用
//求解结果表示
int dp[MAXN][MAXW];
int x[MAXN];
int maxv; 				//存放最优解的总价值

void Knap()			//动态规划法求0/1背包问题
{
    int i,r;
    for (i = 0; i <= n; i++)		//置边界条件dp[i][0]=0
        dp[i][0] = 0;
    for (r = 0; r <= W; r++)		//置边界条件dp[0][r]=0
        dp[0][r] = 0;
    for (i = 1; i <= n; i++)
    {
        for (r = 1; r <= W; r++)
            if (r < w[i])  //放不下惹
                dp[i][r] = dp[i - 1][r];
            else
                dp[i][r] = max(dp[i - 1][r],dp[i - 1][r - w[i]] + v[i]);
    }
}

void Buildx()				//回推求最优解
{
    int i = n,r = W;
    maxv = 0;
    while (i >= 0)			//判断每个物品
    {
        if (dp[i][r] != dp[i - 1][r])
        {
            x[i] = 1;			//选取物品i
            maxv += v[i];			//累计总价值
            r = r - w[i];
        }
        else
            x[i] = 0;			//不选取物品i
        i--;
    }
}

