#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//给定一个有n（n≥1）个整数的序列，要求求出其中最大连续子序列的和。
//例如
//序列（ - 2，11， - 4，13， - 5， - 2）的最大子序列和为20

//问题表示
int n = 6;
int a[] = { 0, - 2,11, - 4,13, - 5, - 2 };	//a数组不用下标为0的元素
//求解结果表示
int dp[MAXN]; //dp[i]表示以a[i]结尾的数组的最大子序列和
void maxSubSum()			//求dp数组
{
	dp[0] = 0;
	for (int j = 1; j <= n; j++)
		dp[j] = max(dp[j - 1] + a[j],a[j]);
}

void dispmaxSum()			//输出结果
{
	int maxj = 1;
	for (int j = 2; j <= n; j++)		//求dp中最大元素dp[maxj]
		if (dp[j] > dp[maxj]) maxj = j;
	for (int k = maxj; k >= 1; k--)		//找前一个值小于等于0者,最大序列就是从它后一位开始的！
		if (dp[k] <= 0) break;
	printf("    最大连续子序列和: %d\n", dp[maxj]);
	printf("    所选子序列: ");
	for (int i = k + 1; i <= maxj; i++)
		printf("%d ", a[i]);
	printf("\n");
}
