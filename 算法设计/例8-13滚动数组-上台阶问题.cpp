#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//一个楼梯有n个台阶，上楼可以一步上1个台阶，也可以一步上2个台阶，求上楼梯共有多少种不同的走法。
//设f(n)表示上n个台阶的楼梯的【走法数】。
//显然，f(1) = 1，
//f(2) = 2（一种走法是一步上1个台阶、走2步，另外一种走法是一步上2个台阶）。
//对于大于2的n个台阶的楼梯：一种走法是第一步上1个台阶，剩余n - 1个台阶的走法数是f(n - 1)；另外一种走法是第一步上2个台阶，剩余n - 2个台阶的走法数是f(n - 2)。
//所以有：f(n) = f(n - 1) + f(n - 2)。
//将n从0开始计数，得到状态转移方程：
//f(0) = 1
//f(1) = 2
//f(n) = f(n - 1) + f(n - 2)		n > 1

//其实就是fibnacci数列
int solve()
{
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n - 1];
}
//但实际上只要一个dp[3]就可以解决问题：
//问题表示
int n;
//求解结果表示
int dp[3];
int solve1()
{
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++)
        dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
    return dp[(n - 1) % 3];
}



