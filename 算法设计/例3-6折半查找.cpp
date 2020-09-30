#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//基本思路：设a[low..high]是当前的查找区间（递增），首先确定该区间的中点位置mid = (low + high) / 2；然后将待查的k值与a[mid].key比较：
//（1）若k == a[mid]，则查找成功并返回该元素的物理下标；
//（2）若k<a[mid]，则由表的有序性可知a[mid..high]均大于k，因此若表中存在关键字等于k的元素，
//	则该元素必定位于左子表a[low..mid - 1]中，故新的查找区间是左子表a[low..mid - 1]；
//（3）若k>a[mid]，则要查找的k必在位于右子表a[mid + 1..high]中，即新的查找区间是右子表a[mid + 1..high]。
//	下一次查找是针对新的查找区间进行的。
int BinSearch(int a[],int low,int high,int k)//k是要查找的元素
//拆半查找算法
{
	int mid;
	if (low <= high)		//当前区间存在元素时
	{
		mid = (low + high) / 2;	//求查找区间的中间位置
		if (a[mid] == k)		//找到后返回其物理下标mid
			return mid;
		if (a[mid] > k)		//当a[mid]>k时
			return BinSearch(a,low,mid - 1,k);
		else			//当a[mid]<k时
			return BinSearch(a,mid + 1,high,k);
	}
	else return -1;		//若当前查找区间没有元素时返回-1
}
