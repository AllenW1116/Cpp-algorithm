#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>
#include <stdio.h>
#define INF 0x3f3f3f3f		//最大整数∞
#define MAXN 42			//最多的作业数
#define max(x,y) ((x)>(y)?(x):(y))
#define max3(x,y,z) max(max(x,y),z)
#define min(x,y) ((x)<(y)?(x):(y))
#define min3(x,y,z) min(min(x,y),z)
using namespace std;
//试题名称：任务调度
//时间限制：1.0s
//内存限制：256.0MB
//问题描述：有若干个任务需要在一台机器上运行。它们之间没有依赖关系，因此 可以被按照任意顺序执行。
//该机器有两个CPU和一个GPU。对于每个任务，你可以为它分配不同的硬件资源：

//1. 在单个CPU上运行。
//2. 在两个CPU上同时运行。
//3. 在单个CPU和GPU上同时运行。
//4. 在两个CPU和GPU上同时运行。

//一个任务开始执行以后，将会独占它所用到的所有硬件资源，不得中断，直到执行结束为止。
//第i个任务用单个CPU，两个CPU，单个CPU加GPU，两个CPU加GPU运行所消耗的时间分别为ai，bi，ci 和 di。
//现在需要你计算出至少需要花多少时间可以把所有给定的任务完成。

//输入格式：输入的第一行只有一个正整数 n(1 ≤ n ≤ 40)， 是总共需要执行的任 务个数。
//接下来的 n 行每行有四个正整数ai，bi，ci，di(ai，bi，ci，di 均不超过10)，以空格隔开。
//输出格式：输出只有一个整数，即完成给定的所有任务所需的最少时间。
//样例输入：
//3
//4 4 2 2
//7 4 7 4
//3 3 3 3
//样例输出
//7
//样例说明：有很多种调度方案可以在7个时间单位里完成给定的三个任务，以下是其中的一种方案：
//同时运行第一个任务（单CPU加上GPU）和第三个任务（单CPU），它们分别在时刻2和时刻3完成。在时刻3开始双CPU运行任务2，在时刻7完成。


//问题表示
int n;					//任务数
struct node
{
	int a, b, c, d;
} A[MAXN];  // acbd对应四种执行方法

int x[MAXN];
int bestf = INF;				//存放调度时间
void swap(int& x, int& y)		//交换x和y
{
	int tmp = x;
	x = y; y = tmp;
}

// cpu1 cpu2 gpu指各个硬件上的运行时间，初始时应该都为0
void dfs(int i, int cpu1, int cpu2, int gpu)	//从第i层开始搜索
{
    int m, k, tcpu1, tcpu2, tgpu;
    if (i == n)				//到达叶结点,产生一种调度方案
    {
        m = max3(cpu1, cpu2, gpu);
        if (m < bestf)			//找到更优解
            bestf = m;
    }
    else
    {
        for (int j = i; j < n; j++)		//没有到达叶结点
        {
            swap(x[i], x[j]);		//考虑第i步选择任务x[j]	
            for (k = 1; k <= 5; k++)		//考虑运行方式
            {
                tcpu1 = cpu1; tcpu2 = cpu2; tgpu = gpu;
                if (k == 1)			//方案1：单个CPU上运行-CPU1
                    cpu1 += A[x[i]].a;
                else if (k == 2)		//方案1：单个CPU上运行-CPU2
                    cpu2 += A[x[i]].a;
                else if (k == 3)	//方案3：在CPU1和GPU上同时运行
                {
                    m = max(cpu1, gpu) + A[x[i]].c;
                    cpu1 = gpu = m;
                }
                else if (k == 4)	//方案3：在CPU2和GPU上同时运行
                {
                    m = max(cpu2, gpu) + A[x[i]].c;
                    cpu2 = gpu = m;
                }
                else if (k == 5)	//方案4：在两个CPU+GPU上同时运行
                {
                    m = max3(cpu1, cpu2, gpu) + A[x[i]].d;
                    cpu1 = cpu2 = gpu = m;
                }
                m = max3(cpu1, cpu2, gpu);
                if (m < bestf)	  	//剪枝:仅仅扩展当前总时间小于bestf的结点
                    dfs(i + 1, cpu1, cpu2, gpu);
                cpu1 = tcpu1; cpu2 = tcpu2; gpu = tgpu;
            }
            swap(x[i], x[j]);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int k = 0; k < n; k++)  //设置初始调度为作业0,1,…,n-1的顺序
        x[k] = k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &A[i].a, &A[i].b, &A[i].c, &A[i].d);
        if (A[i].b < A[i].d) A[i].d = A[i].b;
    }
    dfs(0, 0, 0, 0);
    printf("%d\n", bestf);
    return 0;
}
