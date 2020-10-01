#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//4. 设有n个互不相同的整数，按递增顺序存放在数组a[0..n - 1]中，若存在一个下标i（0≤i < n），使得a[i] = i。
//设计一个算法以O(log2n)时间找到这个下标i。

//当时看完懵了半天，突然意识到整数可以是负的……
//显然使用二分查找
int Search(int a[], int n) {
	int l = 0, r = n - 1, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] == mid)
			return mid;
		if (a[mid] < mid)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}
//此题目较为简单就不做测试了