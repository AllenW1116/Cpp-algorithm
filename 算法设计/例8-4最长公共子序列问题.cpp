#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;

//【问题描述】字符序列的子序列是指从给定字符序列中随意地（不一定连续）去掉若干个字符（可能一个也不去掉）后所形成的字符序列。
//给定两个字符序列A和B，如果字符序列Z既是A的子序列，又是B的子序列，则称序列Z是A和B的公共子序列。
//该问题是求两序列A和B的最长公共子序列（【LCS】）。
//定义二维动态规划数组dp，其中dp[i][j]为子序列（a0，a1，…，ai - 1）和（b0，b1，…，bj - 1）的最长公共子序列的长度。

//状态转移方程（ppt63页）：
//dp[i][j] = 0				  i = 0或j = 0―边界条件
//dp[i][j] = dp[i - 1][j - 1] + 1		  a[i - 1] = b[j - 1]
//dp[i][j] = MAX(dp[i][j - 1]，dp[i - 1][j])	  a[i - 1]≠b[j - 1]

//如何通过dp求出LCS呢？注意到：
//dp[i][j] = 0				  i = 0或j = 0―边界条件
//dp[i][j] = dp[i - 1][j - 1] + 1		  a[i - 1] = b[j - 1]
//dp[i][j] = MAX(dp[i][j - 1]，dp[i - 1][j])	  a[i - 1]≠b[j - 1]
//
//当dp[i][j] ≠ dp[i][j - 1]（矩阵中左边元素）并且dp[i][j] ≠ dp[i - 1][j]（矩阵中上方元素）值时：
//a[i - 1] = b[j - 1]
//将a[i - 1]添加到LCS中。

//dp[i][j] = dp[i][j - 1]：与左边相等  j--
//dp[i][j] = dp[i - 1][j]：与上方相等  i--
//与左边、上方都不相等：a[i - 1]=b[j - 1]属于LCS   i--，j--


//问题表示
int m,n;
string a,b;				//求解结果表示
int dp[MAX][MAX];			//动态规划数组
vector<char> subs;			//存放LCS
void LCSlength()			//求dp
{
    int i,j;
    for (i = 0; i <= m; i++)			//将dp[i][0]置为0，边界条件
        dp[i][0] = 0;
    for (j = 0; j <= n; j++)			//将dp[0][j]置为0，边界条件   
        dp[0][j] = 0;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)		//两重for循环处理a、b的所有字符
        {
            if (a[i - 1] == b[j - 1])		//情况(1):字符串最后一位相等
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else				//情况(2)
                dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
        }
}
void Buildsubs()		    //由dp构造从LCS
{
    int k = dp[m][n];		    //k为a和b的最长公共子序列长度
    int i = m;
    int j = n;
    while (k > 0) {			    //在subs中放入最长公共子序列(反向)
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        else			    //与上方、左边元素值均不相等
        {
            subs.push_back(a[i - 1]);  //subs中添加a[i-1]
            i--; j--; k--;
        }
    }
}
