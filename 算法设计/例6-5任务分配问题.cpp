#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
using namespace std;
//�ͱ����������ƣ�Ҳ���÷�֧���޷�����Ӽ�������
struct NodeType		//���н������
{
	int no;			//�����
	int i;			//��Ա���
	int x[MAXN];		//x[i]Ϊ��Աi�����������
	bool worker[MAXN];		//worker[i]=true��ʾ����i�Ѿ�����
	int cost;			//���Ѿ�������������Ҫ�ĳɱ�
	int lb;			//�½�
	bool operator<(const NodeType& s) const	//����<��ϵ��������Ҫʹ�����ȶ��� ��Ҫ�����ع�ϵ��������
	{
		return lb > s.lb;
	}
};


void bound(NodeType& e)	     //����e���޽�ֵ��ʣ��δ������Ա���ܵ���С���䷽����	
{
	int minsum = 0;
	for (int i1 = e.i + 1; i1 <= n; i1++) //��c[e.i+1..n]������СԪ�غ�
	{
		int minc = INF;
		for (int j1 = 1; j1 <= n; j1++) {
			if (e.worker[j1] == false && c[i1][j1] < minc)//�����н�������û�з��������
				minc = c[i1][j1];
		}
		minsum += minc;
	}
	e.lb = e.cost + minsum;
}
//�����ʾ
int n = 4;
int c[MAXN][MAXN] = { {0},{0,9,2,7,8},{0,6,4,3,7},
	{0,5,8,1,8},{0,7,6,9,4} };
//�±�0��Ԫ�ز���
int bestx[MAXN];		//���ŷ��䷽��
int mincost = INF;		//��С�ɱ�
int total = 1;			//�������ۼ�

void bfs()				//����������
{
	int j;
	NodeType e, e1;
	priority_queue<NodeType> qu;
	memset(e.x, 0, sizeof(e.x));	//��ʼ��������x
	memset(e.worker, 0, sizeof(e.worker));//��ʼ��������worker
	
	e.i = 0;				//����㣬ָ����ԱΪ0
	e.cost = 0;
	bound(e);				//�������lb
	e.no = total++;
	qu.push(e);			//����������

	while (!qu.empty())
	{
		e = qu.top(); qu.pop();		//���ӽ��e����ǰ������Աe.i
		if (e.i == n)			//�ﵽҶ�ӽ��
		{
			if (e.cost < mincost)	//�Ƚ������Ž�
			{
				mincost = e.cost;
				for (j = 1; j <= n; j++)
					bestx[j] = e.x[j];
			}
		}
		e1.i = e.i + 1;		//��չ������һ����Ա�����񣬶�Ӧ���e1
		for (j = 1; j <= n; j++)	//����n������
		{
			if (e.worker[j]) 	//����j�Ƿ��ѷ�����Ա,���ѷ��䣬����
				continue;
			for (int i1 = 1; i1 <= n; i1++)	//����e.x�õ�e1.x
				e1.x[i1] = e.x[i1];
			e1.x[e1.i] = j;		//Ϊ��Աe1.i��������j
			for (int i2 = 1; i2 <= n; i2++)	//����e.worker�õ�e1.worker
				e1.worker[i2] = e.worker[i2];
			e1.worker[j] = true;		//��ʾ����j�Ѿ�����
			e1.cost = e.cost + c[e1.i][j];
			bound(e1);			//��e1��lb
			e1.no = total++;
			if (e1.lb <= mincost)		//��֦
				qu.push(e1);
		}
	}
}



