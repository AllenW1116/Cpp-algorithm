#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
using namespace std;
//【问题描述】求将正整数n无序拆分成最大数为k（称为n的k拆分）的拆分方案个数，要求所有的拆分方案不重复。
//【问题求解】设n = 5，k = 5，对应的拆分方案有：
//① 5 = 5
//② 5 = 4 + 1
//③ 5 = 3 + 2
//④ 5 = 3 + 1 + 1
//⑤ 5 = 2 + 2 + 1
//⑥ 5 = 1 + 1 + 1 + 1
//⑦ 5 = 1 + 1 + 1 + 1 + 1
//为了防止重复计数，让拆分数保持从大到小排序。正整数5的拆分数为7。
//迭代公式推理：ppt31页
//迭代公式：
//当n = 1或者k = 1： f（n，k）= 1
//当n < k：f（n，k） = f(n，n)
//当n = k：f（n，k） = f(n，n - 1) + 1
//其他情况：f(n - k，k) + f(n，k - 1)  包含k的情况+不包含k的情况


int dp[MAXN][MAXN];			//动态规划数组
void Split(int n,int k)		//求解算法
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++)
        {
            if (i == 1 || j == 1)
                dp[i][j] = 1;
            else if (i < j)
                dp[i][j] = dp[i][i];
            else if (i == j)
                dp[i][j] = dp[i][j - 1] + 1;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
        }
    }
}

//该方法还可以和递归法结合一下：【备忘录法】！
int dpf(int n，int k)			//求解算法
{
    if (dp[n][k] != 0) return dp[n][k];
    if (n == 1 || k == 1)
    {
        dp[n][k] = 1; return dp[n][k];
    }
    else if (n < k)
    {
        dp[n][k] = dpf(n，n); return dp[n][k];
    }
    else if (n == k)
    {
        dp[n][k] = dpf(n，k - 1) + 1; return dp[n][k];
    }
    else
    {
        dp[n][k] = dpf(n，k - 1) + dpf(n - k，k); return dp[n][k];
    }
}
