#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//【问题描述】资源分配问题是将数量一定的一种或若干种资源（原材料、资金、设备或劳动力等），合理地分配给若干使用者，使总收益最大。（ppt105页）
//【问题求解】采用动态规划求解该问题。设置3个商店A、B、C的编号分别为1～3。
//这里总员工数为n = 5，商店个数m = 3，假设从商店3开始决策起。
//设置二维动态规划数组为dp，其中dp[i][s]表示考虑商店i～商店m并分配s个人后的最优赢利。（从最后一个商店开始考虑！）
//另外设置二维数组pnum，其中pnum[i][s]表示求出dp[i][s]时对应商店i的分配人数。
//对应的状态转移方程如下：
//dp[m + 1][j] = 0			  	边界条件（类似终点的dp值为0）
//dp[i][s] = max(v[i][j] + dp[i + 1][s - j])（j是变量）	pnum[i][s] = dp[i][s]取最大值的j（0≤j≤n）
//显然，dp[1][n]就是最优赢利。

//问题表示
int m = 3;
int n = 5;				//商店数为m,总人数为n
int v[MAXM][MAXN] = { {0,0,0,0,0,0},{0,3,7,9,12,13},
	{0,5,10,11,11,11},{0,4,6,11,12,12} }; //不计v[0]行
//求解结果表示
int dp[MAXM][MAXN];
int pnum[MAXM][MAXN];
void Plan()			  //求最优方案dp
{
    int maxf, maxj;
    for (int j = 0; j <= n; j++)	  //置边界条件
        dp[m + 1][j] = 0;
    for (int i = m; i >= 1; i--)	  //i从商店3到1进行处理
    {
        for (int s = 1; s <= n; s++)	  //分配的总人数为s
        {
            maxf = 0;
            maxj = 0;
            for (j = 0; j <= s; j++)	  //找该商店最优情况maxf和分配人数maxj
            {
                if ((v[i][j] + dp[i + 1][s - j]) >= maxf)
                {
                    maxf = v[i][j] + dp[i + 1][s - j];
                    maxj = j;
                }
            }
            dp[i][s] = maxf;
            pnum[i][s] = maxj;
        }
    }
}

