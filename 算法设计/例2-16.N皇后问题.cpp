#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

bool place(int i, int j)		//����(i,j)λ���ܷ�ڷŻʺ�
{
    if (i == 1) return true;		//��һ���ʺ����ǿ��Է���
    int k = 1;
    while (k < i)			//k=1��i-1���ѷ����˻ʺ����
    {
        if ((q[k] == j) || (abs(q[k] - j) == abs(i - k)))
            return false;
        k++;
    }
    return true;
}
void queen(int i, int n)		//����1��i�Ļʺ�i�ǵ�i�� ��ʼ1
{
    if (i > n)
        dispasolution(n);		//���лʺ���ý���
    else
    {
        for (int j = 1; j <= n; j++)	//�ڵ�i������̽ÿһ����j��֮ǰ���Ӽ������� ���֣�������n�֣�
            if (place(i, j))		//�ڵ�i�����ҵ�һ������λ��(i,j)
            {
                q[i] = j;
                queen(i + 1, n);
            }
    }
}