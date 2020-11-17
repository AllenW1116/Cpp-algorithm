#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//【问题描述】设A和B是两个字符串。现在要用最少的字符操作次数，将字符串A转换为字符串B。这里所说的字符操作共有3种：
//（1）删除一个字符。
//（2）插入一个字符。
//（3）将一个字符替换另一个字符。
//例如，A = “sfdqxbw”，B = “gfdgw”，结果为4。
//s换为g；删除q；删除x；b换位g；共4次操作
//【问题求解】设字符串A、B的长度分别为m、n，分别用字符串a、b存放。
//设计一个动态规划二维数组dp，其中dp[i][j]表示将a[0..i - 1]（1≤i≤m）与b[0..j - 1]（1≤j≤n）的最优编辑距离（即a[0..i - 1] 转换为b[0..j - 1]的最少操作次数）。
//两种特殊情况：
//当B串空时，要删除A中全部字符转换为B，即dp[i][0] = i（删除A中i个字符，共i次操作）；
//当A串空时，要在A中插入B的全部字符转换为B，即dp[0][j] = j（向A中插入B的j个字符，共j次操作）。
//对于非空的情况，当a[i - 1] = b[j - 1]时，这两个【字符】不需要任何操作，即dp[i][j] = dp[i - 1][j - 1]。
//当a[i - 1]≠b[j - 1]时，以下3种操作都可以达到目的：
//将a[i - 1]替换为b[j - 1]，有：dp[i][j] = dp[i - 1][j - 1] + 1（一次替换操作的次数计为1）。
//在a[i - 1]字符后面插入b[j - 1]字符，有：dp[i][j] = dp[i][j - 1] + 1（一次插入操作的次数计为1）。
//删除a[i - 1]字符，有：dp[i][j] = dp[i - 1][j] + 1（一次删除操作的次数计为1）。
//此时dp[i][j]取3种操作的最小值。
//状态转移方程如下：
//dp[i][j] = dp[i - 1][j - 1]			当a[i - 1] = b[j - 1]时
//dp[i][j] = min(dp[i - 1][j - 1] + 1，dp[i][j - 1] + 1，dp[i - 1][j] + 1)	 当a[i - 1]≠b[j - 1]时

//问题表示
string a = "sfdqxbw";
string b = "gfdgw";
//求解结果表示
int dp[MAX][MAX];
void solve()			//求dp
{
    int i,j;
    for (i = 1; i <= a.length(); i++)
        dp[i][0] = i;		//把a的i个字符全部删除转换为b
    for (j = 1; j <= b.length(); j++)
        dp[0][j] = j;		//在a中插入b的全部字符转换为b
    for (i = 1; i <= a.length(); i++)
        for (j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(  min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]  ) + 1;
        }
}
