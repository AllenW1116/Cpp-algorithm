#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//5. ����ģ�¶��ֲ��ҹ������һ�����ֲ����㷨��������ʱ�临�Ӷȡ�
int TriSearch(int a[], int low, int high, int k)//k��Ҫ���ҵ�Ԫ��,a[]��һ����������
//�������㷨
{
	int lmid,hmid;
	if (low <= high)		//��ǰ�������Ԫ��ʱ
	{
		hmid = (high-low) *2/3+low;	
		lmid = (high - low) * 1 / 3+low; 
		if (a[lmid] == k || a[hmid]==k)		//�ҵ��󷵻��������±�
			return (a[lmid]==k)?lmid:hmid;

		if (a[lmid] > k)
			return TriSearch(a, low, lmid - 1, k);
		else if (a[hmid] < k)
			return TriSearch(a, hmid + 1, high, k);
		else
			return TriSearch(a, lmid + 1, hmid - 1, k);
	}
	else return -1;		//����ǰ��������û��Ԫ��ʱ����-1
}

int main1() {
	int A[] = { 1,2,3,4,5,6 };
	cout << TriSearch(A, 0, 5,6);//����ͨ��
	return 0;
}

//��Ȼʱ�临�Ӷȣ�Log3N