#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>
#define MAXN 2			
using namespace std;


//�����ʾ��ppt18ҳ
struct NodeType		//�����еĽ������
{
	int no;			//����ţ���1��ʼ
	int i;			//��ǰ����������ռ��еĲ��
	int w;			//��ǰ����������
	int v;			//��ǰ�����ܼ�ֵ
	int x[MAXN];		//��ǰ�������Ľ�����
	double ub;			//�Ͻ�
};
int w[]; //��������
int v[]; //��ֵ����
int bestx[]; //������
int W; //�������

//���ڵ�i����Ʒ���ԣ�e.w��ʾ���eʱ��װ�������������e.v��ʾ��װ����ܼ�ֵ��
//�������ʣ�����Ʒ����װ�뱳������ô��ֵ���Ͻ�e.ub = e.v + (v[i + 1] + �� + v[n])
//�������ʣ�����Ʒ����ȫ��װ�뱳������ô��ֵ���Ͻ�e.ub = e.v + (v[i + 1] + �� + v[k]) + (��Ʒk + 1װ��ġ�����������)����Ʒk + 1�ġ���λ��ֵ��
void bound(NodeType& e)			//�����֦���e���Ͻ�
{
	int i = e.i + 1;				//���ǽ��e��������Ʒ
	int sumw = e.w;				//����װ���������
	double sumv = e.v;				//����װ����ܼ�ֵ
	while ((sumw + w[i] <= W) && i <= n)
	{
		sumw += w[i];				//���㱳����װ������
		sumv += v[i];				//���㱳����װ���ֵ
		i++;
	}
	if (i <= n)					//������Ʒֻ�ܲ���װ��
		e.ub = sumv + (W - sumw) * v[i] / w[i];
	else						//������Ʒȫ������װ��
		e.ub = sumv;
}

void EnQueue(NodeType e, queue<NodeType>& qu)
//���e����qu
{
	if (e.i == n)					//����Ҷ�ӽ��
	{
		if (e.v > maxv)				//�ҵ������ֵ�Ľ�
		{
			maxv = e.v;
			for (int j = 1; j <= n; j++)
				bestx[j] = e.x[j];
		}
	}
	else qu.push(e);				//��Ҷ�ӽ�����
}

void bfs()				//��0/1���������Ž�
{
	int j;
	NodeType e, e1, e2;			//����3�����
	queue<NodeType> qu;		//����һ������


	e.i = 0;				//������ó�ֵ�����μ�Ϊ0
	e.w = 0; e.v = 0;
	e.no = total++;
	for (j = 1; j <= n; j++)
		e.x[j] = 0;
	bound(e);				//��������Ͻ�
	qu.push(e);				//��������


	while (!qu.empty())				//�Ӳ���ѭ��
	{
		e = qu.front(); qu.pop();			//���ӽ��e
		if (e.w + w[e.i + 1] <= W)			//��֦��������ӽ�� ������װ��
		{
			e1.no = total++; e1.i = e.i + 1;		//�������ӽ��
			e1.w = e.w + w[e1.i];
			e1.v = e.v + v[e1.i];
			for (j = 1; j <= n; j++)			//���ƽ�����
				e1.x[j] = e.x[j];
			e1.x[e1.i] = 1; //��һ����Ľ������϶�����һ����һά������Ҫ�ֶ�����Ϊ1
			bound(e1);				//�����ӽ����Ͻ�
			EnQueue(e1, qu);			//���ӽ����Ӳ���
		}
		e2.no = total++;				//�����Һ��ӽ�㣺����Ʒ��ѡ
		e2.i = e.i + 1;
		e2.w = e.w; e2.v = e.v;
		for (j = 1; j <= n; j++)			//���ƽ�����
			e2.x[j] = e.x[j];
		e2.x[e2.i] = 0;
		bound(e2);				//���Һ��ӽ����Ͻ�
		if (e2.ub > maxv)		//���Һ��ӽ�����,�����,���򱻼�֦
			EnQueue(e2, qu);
	}
}