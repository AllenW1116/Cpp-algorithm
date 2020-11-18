#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//如果仅仅求装入背包的最大价值（不需求解向量x）。
//由于第i个阶段（考虑物品i）的解dp[i][*]只与第i - 1个阶段（考虑物品i - 1）的解dp[i - 1][*]有关，这种情况下保存更前面的数据已经毫无意义。
//所以可以利用滚动数组进行优化，将dp数组由dp[MAXN][MAXW]改为dp[2][MAXW]。
//求0 / 1背包问题的状态转移方程如下：
//dp[0][0] = 0，dp[1][0] = 0
//dp[0][r] = 0
//dp[c][r] = dp[1 - c][r]			当r < w[i]时，物品i放不下
//dp[c][r] = MAX{ dp[1 - c][r]，dp[1 - c][r - w[i]] + v[i] }  否则在不放入和放入物品i之间选最优解
//关键变化【1-c】：因为不是0行就是1行

void Knap()			//动态规划法求0/1背包问题
{
	int i, r;
	int c = 0;
	for (i = 0; i <= 1; i++)		//置边界条件dp[0..1][0]=0
		dp[i][0] = 0;
	for (r = 0; r <= W; r++)		//置边界条件dp[0][r]=0
		dp[0][r] = 0;
	for (i = 1; i <= n; i++)
	{
		c = 1 - c;
		for (r = 1; r <= W; r++)
		{
			if (r < w[i])
				dp[c][r] = dp[1 - c][r];
			else
				dp[c][r] = max(dp[1 - c][r], dp[1 - c][r - w[i]] + v[i]);
		}
	}
}

