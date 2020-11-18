#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//【问题描述】有n种重量和价值分别为wi、vi（1≤i≤n）的物品，从这些物品中挑选总重量【不超过W】的物品，求出挑选物品价值总和最大的挑选方案，这里【每种物品可以挑选任意多件】。
//【问题求解】设置动态规划二维数组dp，dp[i][j]表示从前i个物品中选出重量不超过j的物品的最大总价值。
//显然有边界条件：dp[i][0] = 0（背包不能装入任何物品时，总价值为0），dp[0][j] = 0（没有任何物品可装入时，总价值为0）→采用memset函数一次性初始化为0。
//另外设置二维数组fk，其中fk[i][j]存放dp[i][j]得到最大值时物品i挑选的件数。
//状态转移方程：
//dp[i][j] = MAX{ dp[i - 1][j - k * w[i]] + k * v[i] }  当dp[i][j] <dp[i - 1][j - k * w[i]] + k * v[i]（k * w[i]≤j）
//fk[i][j] = k;			    	    物品i取k件
//
//这样，dp[n][W]便是背包容量为W、考虑所有n个物品（同一物品允许多次选择）后得到的背包最大总价值，即问题的最优结果。


//问题表示
int n, W;
int w[MAXN], v[MAXN];
//求解结果表示
int dp[MAXN + 1][MAXW + 1], fk[MAXN + 1][MAXW + 1];
int solve()				//求解多重背包问题
{
    int i, j, k;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= W; j++)   //对于每一个j，将把每一个k都尝试一遍，试出使得maxv最大的！
            for (k = 0; k * w[i] <= j; k++)
            {
                if (dp[i][j] < dp[i - 1][j - k * w[i]] + k * v[i])
                {
                    dp[i][j] = dp[i - 1][j - k * w[i]] + k * v[i];
                    fk[i][j] = k;		//物品i取k件
                }
            }
    }
    return dp[n][W];
}

void Traceback()		//回推求最优解
{
    int i = n, j = W;
    while (i >= 1)
    {
        printf("物品%d共%d件 ", i, fk[i][j]);
        j -= fk[i][j] * w[i];	//剩余重量
        i--;
    }
    printf("\n");
}


