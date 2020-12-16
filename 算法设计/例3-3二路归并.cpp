#include<iostream>
#include<vector>
using namespace std;
//归并排序的基本思想是：首先将a[0..n - 1]看成是n个长度为1的有序表，
//将相邻的k（k≥2）个有序子表成对归并，得到n / k个长度为k的有序子表；
//然后再将这些有序子表继续归并，得到n / k^2个长度为k^2的有序子表，如此反复进行下去，最后得到一个长度为n的有序表。
//若k = 2，即归并在相邻的两个有序子表中进行的，称为【二路归并】排序。
//若k > 2，即归并操作在相邻的多个有序子表中进行，则叫多路归并排序。

//循环log2n次，length依次取1、2、…、log2n。每次执行以下步骤：
//① 分解：将原序列分解成length长度的若干子序列。
//② 求解子问题：将相邻的两个子序列调用Merge算法合并成一个有序子序列。
//③ 合并：由于整个序列存放在数组中a中，排序过程是就地进行的，合并步骤不需要执行任何操作。



void Merge(int a[],int low,int mid,int high)
//递增的a[low..mid]和递增的a[mid+1..high]→递增的a[low..high]
{
	int *tmpa;
	int i = low,j = mid + 1,k = 0;
	tmpa = (int *)malloc((high - low + 1) * sizeof(int));//开辟空间存合并后的数组
	while (i <= mid && j <= high)
		if (a[i] <= a[j])		//将第1子表中的元素放入tmpa中
		{
			tmpa[k] = a[i];  i++; k++;
		}
		else			//将第2子表中的元素放入tmpa中
		{
			tmpa[k] = a[j]; j++; k++;
		}
	while (i <= mid)		//将第1子表余下部分复制到tmpa
	{
		tmpa[k] = a[i]; i++; k++;
	}
	while (j <= high)		//将第2子表余下部分复制到tmpa
	{
		tmpa[k] = a[j]; j++; k++;
	}
	for (k = 0,i = low; i <= high; k++,i++)  //将tmpa复制回a中
		a[i] = tmpa[k];
	free(tmpa);			//释放tmpa所占内存空间
}
void MergePass(int a[],int length,int n)
//一趟二路归并排序
{
	int i;
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)   //归并length长的两相邻子表
		Merge(a,i,i + length - 1,i + 2 * length - 1);
	if (i + length - 1 < n)	     		 //余下两个子表，后者长度小于length
		Merge(a,i,i + length - 1,n - 1);	 //归并这两个子表
}

void MergeSort(int a[],int n)		//二路归并算法
{
	int length;
	for (length = 1; length < n; length = 2 * length)
		MergePass(a,length,n);
}
//这是自底向上的二路归并，先处理小的，最后合成大的




void MergeSort(int a[],int low,int high)
//二路归并算法
{
	int mid;
	if (low < high)			//子序列有两个或以上元素
	{
		mid = (low + high) / 2;		//取中间位置
		MergeSort(a,low,mid);		//对a[low..mid]子序列排序
		MergeSort(a,mid + 1,high);	//对a[mid+1..high]子序列排序
		Merge(a,low,mid,high);		//将两子序列合并，见前面的算法
	}
}
//这是自顶向下的二路归并