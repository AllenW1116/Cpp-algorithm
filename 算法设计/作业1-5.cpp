#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//5. 请你模仿二分查找过程设计一个三分查找算法。分析其时间复杂度。
int TriSearch(int a[], int low, int high, int k)//k是要查找的元素,a[]是一个递增序列
//拆半查找算法
{
	int lmid,hmid;
	if (low <= high)		//当前区间存在元素时
	{
		hmid = (high-low) *2/3+low;	
		lmid = (high - low) * 1 / 3+low; 
		if (a[lmid] == k || a[hmid]==k)		//找到后返回其物理下标
			return (a[lmid]==k)?lmid:hmid;

		if (a[lmid] > k)
			return TriSearch(a, low, lmid - 1, k);
		else if (a[hmid] < k)
			return TriSearch(a, hmid + 1, high, k);
		else
			return TriSearch(a, lmid + 1, hmid - 1, k);
	}
	else return -1;		//若当前查找区间没有元素时返回-1
}

int main1() {
	int A[] = { 1,2,3,4,5,6 };
	cout << TriSearch(A, 0, 5,6);//测试通过
	return 0;
}

//显然时间复杂度：Log3N