#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//��������������Դ���������ǽ�����һ����һ�ֻ���������Դ��ԭ���ϡ��ʽ��豸���Ͷ����ȣ�������ط��������ʹ���ߣ�ʹ��������󡣣�ppt105ҳ��
//��������⡿���ö�̬�滮�������⡣����3���̵�A��B��C�ı�ŷֱ�Ϊ1��3��
//������Ա����Ϊn = 5���̵����m = 3��������̵�3��ʼ������
//���ö�ά��̬�滮����Ϊdp������dp[i][s]��ʾ�����̵�i���̵�m������s���˺������Ӯ�����������һ���̵꿪ʼ���ǣ���
//�������ö�ά����pnum������pnum[i][s]��ʾ���dp[i][s]ʱ��Ӧ�̵�i�ķ���������
//��Ӧ��״̬ת�Ʒ������£�
//dp[m + 1][j] = 0			  	�߽������������յ��dpֵΪ0��
//dp[i][s] = max(v[i][j] + dp[i + 1][s - j])��j�Ǳ�����	pnum[i][s] = dp[i][s]ȡ���ֵ��j��0��j��n��
//��Ȼ��dp[1][n]��������Ӯ����

//�����ʾ
int m = 3;
int n = 5;				//�̵���Ϊm,������Ϊn
int v[MAXM][MAXN] = { {0,0,0,0,0,0},{0,3,7,9,12,13},
	{0,5,10,11,11,11},{0,4,6,11,12,12} }; //����v[0]��
//�������ʾ
int dp[MAXM][MAXN];
int pnum[MAXM][MAXN];
void Plan()			  //�����ŷ���dp
{
    int maxf, maxj;
    for (int j = 0; j <= n; j++)	  //�ñ߽�����
        dp[m + 1][j] = 0;
    for (int i = m; i >= 1; i--)	  //i���̵�3��1���д���
    {
        for (int s = 1; s <= n; s++)	  //�����������Ϊs
        {
            maxf = 0;
            maxj = 0;
            for (j = 0; j <= s; j++)	  //�Ҹ��̵��������maxf�ͷ�������maxj
            {
                if ((v[i][j] + dp[i + 1][s - j]) >= maxf)
                {
                    maxf = v[i][j] + dp[i + 1][s - j];
                    maxj = j;
                }
            }
            dp[i][s] = maxf;
            pnum[i][s] = maxj;
        }
    }
}

