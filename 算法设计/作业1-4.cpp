#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//4. ����n��������ͬ��������������˳����������a[0..n - 1]�У�������һ���±�i��0��i < n����ʹ��a[i] = i��
//���һ���㷨��O(log2n)ʱ���ҵ�����±�i��

//��ʱ�������˰��죬ͻȻ��ʶ�����������Ǹ��ġ���
//��Ȼʹ�ö��ֲ���
int Search(int a[], int n) {
	int l = 0, r = n - 1, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] == mid)
			return mid;
		if (a[mid] < mid)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}
//����Ŀ��Ϊ�򵥾Ͳ���������