#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//����������������һ����n��n��1�������������У�Ҫ���������������������еĺ͡�
//���磺
//���У� - 2��11�� - 4��13�� - 5�� - 2������������к�Ϊ20
//���У� - 6��2��4�� - 7��5��3��2�� - 1��6�� - 9��10�� - 2������������к�Ϊ16��
//�涨һ������������������к�������0������Ϊ0�������У������С��0������Ϊ0��


long max3(long a, long b, long c) {
	return(max(a, b) > max(b, c)) ? max(a, b) : max(b, c);
}

long maxSubSum(int a[],int left,int right)
//��a[left..high]������������������к�
{
	int i,j;
	long maxLeftSum,maxRightSum;
	long maxLeftBorderSum,leftBorderSum;
	long maxRightBorderSum,rightBorderSum;
	if (left == right)		//������ֻ��һ��Ԫ��ʱ
	{
		if (a[left] > 0) 		//��Ԫ�ش���0ʱ������
			return a[left];
		else			//��Ԫ��С�ڻ����0ʱ����0
			return 0;
	}
	int mid = (left + right) / 2;			//���м�λ��
	maxLeftSum = maxSubSum(a,left,mid);		//�����
	maxRightSum = maxSubSum(a,mid + 1,right);	//���ұ�


	maxLeftBorderSum = 0,leftBorderSum = 0;
	for (i = mid; i >= left; i--)                   //�������߼���a[mid]Ԫ��
	{
		leftBorderSum += a[i];			//���ɵ����е�����
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}



	maxRightBorderSum = 0,rightBorderSum = 0;
	for (j = mid + 1; j <= right; j++)			//���a[mid]�ұ�Ԫ��
	{
		rightBorderSum += a[j];  			//���ɵ����е�����
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}



	return max3(maxLeftSum,maxRightSum,maxLeftBorderSum + maxRightBorderSum);
}

