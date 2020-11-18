#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//���������װ�뱳��������ֵ�������������x����
//���ڵ�i���׶Σ�������Ʒi���Ľ�dp[i][*]ֻ���i - 1���׶Σ�������Ʒi - 1���Ľ�dp[i - 1][*]�йأ���������±����ǰ��������Ѿ��������塣
//���Կ������ù�����������Ż�����dp������dp[MAXN][MAXW]��Ϊdp[2][MAXW]��
//��0 / 1���������״̬ת�Ʒ������£�
//dp[0][0] = 0��dp[1][0] = 0
//dp[0][r] = 0
//dp[c][r] = dp[1 - c][r]			��r < w[i]ʱ����Ʒi�Ų���
//dp[c][r] = MAX{ dp[1 - c][r]��dp[1 - c][r - w[i]] + v[i] }  �����ڲ�����ͷ�����Ʒi֮��ѡ���Ž�
//�ؼ��仯��1-c������Ϊ����0�о���1��

void Knap()			//��̬�滮����0/1��������
{
	int i, r;
	int c = 0;
	for (i = 0; i <= 1; i++)		//�ñ߽�����dp[0..1][0]=0
		dp[i][0] = 0;
	for (r = 0; r <= W; r++)		//�ñ߽�����dp[0][r]=0
		dp[0][r] = 0;
	for (i = 1; i <= n; i++)
	{
		c = 1 - c;
		for (r = 1; r <= W; r++)
		{
			if (r < w[i])
				dp[c][r] = dp[1 - c][r];
			else
				dp[c][r] = max(dp[1 - c][r], dp[1 - c][r - w[i]] + v[i]);
		}
	}
}

