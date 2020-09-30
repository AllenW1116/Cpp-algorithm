#include<iostream>
#include<vector>
using namespace std;
//基本思想：在待排序的n个元素中任取一个元素（通常取第一个元素）作为基准，把该元素放入最终位置后，
//整个数据序列被基准分割成两个子序列，所有小于基准的元素放置在前子序列中，所有大于基准的元素放置在后子序列中，
//并把基准排在这两个子序列的中间，这个过程称作划分。
//然后对两个子序列分别重复上述过程，直至每个子序列内只有一个记录或空为止。
//
//当a[s..t]中长度小于2：不做任何事情
//
//其他情况：
//f(a, s, t) ≡ i = Partition(a, s, t);
//f(a, s, i - 1);
//f(a, i + 1, t);

int Partition(int a[],int s,int t)	//划分算法,把第一个元素放入最终位置
{
	int i = s,j = t;
	int tmp = a[s];		//用序列的第1个记录作为基准
	while (i != j)			//从序列两端交替向中间扫描，直至i=j为止     
	{
		while (j > i && a[j] >= tmp)
			j--;    		//从右向左扫描，找第1个关键字小于tmp的a[j]
		a[i] = a[j];		//将a[j]前移到a[i]的位置
		while (i < j && a[i] <= tmp)
			i++;   		//从左向右扫描，找第1个关键字大于tmp的a[i]
		a[j] = a[i];		//将a[i]后移到a[j]的位置
	}
	a[i] = tmp;
	return i;
}


void QuickSort(int a[],int s,int t) //快速排序
//对a[s..t]元素序列进行递增排序
{
	if (s < t) 			//序列内至少存在2个元素的情况
	{
		int i = Partition(a,s,t);
		QuickSort(a,s,i - 1);	//对左子序列递归排序
		QuickSort(a,i + 1,t);	//对右子序列递归排序
	}
}


