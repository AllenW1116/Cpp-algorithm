#include<iostream>
#include<vector>
using namespace std;

//设f(a，n，i)用于对a[i..n - 1]元素序列（共n - i个元素）进行冒泡排序，是“大问题”，
//则f(a，n，i + 1)用于对a[i + 1..n - 1]元素序列（共n - i - 1个元素）进行冒泡排序，是“小问题”。
//当i = n - 1时所有元素有序，算法结束。　
//
//
//
//当i = n - 1 不做任何事情，算法结束
//
//否则 对a[i..n - 1]元素序列，从a[n - 1]开始
//进行相邻元素比较;			
//若相邻两元素反序则将两者交换;
//若没有交换则返回，否则执行f(a，n，i + 1);

void BubbleSort(int a[],int n,int i)
{
	int  j;
	bool exchange;
	if (i == n - 1) return;		//满足递归出口条件
	else
	{
		exchange = false;		//置exchange为false
		for (j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])		//当相邻元素反序时
			{
				swap(a[j], a[j - 1]);
				exchange = true;	//发生交换置exchange为true
			}
		if (exchange == false)		//未发生交换时直接返回　　　
			return;
		else				//发生交换时继续递归调用（一趟冒泡可以把无序区最小的元素归位）
			BubbleSort(a,n,i + 1);
	}
}
//
//int main() {
//
//	int A[] = { 2,3,4,5,1 };
//	BubbleSort(A, 5, 0);
//	for (int i = 0; i < 5; i++) {
//		cout << A[i];
//	}
//	return 0;
//}
