#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
//��������������n��n��1����������Ҫ�����n����ִ�У�ÿ������ֻ�ܷ����һ���ˣ�ÿ����ֻ��ִ��һ������
//��i����ִ�е�j������ĳɱ���c[i][j]��1��i��j��n��������ܳɱ���С�ķ��䷽����



int x[MAXN];		//��ʱ��
int cost = 0;		//��ʱ��ĳɱ�
int bestx[MAXN];	//���Ž�   x��i��=j��ʾ��Աi��������j��Ϊ0����û��������
int mincost = 9999;	//���Ž�ĳɱ�
bool worker[MAXN];	//worker[j]��ʾ����j�Ƿ��Ѿ�������Ա,
int n = 4;
int c[MAXN][MAXN] = { {0},{0,9,2,7,8},{0,6,4,3,7},
                   {0,5,8,1,8},{0,7,6,9,4} };



void dfs(int i)			//Ϊ��i����Ա��������
{
    if (i > n)				//����Ҷ�ӽ��
    {
        if (cost < mincost)		//�Ƚ������Ž�
        {
            mincost = cost;
            for (int j = 1; j <= n; j++)
                bestx[j] = x[j];
        }
    }
    else
    {
        for (int j = 1; j <= n; j++)		//Ϊ��Աi��̽����j:1��n
            if (!worker[j])		//������j��û�з���
            {
                worker[j] = true;
                x[i] = j;			//����j�������Աi
                cost += c[i][j];
                dfs(i + 1);			//Ϊ��Աi+1��������
                worker[j] = false;		//����
                x[i] = 0;
                cost -= c[i][j];
            }
    }
}

