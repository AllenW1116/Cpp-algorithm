#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//【问题描述】给定高度为n的一个整数三角形，找出从顶部到底部的最小路径和，只能向先移动相邻的结点。
//首先输入n，接下来的1～n行，第i行输入i个整数，输出分为2行，第一行为最小路径，第2行为最小路径和。
//从顶部到底部查找最小路径，那么结点（i，j）的前驱结点只有（i - 1，j - 1）和（i - 1，j）两个
//dp[i][j]表示从顶部a[0][0]查找到（i，j）结点时的最小路径和。
//dp[i][j] = min(dp[i - 1][j - 1]，dp[i - 1][j]) + a[i][j]
//状态转移方程：
//dp[0][0] = a[0][0]			顶部边界
//dp[i][0] = dp[i - 1][0] + a[i][0]		考虑第1列的边界，1≤i≤n - 1
//dp[i][i] = dp[i - 1][i - 1] + a[i][i]		考虑对角线的边界，1≤i≤n - 1
//dp[i][j] = min(dp[i - 1][j - 1]，dp[i - 1][j]) + a[i][j]  i > 1的其他有两条达到路径的结点

//用pre[i][j]表示查找到（i，j）结点时最小路径上的前驱结点，由于前驱结点只有两个，
//即（i - 1，j - 1）和（i - 1，j），用pre[i][j]记录前驱结点的列号即可。

//问题表示
int a[MAXN][MAXN];
int n;  //三角形层数
//求解结果表示
int ans = 0;
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];

int Search()			//求最小和路径ans
{
    int i,j;
    dp[0][0] = a[0][0];
    for (i = 1; i < n; i++)		//考虑第1列的边界
    {
        dp[i][0] = dp[i - 1][0] + a[i][0];
        pre[i][0] = 0;
    }
    for (i = 1; i < n; i++)		//考虑对角线的边界
    {
        dp[i][i] = a[i][i] + dp[i - 1][i - 1];
        pre[i][i] = i - 1;
    }
    for (i = 2; i < n; i++)		//考虑其他有两条达到路径的结点
    {
        for (j = 1; j < i; j++)
        {
            if (dp[i - 1][j - 1] < dp[i - 1][j])
            {
                pre[i][j] = j - 1;
                dp[i][j] = a[i][j] + dp[i - 1][j - 1];
            }
            else
            {
                pre[i][j] = j;
                dp[i][j] = a[i][j] + dp[i - 1][j];
            }
        }
    }


    ans = dp[n - 1][0];//答案就是最后一行最小的数
    int k = 0;
    for (j = 1; j < n; j++)	//求出最小ans和对应的列号k
    { //  dp二维数组的最后一行中最小的那个值就是ans（路径和），k是最终出口的列号
        if (ans > dp[n - 1][j])
        {
            ans = dp[n - 1][j];
            k = j;
        }
    }
    return k;
}


void Disppath(int k)		//输出最小和路径
{
    int i = n - 1;
    vector<int> path;		//存放逆路径向量path
    while (i >= 0)		//从（n-1,k）结点反推求出反向路径
    {
        path.push_back(a[i][k]);
        k = pre[i][k];		//最小路径在前一行中的列号
        i--;			//在前一行查找
    }
    vector<int>::reverse_iterator it;		//定义反向迭代器
    for (it = path.rbegin(); it != path.rend(); ++it)
        printf("%d ", *it);	//反向输出构成正向路径（只输出列号）
    printf("\n");
}






