#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//��������������n�������ͼ�ֵ�ֱ�Ϊwi��vi��1��i��n������Ʒ������Щ��Ʒ����ѡ��������������W������Ʒ�������ѡ��Ʒ��ֵ�ܺ�������ѡ���������ÿ����Ʒ������ѡ����������
//��������⡿���ö�̬�滮��ά����dp��dp[i][j]��ʾ��ǰi����Ʒ��ѡ������������j����Ʒ������ܼ�ֵ��
//��Ȼ�б߽�������dp[i][0] = 0����������װ���κ���Ʒʱ���ܼ�ֵΪ0����dp[0][j] = 0��û���κ���Ʒ��װ��ʱ���ܼ�ֵΪ0��������memset����һ���Գ�ʼ��Ϊ0��
//�������ö�ά����fk������fk[i][j]���dp[i][j]�õ����ֵʱ��Ʒi��ѡ�ļ�����
//״̬ת�Ʒ��̣�
//dp[i][j] = MAX{ dp[i - 1][j - k * w[i]] + k * v[i] }  ��dp[i][j] <dp[i - 1][j - k * w[i]] + k * v[i]��k * w[i]��j��
//fk[i][j] = k;			    	    ��Ʒiȡk��
//
//������dp[n][W]���Ǳ�������ΪW����������n����Ʒ��ͬһ��Ʒ������ѡ�񣩺�õ��ı�������ܼ�ֵ������������Ž����


//�����ʾ
int n, W;
int w[MAXN], v[MAXN];
//�������ʾ
int dp[MAXN + 1][MAXW + 1], fk[MAXN + 1][MAXW + 1];
int solve()				//�����ر�������
{
    int i, j, k;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= W; j++)   //����ÿһ��j������ÿһ��k������һ�飬�Գ�ʹ��maxv���ģ�
            for (k = 0; k * w[i] <= j; k++)
            {
                if (dp[i][j] < dp[i - 1][j - k * w[i]] + k * v[i])
                {
                    dp[i][j] = dp[i - 1][j - k * w[i]] + k * v[i];
                    fk[i][j] = k;		//��Ʒiȡk��
                }
            }
    }
    return dp[n][W];
}

void Traceback()		//���������Ž�
{
    int i = n, j = W;
    while (i >= 1)
    {
        printf("��Ʒ%d��%d�� ", i, fk[i][j]);
        j -= fk[i][j] * w[i];	//ʣ������
        i--;
    }
    printf("\n");
}


