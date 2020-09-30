#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//对于序列a[s..t]（递增），在其中查找第k小元素（元素下标为k-1）的过程如下：
//若k - 1 = i，a[i]即为所求，返回a[i]。
//若k - 1 < i，第k小的元素应在a[s..i - 1]子序列中，递归在该子序列中求解并返回其结果。
//若k - 1 > i，第k小的元素应在a[i + 1..t]子序列中，递归在该子序列中求解并返回其结果。


int QuickSelect(int a[],int s,int t,int k)
//在a[s..t]序列中找第k小的元素
{
	int i = s,j = t, tmp;
	if (s < t)
	{
		tmp = a[s];
		while (i != j) 		 //从区间两端交替向中间扫描，直至i=j为止
		{
			while (j > i && a[j] >= tmp) j--;
			a[i] = a[j];		//将a[j]前移到a[i]的位置
			while (i < j && a[i] <= tmp) i++;
			a[j] = a[i];		//将a[i]后移到a[j]的位置
		}
		a[i] = tmp;
		if (k - 1 == i) return a[i];
		else if (k - 1 < i) return QuickSelect(a,s,i - 1,k);
		//在左区间中递归查找
		else return QuickSelect(a,i + 1,t,k);
		//在右区间中递归查找
	}
	else if (s == t && s == k - 1)	//区间内只有一个元素且为a[k-1]
		return a[k - 1];
}
