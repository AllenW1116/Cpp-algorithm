#include<iostream>
#include<vector>
using namespace std;

//简单选择排序
//设f(a，n，i)用于对a[i..n - 1]元素序列（共n - i个元素）进行简单选择排序，是“大问题”.
//f(a，n，i + 1)用于对a[i + 1..n - 1]元素序列（共n - i - 1个元素）进行简单选择排序，是“小问题”。
//当i = n - 1时所有元素有序，算法结束。
//f(a，n，i)  当i = n - 1：不做任何事情，算法结束
//f(a，n，i)  否则：通过简单比较挑选a[i..n - 1]中的最小元素a[k]放在a[i]处; f(a，n，i + 1);

void SelectSort(int a[],int n,int i)
{
	int j,k;
	if (i == n - 1) return;	//满足递归出口条件
	else
	{
		k = i;			//k记录a[i..n-1]中最小元素的下标
		for (j = i + 1; j < n; j++)  	//在a[i..n-1]中找最小元素
			if (a[j] < a[k])
				k = j;
		if (k != i)		//若最小元素不是a[i]
			swap(a[i], a[k]);	//a[i]和a[k]交换
		SelectSort(a,n,i + 1);
	}
}
