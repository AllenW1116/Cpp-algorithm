#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【问题描述】给定一个有n（n≥1）个整数的序列，要求求出其中最大连续子序列的和。
//例如：
//序列（ - 2，11， - 4，13， - 5， - 2）的最大子序列和为20
//序列（ - 6，2，4， - 7，5，3，2， - 1，6， - 9，10， - 2）的最大子序列和为16。
//规定一个序列最大连续子序列和至少是0（看成0个元素构成的子序列），如果小于0，其结果为0。

int maxSubSum1(int a[], int n)
{
	int i, j, k;
	int maxSum = 0, thisSum;//thissum当前累加的元素的最大值
	for (i = 0; i < n; i++)		  //两重循环穷举所有的连续子序列
	{
		for (j = i; j < n; j++)
		{
			thisSum = 0;
			for (k = i; k <= j; k++)
				thisSum += a[k];
			if (thisSum > maxSum)  //通过比较求最大连续子序列之和
				maxSum = thisSum;
		}
	}
	return maxSum;
}
//一共有多少个子串呢？
//本算法中，每一个点i都会作为一次起点；
//当i作起点时，i+1，i+2……n都做一次终点；
//1作起点时，n-1个串；
//2作起点时，n-2个串；
//……
//n-1作起点时，1个串；
//一共n（n-1）/2个串，都比较了一遍！


//改进版：改进前面的解法，在求两个相邻子序列和时，它们之间是关联的。
//例如a[0..3]子序列和 = a[0] + a[1] + a[2] + a[3]，
//a[0..4]子序列和 = a[0] + a[1] + a[2] + a[3] + a[4]，
//在前者计算出来后，求后者时只需在前者基础上加以a[4]即可，没有必须每次都重复计算。从而提高了算法效率。
int maxSubSum2(int a[], int n)
{
	int i, j;
	int maxSum = 0, thisSum;
	for (i = 0; i < n; i++)
	{
		thisSum = 0;
		for (j = i; j < n; j++)
		{
			thisSum += a[j];  //maxSum已经包含了a[i..j-1]的最大和
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}


//解法3：更一步改进解法2。
//如果扫描中遇到负数，当前子序列和thisSum将会减小，
//若thisSum为负数，表明前面已经扫描的那个子序列可以抛弃了，（为负，即过去的这几个数的序列和对总序列和的贡献是负的！）
//则放弃这个子序列，重新开始下一个子序列的分析，并置thisSum为0。
//若这个子序列和thisSum不断增加，那么最大子序列和maxSum也不断增加。
int maxSubSum3(int a[], int n)
{
	int j, maxSum = 0, thisSum = 0;
	for (j = 0; j < n; j++)
	{
		thisSum += a[j];
		if (thisSum < 0)        //若当前子序列和为负数，重新开始下一子序列
			thisSum = 0;
		if (maxSum < thisSum)   //比较求最大连续子序列和
			maxSum = thisSum;
	}
	return maxSum;
}
//这个方法需要重新理解一下找max子串的过程了：在你找到最大子序列的第一个数前的数字加起来必为负数；
//因为如果它不负的话你可以加在你的序列里就更大了呀




