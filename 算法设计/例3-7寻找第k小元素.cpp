#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��������a[s..t]���������������в��ҵ�kСԪ�أ�Ԫ���±�Ϊk-1���Ĺ������£�
//��k - 1 = i��a[i]��Ϊ���󣬷���a[i]��
//��k - 1 < i����kС��Ԫ��Ӧ��a[s..i - 1]�������У��ݹ��ڸ�����������Ⲣ����������
//��k - 1 > i����kС��Ԫ��Ӧ��a[i + 1..t]�������У��ݹ��ڸ�����������Ⲣ����������


int QuickSelect(int a[],int s,int t,int k)
//��a[s..t]�������ҵ�kС��Ԫ��
{
	int i = s,j = t, tmp;
	if (s < t)
	{
		tmp = a[s];
		while (i != j) 		 //���������˽������м�ɨ�裬ֱ��i=jΪֹ
		{
			while (j > i && a[j] >= tmp) j--;
			a[i] = a[j];		//��a[j]ǰ�Ƶ�a[i]��λ��
			while (i < j && a[i] <= tmp) i++;
			a[j] = a[i];		//��a[i]���Ƶ�a[j]��λ��
		}
		a[i] = tmp;
		if (k - 1 == i) return a[i];
		else if (k - 1 < i) return QuickSelect(a,s,i - 1,k);
		//���������еݹ����
		else return QuickSelect(a,i + 1,t,k);
		//���������еݹ����
	}
	else if (s == t && s == k - 1)	//������ֻ��һ��Ԫ����Ϊa[k-1]
		return a[k - 1];
}
