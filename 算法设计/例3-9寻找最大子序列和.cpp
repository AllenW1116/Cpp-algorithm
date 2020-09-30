#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//【问题描述】给定一个有n（n≥1）个整数的序列，要求求出其中最大连续子序列的和。
//例如：
//序列（ - 2，11， - 4，13， - 5， - 2）的最大子序列和为20
//序列（ - 6，2，4， - 7，5，3，2， - 1，6， - 9，10， - 2）的最大子序列和为16。
//规定一个序列最大连续子序列和至少是0（长度为0的子序列），如果小于0，其结果为0。


long max3(long a, long b, long c) {
	return(max(a, b) > max(b, c)) ? max(a, b) : max(b, c);
}

long maxSubSum(int a[],int left,int right)
//求a[left..high]序列中最大连续子序列和
{
	int i,j;
	long maxLeftSum,maxRightSum;
	long maxLeftBorderSum,leftBorderSum;
	long maxRightBorderSum,rightBorderSum;
	if (left == right)		//子序列只有一个元素时
	{
		if (a[left] > 0) 		//该元素大于0时返回它
			return a[left];
		else			//该元素小于或等于0时返回0
			return 0;
	}
	int mid = (left + right) / 2;			//求中间位置
	maxLeftSum = maxSubSum(a,left,mid);		//求左边
	maxRightSum = maxSubSum(a,mid + 1,right);	//求右边


	maxLeftBorderSum = 0,leftBorderSum = 0;
	for (i = mid; i >= left; i--)                   //求出以左边加上a[mid]元素
	{
		leftBorderSum += a[i];			//构成的序列的最大和
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}



	maxRightBorderSum = 0,rightBorderSum = 0;
	for (j = mid + 1; j <= right; j++)			//求出a[mid]右边元素
	{
		rightBorderSum += a[j];  			//构成的序列的最大和
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}



	return max3(maxLeftSum,maxRightSum,maxLeftBorderSum + maxRightBorderSum);
}

