#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
using namespace std;
//�㷨���̣�ppt7ҳ
//��������closest��lowcost�����Ǽ�¼��U��V - U������СȨֵ�ıߣ�
//����ĳ��j��V - U��closest[j]�洢�ñ���������U�еĶ����ţ�j���뼯��U��������������ŵ����ĸ��㣩��lowcost[j]�洢�ñߵ�Ȩֵ��ppt6ҳ��
//���ݽṹ���ڽӾ��󣨴�Ȩ��
typedef struct {
	int no;  //����ı��
	Infotype info; //��������Ϣ
}Vertextype;//ͼ��һ������

typedef struct {
	int edges[50][50];  //�ڽӾ�������
	int n, e; //n������e����
	Vertextype vexs[50]; //һά�������ڴ�Ŷ���
}MGraph; //һ���ڽӾ���

void Prim(MGraph g, int v)	   //Prim�㷨 vΪԴ��
{
	int lowcost[MAXV];
	int mincost;
	int closest[MAXV], i, j, k;
	for (j = 0; j < g.n; j++)	   //����ʼ��lowcost��closest���飬��ʼʱ����Uֻ����Դ��
	{
		lowcost[j] = g.edges[v][j];
		closest[j] = v;
	}
	for (i = 1; i < g.n; i++)		//�ҳ�(n-1)������
	{
		mincost = INF;
		for (j = 0; j < g.n; j++)		//��(V-U)���ҳ���U����Ķ���k
			if (lowcost[j] != 0 && lowcost[j] < mincost)
			{
				mincost = lowcost[j];
				k = j;			//k��¼�������ı�ţ�׼���Ѹýڵ����U
			}
		printf(" ��̱�(%d,%d)ȨΪ:%d\n", closest[k], k, mincost);
		lowcost[k] = 0;			//���k�Ѿ�����U��lowcost=0��˵���ýڵ��Ѽ���U��
		for (j = 0; j < g.n; j++)		//�޸�����lowcost��closest������U���¼�����k�ڵ㣬V-U�еĽڵ����U�����������ܾ�������k�ڵ�ľ���
			if (g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])
			{
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
	}
}



