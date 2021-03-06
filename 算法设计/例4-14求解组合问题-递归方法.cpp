#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【问题描述】求1～n的正整数中取k（k≤n）个不重复整数的所有组合。
//【问题求解】用数组元素a[0..k - 1]来保存一个组合，由于一个组合中所有元素不会重复出现，规定a中所有元素按递增排列。
//大问题：f(n, k)从1～n中任取k个数的所有组合。
//小问题：f(m, k - 1)从1～m中任取k - 1个数的所有组合。
//
//因为a中元素递增排列，所以a[k - 1]的取值范围只能为k～n，（否则的话前面得有负数了不然不递增）
//当a[k - 1]确定为i后，合并f(i - 1, k - 1)的一个结果便构成f(n, k)的一个组合结果。
//
//当k=0  输出a中的一种组合
//当k > 0  i取值从k到n:{ a[k - 1] = i; f(i - 1，k - 1)}  （体现蛮力思想！我们要求数组a[k],得知数组的最后一个元素的取值范围；
//那就让最后一个元素把每个可能的值都取一遍！）
//图解过程见ppt80页

int a[]; //存放一个组合
void comb(int n, int k)	//求1..n中k个整数的组合
{
	if (k == 0)			//k为0时【输出】一个组合
		dispacomb();
	else
	{
		for (int i = k; i <= n; i++)
		{
			a[k - 1] = i;		//a[k-1]位置取k～n的整数
			comb(i - 1, k - 1);
		}
	}
}


