#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
【问题描述】给定一个无序的整数序列a[0..n - 1]，求其中最长递增子序列的长度。
例如，a[] = { 2，1，5，3，6，4，8，9，7 }，n = 9，其最长递增子序列为{ 1，3，4，8，9 }，结果为5。
【问题求解】设计动态规划数组为一维数组dp，dp[i]表示a[0..i]中以a[i]结尾的最长递增子序列的长度。

//问题表示
int a[] = { 2,1,5,3,6,4,8,9,7 };
int n = sizeof(a) / sizeof(a[0]);
//求解结果表示
int ans = 0;
int dp[MAX];
void solve(int a[],int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i],dp[j] + 1); //若i在j左边，那就是dp[i]；若i在j右边，那就是dp[j]+1
        }
    }
    ans = dp[0];
    for (i = 1; i < n; i++)  //答案就是dp数组中的最大值
        ans = max(ans,dp[i]);
}
