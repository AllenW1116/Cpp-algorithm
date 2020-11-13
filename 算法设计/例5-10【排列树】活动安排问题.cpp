#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>

//【问题描述】假设有一个需要使用某一资源的n个活动所组成的集合S，S = { 1，…，n }。
//该资源任何时刻只能被一个活动所占用，活动i有一个开始时间bi和结束时间ei（bi < ei），其执行时间为ei - bi，假设最早活动执行时间为0。
//一旦某个活动开始执行，中间不能被打断，直到其执行完毕。
//若活动i和活动j有bi≥ej（i在j后面执行） 或 bj≥ei（j在i后面执行），则称这两个活动兼容。
//设计算法求一种最优活动安排方案，使得所有安排的活动个数最多。

//想要安排活动个数最多，即：该种方案的兼容数最多
//
//问题表示
struct Action
{
	int b;				//活动起始时间
	int e;				//活动结束时间
};
int n = 4;
Action A[] = { {0,0},{1,3},{2,5},{4,8},{6,10} }; //下标0不用

//问题的求解结果表示：
int x[MAX];		//临时解向量
int bestx[MAX];	//最优解向量
int laste = 0;		//一个调度方案中最后兼容活动的结束时间,初值为0（初始时没有活动 结束时间为0）
int sum = 0;		//一个调度方案中所有兼容活动个数,初值为0
int maxsum = 0;

void dfs(int i)	//搜索活动问题最优解
{
    if (i > n)		//到达叶子结点,产生一种调度方案
    {
        if (sum > maxsum)
        {
            maxsum = sum;
            for (int k = 1; k <= n; k++)
                bestx[k] = x[k];
        }
    }
    else
    {
        for (int j = i; j <= n; j++)	  	//没有到达叶子结点,考虑i到n的活动
        {    				//第i层结点选择活动x[j]
            swap(x[i], x[j]);		//排序树问题递归框架:交换x[i],x[j]
            int sum1 = sum;		//保存sum，laste以便回溯
            int laste1 = laste;
            if (A[x[i]].b >= laste)	//活动x[j]与前面兼容
            {
                sum++;			//兼容活动个数增1
                laste = A[x[i]].e;		//修改本方案的最后兼容时间
            }
            dfs(i + 1);			//排序树问题递归框架:进入下一层
            swap(x[i], x[j]);		//排序树问题递归框架:交换x[i],x[j](回溯 即换回去)
            sum = sum1;			//回溯
            laste = laste1;		//即撤销第i层结点对活动x[j]的选择
        }
    }
}
