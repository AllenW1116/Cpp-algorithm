#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//�����������������߶�Ϊn��һ�����������Σ��ҳ��Ӷ������ײ�����С·���ͣ�ֻ�������ƶ����ڵĽ�㡣
//��������n����������1��n�У���i������i�������������Ϊ2�У���һ��Ϊ��С·������2��Ϊ��С·���͡�
//�Ӷ������ײ�������С·������ô��㣨i��j����ǰ�����ֻ�У�i - 1��j - 1���ͣ�i - 1��j������
//dp[i][j]��ʾ�Ӷ���a[0][0]���ҵ���i��j�����ʱ����С·���͡�
//dp[i][j] = min(dp[i - 1][j - 1]��dp[i - 1][j]) + a[i][j]
//״̬ת�Ʒ��̣�
//dp[0][0] = a[0][0]			�����߽�
//dp[i][0] = dp[i - 1][0] + a[i][0]		���ǵ�1�еı߽磬1��i��n - 1
//dp[i][i] = dp[i - 1][i - 1] + a[i][i]		���ǶԽ��ߵı߽磬1��i��n - 1
//dp[i][j] = min(dp[i - 1][j - 1]��dp[i - 1][j]) + a[i][j]  i > 1�������������ﵽ·���Ľ��

//��pre[i][j]��ʾ���ҵ���i��j�����ʱ��С·���ϵ�ǰ����㣬����ǰ�����ֻ��������
//����i - 1��j - 1���ͣ�i - 1��j������pre[i][j]��¼ǰ�������кż��ɡ�

//�����ʾ
int a[MAXN][MAXN];
int n;  //�����β���
//�������ʾ
int ans = 0;
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];

int Search()			//����С��·��ans
{
    int i,j;
    dp[0][0] = a[0][0];
    for (i = 1; i < n; i++)		//���ǵ�1�еı߽�
    {
        dp[i][0] = dp[i - 1][0] + a[i][0];
        pre[i][0] = 0;
    }
    for (i = 1; i < n; i++)		//���ǶԽ��ߵı߽�
    {
        dp[i][i] = a[i][i] + dp[i - 1][i - 1];
        pre[i][i] = i - 1;
    }
    for (i = 2; i < n; i++)		//���������������ﵽ·���Ľ��
    {
        for (j = 1; j < i; j++)
        {
            if (dp[i - 1][j - 1] < dp[i - 1][j])
            {
                pre[i][j] = j - 1;
                dp[i][j] = a[i][j] + dp[i - 1][j - 1];
            }
            else
            {
                pre[i][j] = j;
                dp[i][j] = a[i][j] + dp[i - 1][j];
            }
        }
    }


    ans = dp[n - 1][0];//�𰸾������һ����С����
    int k = 0;
    for (j = 1; j < n; j++)	//�����Сans�Ͷ�Ӧ���к�k
    { //  dp��ά��������һ������С���Ǹ�ֵ����ans��·���ͣ���k�����ճ��ڵ��к�
        if (ans > dp[n - 1][j])
        {
            ans = dp[n - 1][j];
            k = j;
        }
    }
    return k;
}


void Disppath(int k)		//�����С��·��
{
    int i = n - 1;
    vector<int> path;		//�����·������path
    while (i >= 0)		//�ӣ�n-1,k����㷴���������·��
    {
        path.push_back(a[i][k]);
        k = pre[i][k];		//��С·����ǰһ���е��к�
        i--;			//��ǰһ�в���
    }
    vector<int>::reverse_iterator it;		//���巴�������
    for (it = path.rbegin(); it != path.rend(); ++it)
        printf("%d ", *it);	//���������������·����ֻ����кţ�
    printf("\n");
}






