//2. 一个机器人只能向下和向右移动，每次只能移动一步，设计一个算法求它从（0，0）移动到（m，n）有多少条路径。
//根据组合数学知识，易知有（n,m）种方法
//因此该问题转化为求【组合问题】。
//首先，用数组元素a[0..k - 1]来保存一个组合，由于一个组合中所有元素不会重复出现，规定a中所有元素按递增排列。
//因为a中元素递增排列，所以a[k - 1]的取值范围只能为k～n，（否则的话前面得有负数了不然不递增）
//当a[k - 1]确定为i后，合并f(i - 1, k - 1)的一个结果便构成f(n, k)的一个组合结果。
//
//当k=0  输出a中的一种组合
//当k > 0  i取值从k到n:{ a[k - 1] = i; f(i - 1，k - 1)}  
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
using namespace std;

int a[3] = { 0,0,0 }; //存放一个组合
int countt = 0; //方法数
void comb(int n, int m)	//求1..n中m个整数的组合
{
	if (m == 0)			//k为0时输出一个组合
	{
		countt++;
	}
	else
	{
		for (int i = m; i <= n; i++)
		{
			a[m - 1] = i;		//a[m-1]位置取m～n的整数
			comb(i - 1, m - 1);
		}
	}
}

int main() {
	comb(5, 3);
	cout << "共有" << countt << "种方法！";
	return 0;

}





