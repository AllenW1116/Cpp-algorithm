#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
using namespace std;
//【问题描述】有n个集装箱要装上一艘载重量为W的轮船，其中集装箱i（1≤i≤n）的重量为wi。
//不考虑集装箱的体积限制，现要选出尽可能多的集装箱装上轮船，使它们的重量之和不超过W。
//当重量限制为W时，wi越小可装载的集装箱个数越多，所以采用优先选取重量轻的集装箱装船的贪心思路。

//问题表示
int w[] = { 0,5,2,6,4,3 };		//各集装箱重量,不用下标0的元素
int n = 5, W = 10;
//求解结果表示
int maxw;				//存放最优解的总重量
int x[MAXN];				//存放最优解向量
void solve()				//求解最优装载问题
{
    memset(x, 0, sizeof(x));		//初始化解向量
    sort(w + 1, w + n + 1);			//w[1..n]递增排序
    maxw = 0;
    int restw = W;			//【剩余重量】贪心法很喜欢看【限制条件的剩余部分】！
    for (int i = 1; i <= n && w[i] <= restw; i++)
    {
        x[i] = 1;				//选择集装箱i
        restw -= w[i];			//减少剩余重量
        maxw += w[i];			//累计装载总重量
    }
}







