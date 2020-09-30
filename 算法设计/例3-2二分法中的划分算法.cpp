#include<iostream>
#include<vector>
using namespace std;
//划分算法的补充
//我们先看这么一道题：
//假设一个线性表采用顺序表表示。设计一个算法，删除其中所有值等于x的元素。要求算法的时间复杂度为O(n)，空间复杂度为O(1)。
typedef int ElemType;

typedef struct {  //SqList为顺序表
	ElemType data[50];
	int length;
}SqList;

//方法一：重建法。直接新建一个表，将原先的表覆盖
void delnode1(SqList *&L, ElemType x)
{
	int k = 0, i;			//k记录值不等于x的元素个数
	for (i = 0; i < L->length; i++)
		if (L->data[i] != x)		//若当前元素不为x,将其插入L中
		{
			L->data[k] = L->data[i];
			k++;			//插入一个元素时元素个数增1
		}
	L->length = k;		//顺序表L的长度等于k
}
//方法二：移动法
//扫描顺序表L，用i从左到右扫描L中的所有元素，用k记录L中当前等于x的元素个数，一边扫描L一边统计当前k值。
//当i指向的元素为x时，k增1；否则将不为x的元素前移k个位置，即L->data[i - k] = L->data[i]。
//最后修改L的长度（原先的长度-k）。
void delnode2(SqList *&L, ElemType x)
{
	int k = 0, i = 0;			//k记录值等于x的元素个数
	while (i < L->length)
	{
		if (L->data[i] == x)		//当前元素值为x时k增1
			k++;
		else			//当前元素不为x时将其前移k个位置
			L->data[i - k] = L->data[i];
		i++;
	}
	L->length -= k;			//顺序表L的长度递减k
}
//方法三：区间划分法：
//初始时，“不为x的区间”为空  i = -1，j从0开始遍历，“为x的区间”是a[i + 1..j - 1]
//若a[j] = x，跳过，j++。
//若a[j]≠x，i++扩大“不为x的区间”，将a[j]与a[i]交换，扩大“为x的区间”，j++。
void delnode3(SqList *&L, ElemType x)
{
	int i = -1,j = 0;
	int n = L->length;
	while (j < n)			//j扫描所有元素
	{
		if (L->data[j] != x)		//找到不为x的元素
		{
			i++;			//扩大不为x的区间
			if (i != j)		//将data[j]交换到不为x区间的末尾
				swap(L->data[i],L->data[j]);
		}
		j++;			//继续扫描
	}
	L->length = i + 1;		//设置顺序表的长度
}

