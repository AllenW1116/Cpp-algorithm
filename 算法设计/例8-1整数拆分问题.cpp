#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
using namespace std;
//��������������������n�����ֳ������Ϊk����Ϊn��k��֣��Ĳ�ַ���������Ҫ�����еĲ�ַ������ظ���
//��������⡿��n = 5��k = 5����Ӧ�Ĳ�ַ����У�
//�� 5 = 5
//�� 5 = 4 + 1
//�� 5 = 3 + 2
//�� 5 = 3 + 1 + 1
//�� 5 = 2 + 2 + 1
//�� 5 = 1 + 1 + 1 + 1
//�� 5 = 1 + 1 + 1 + 1 + 1
//Ϊ�˷�ֹ�ظ��������ò�������ִӴ�С����������5�Ĳ����Ϊ7��
//������ʽ����ppt31ҳ
//������ʽ��
//��n = 1����k = 1�� f��n��k��= 1
//��n < k��f��n��k�� = f(n��n)
//��n = k��f��n��k�� = f(n��n - 1) + 1
//���������f(n - k��k) + f(n��k - 1)  ����k�����+������k�����


int dp[MAXN][MAXN];			//��̬�滮����
void Split(int n,int k)		//����㷨
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++)
        {
            if (i == 1 || j == 1)
                dp[i][j] = 1;
            else if (i < j)
                dp[i][j] = dp[i][i];
            else if (i == j)
                dp[i][j] = dp[i][j - 1] + 1;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
        }
    }
}

//�÷��������Ժ͵ݹ鷨���һ�£�������¼������
int dpf(int n��int k)			//����㷨
{
    if (dp[n][k] != 0) return dp[n][k];
    if (n == 1 || k == 1)
    {
        dp[n][k] = 1; return dp[n][k];
    }
    else if (n < k)
    {
        dp[n][k] = dpf(n��n); return dp[n][k];
    }
    else if (n == k)
    {
        dp[n][k] = dpf(n��k - 1) + 1; return dp[n][k];
    }
    else
    {
        dp[n][k] = dpf(n��k - 1) + dpf(n - k��k); return dp[n][k];
    }
}
