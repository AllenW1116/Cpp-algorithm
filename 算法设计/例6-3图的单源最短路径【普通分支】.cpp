#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>
#define MAXN 2			
using namespace std;
//����������������һ������Ȩ����ͼG = ��V��E��������ÿ���ߵ�Ȩ��һ����������
//���⣬������V�е�һ������v����ΪԴ�㡣�����Դ�㵽�������ж�������·�����ȡ�����ĳ�����ָ·�ϸ���Ȩ֮�͡�
struct NodeType		//���н������
{
	int vno;			//������
	int length;			//ԭ�㵽�õ��·������
};
//��dist������Դ��v���������·�����ȣ�dist[i]��ʾԴ��v������i�����·�����ȣ���ʼʱ����dist[i]ֵΪ�ޡ�
//��prev���������·����prev[i]��ʾԴ��v������i�����·���ж���i�ġ�ǰ�����㡣��
//����ͼ�⣺ppt37ҳ��

//�����ʾ
int n;			//ͼ�������
int a[MAXN][MAXN];	//ͼ���ڽӾ���
int v;			//Դ��
//�������ʾ
int dist[MAXN];	//dist[i]Դ�㵽����i�����·������
int prev[MAXN];	//prev[i]��ʾԴ�㵽j�����·���ж���j��ǰ������

void bfs(int v)			//����㷨
{
	NodeType e, e1;
	queue<NodeType> pqu;
	e.vno = v;				//����Դ����e������㣩
	e.length = 0;
	pqu.push(e);			//Դ����e����
	dist[v] = 0;
	while (!pqu.empty())		//���в���ѭ��
	{
		e = pqu.front(); pqu.pop();	//�����н��e
		for (int j = 0; j < n; j++)
		{
			if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j])
			{	//��֦��e.vno������j�б߲���·�����ȸ���
				dist[j] = e.length + a[e.vno][j];
				prev[j] = e.vno;
				e1.vno = j;		//�������ڶ���j�Ľ��e1
				e1.length = dist[j];
				pqu.push(e1);		//���e1����
			}
		}
	}
}

