#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��������⡿������������a[low.high]�У����÷��η������Ԫ��max1�ʹδ�Ԫ��max2�Ĺ������£�
//��1��a[low.high]��ֻ��һ��Ԫ�أ���max1 = a[low]��max2 = -INF�� - �ޣ���Ҫ�������ǲ�ͬ��Ԫ�أ���
//��2��a[low.high]��ֻ������Ԫ�أ���max1 = MAX{ a[low]��a[high] }��max2 = MIN{ a[low]��a[high] }��
//��3��a[low.high]������������Ԫ�أ����м�λ��mid = (low + high) / 2����Ϊa[low..mid]��a[mid + 1..high]�����������䣨ע�����������a[mid]Ԫ�أ���
//������������Ԫ��lmax1�ʹδ�Ԫ��lmax2��������������Ԫ��rmax1�ʹδ�Ԫ��rmax2��
//�ϲ�����lmax1 > rmax1����max1 = lmax1��max2 = MAX{ lmax2��rmax1 }������max1 = rmax1��max2 = MAX{ lmax1��rmax2 }��
static int INF = 65536;
void solve(int a[], int low, int high, int &max1, int &max2)
{
	if (low == high)		//����ֻ��һ��Ԫ��
	{
		max1 = a[low];	max2 = -INF;
	}
	else if (low == high - 1)	//����ֻ������Ԫ��
	{
		max1 = max(a[low], a[high]); max2 = min(a[low], a[high]);
	}
	else			//��������������Ԫ��
	{
		int mid = (low + high) / 2;
		int lmax1, lmax2;
		solve(a, low, mid, lmax1, lmax2);	     //��������lmax1��lmax2
		int rmax1, rmax2;
		solve(a, mid + 1, high, rmax1, rmax2);  //��������lmax1��lmax2
		if (lmax1 > rmax1)
		{
			max1 = lmax1;
			max2 = max(lmax2, rmax1);	//lmax2,rmax1����δ�Ԫ��
		}
		else
		{
			max1 = rmax1;
			max2 = max(lmax1, rmax2);	//lmax1,rmax2����δ�Ԫ��
		}
	}
}