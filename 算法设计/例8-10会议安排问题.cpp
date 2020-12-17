#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//其实就是流水线问题！求本质是求兼容数
//用数组A存放所有的订单，A[i].b（0≤i≤n - 1）存放订单i的起始时间，A[i].e存放订单i的结束时间，订单i的持续时间A[i].length = A[i].e - A[i].b。
//
//这里采用贪心法 + 动态规划的思路，先将订单数组A按结束时间递增排序，设计一维动态规划数组dp，dp[i]表示A[0..i]的订单中所有兼容订单的最长时间。
//对应的状态转移方程如下：
//dp[0] = 订单0的时间
//dp[i] = max{ dp[i - 1]，dp[j] + A[i].length }    订单j是结束时间早于订单i开始时间的最晚的订单
//												（由于所有订单是按结束时间递增排序的，所以可以采用查找方法在A[0..i - 1]中查找A[j].e≤A[i].b的最后一个A[j]。）
//最后求出的dp[n - 1]就是满足要求的结果。
//
//另外为了求出选中的哪些订单，设计一维数组pre，pre[i]表示dp[i]的前驱订单，这里有3种情况：
//A[i]没有前驱订单，pre[i]设置为 - 1。例如订单0没有前驱订单，置pre[0] = -1。
//若不选择订单A[i]，pre[i]设置为 - 2。例如，i = 2时，该方案已经选中了订单1但不选中订单2，则pre[2] = -2。
//若选择订单A[i]并且它前面最晚的前驱订单为A[j]，则pre[i]设置为j。例如，该方案已经选中了订单1、3，考虑i = 5时，前面最晚的前驱订单订单3，则pre[5] = 3。


//问题表示
struct NodeType
{
	int b;			//开始时间
	int e;			//结束时间
	int length;			//订单的执行时间
	bool operator < (const NodeType t) const
	{				//用于排序的运算符重载函数
		return e < t.e;		//按结束时间递增排序
	}
};
int n = 11;			//订单个数
NodeType A[MAX] = { {1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},
   {8,12},{2,13},{12,15} };	//存放订单
//求解结果表示
int dp[MAX];			//动态规划数组
int pre[MAX];			//pre[i]存放前驱订单编号

void solve()			//求dp和pre
{
	memset(dp, 0, sizeof(dp));	//dp数组初始化
	stable_sort(A, A + n);	//采用稳定的排序算法（想要使用排序，先要在你定义的结构体中重载比较符号哦！）
	dp[0] = A[0].length;
	pre[0] = -1;
	for (int i = 1; i < n; i++)
	{
		int low = 0, high = i - 1;
		while (low <= high)	//在A[0..i-1]中查找结束时间早于  (二分查找优化一下
				  //A[i].b的最晚订单A[low-1]
		{
			int mid = (low + high) / 2;
			if (A[mid].e <= A[i].b)
				low = mid + 1;
			else
				high = mid - 1;
		}

		if (low == 0)			//特殊情况：没有比它更靠前的订单。它只能作为第一个
		{
			if (dp[i - 1] >= A[i].length)
			{
				dp[i] = dp[i - 1];
				pre[i] = -2;			//不选中订单i
			}
			else
			{
				dp[i] = A[i].length;
				pre[i] = -1;			//没有前驱订单
			}
		}
		else		//A[i]前面最晚有兼容订单A[low-1]
		{
			if (dp[i - 1] >= dp[low - 1] + A[i].length)
			{
				dp[i] = dp[i - 1];
				pre[i] = -2;			//不选择订单i
			}
			else
			{
				dp[i] = dp[low - 1] + A[i].length;
				pre[i] = low - 1;		//选中订单i
			}
		}
	}
}
