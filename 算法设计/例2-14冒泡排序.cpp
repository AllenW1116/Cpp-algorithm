#include<iostream>
#include<vector>
using namespace std;

//��f(a��n��i)���ڶ�a[i..n - 1]Ԫ�����У���n - i��Ԫ�أ�����ð�������ǡ������⡱��
//��f(a��n��i + 1)���ڶ�a[i + 1..n - 1]Ԫ�����У���n - i - 1��Ԫ�أ�����ð�������ǡ�С���⡱��
//��i = n - 1ʱ����Ԫ�������㷨��������
//
//
//
//��i = n - 1 �����κ����飬�㷨����
//
//���� ��a[i..n - 1]Ԫ�����У���a[n - 1]��ʼ
//��������Ԫ�رȽ�;			
//��������Ԫ�ط��������߽���;
//��û�н����򷵻أ�����ִ��f(a��n��i + 1);

void BubbleSort(int a[],int n,int i)
{
	int  j;
	bool exchange;
	if (i == n - 1) return;		//����ݹ��������
	else
	{
		exchange = false;		//��exchangeΪfalse
		for (j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])		//������Ԫ�ط���ʱ
			{
				swap(a[j], a[j - 1]);
				exchange = true;	//����������exchangeΪtrue
			}
		if (exchange == false)		//δ��������ʱֱ�ӷ��ء�����
			return;
		else				//��������ʱ�����ݹ���ã�һ��ð�ݿ��԰���������С��Ԫ�ع�λ��
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
