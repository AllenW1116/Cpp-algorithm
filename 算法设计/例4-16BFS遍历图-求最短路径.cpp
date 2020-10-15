#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include"�ڽӱ�.h"
#include"�ڽӾ���.h"
#include<queue>
using namespace std;

//���ȿ�һ��ͼ��BFS���
//������������Ĺ����ǣ�
//��1�����ȷ��ʳ�ʼ����v��
//��2�����ŷ��ʶ���v������δ�����ʹ����ڽӵ�v1��v2������vt��
//��3��Ȼ���ٰ���v1��v2������vt�Ĵ��򣬷���ÿһ�����������δ�����ʹ����ڽӵ㣬�������ƣ�ֱ��ͼ�����кͳ�ʼ����v��·����ͨ�Ķ��㶼�����ʹ�Ϊֹ��

const int MAXV = 20;

void BFS_M(Matgraph g, int v)			//�ڽӾ����BFS�㷨
{
	queue<int> qu;			//����һ������qu
	int visited[MAXV];			//�����Ž��ķ��ʱ�־������
	int w, i;
	memset(visited, 0, sizeof(visited));	//���ʱ�־�����ʼ��(ȫ������0)
	printf("%3d", v);			//��������ʶ���ı��
	visited[v] = 1;				//���ѷ��ʱ��
	qu.push(v);				//v����
	while (!qu.empty())			//���в���ʱѭ��
	{
		w = qu.front(); qu.pop();		//���Ӷ���w  queue.front():��ȡ����Ԫ��
		for (i = 0; i < g.n; i++)		//���붥��w���ڵĶ���
			if (g.edges[w][i] != 0 && g.edges[w][i] != 32767 && visited[i] == 0)
			{		//����ǰ�ڽӶ���iδ������
				printf("%3d", i);		//�������ڶ���
				visited[i] = 1;			//�øö����ѱ����ʵı�־
				qu.push(i);			//�ö������
			}
	}
	printf("\n");
}

void BFS_G( AdjGraph *G, int v)		//�ڽӱ��BFS�㷨
{
	ArcNode *p;
	queue<int> qu;			//����һ������qu
	int visited[MAXV], w;			//�����Ŷ���ķ��ʱ�־������
	memset(visited, 0, sizeof(visited));	//���ʱ�־�����ʼ��
	printf("%3d", v);			//��������ʶ���ı��
	visited[v] = 1; 			//���ѷ��ʱ��
	qu.push(v);				//v����
	while (!qu.empty())			//���в���ʱѭ��
	{
		w = qu.front(); qu.pop();		//���Ӷ���w
		p = G->adjlist[w].firstarc;		//�Ҷ���w�ĵ�һ���ڽӵ�
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)	//����ǰ�ڽӶ���δ������
			{
				printf("%3d", p->adjvex);	//�������ڶ���
				visited[p->adjvex] = 1;	//�øö����ѱ����ʵı�־
				qu.push(p->adjvex);		//�ö������
			}
			p = p->nextarc;			//�Ҷ���w����һ���ڽӵ�
		}
	}
}

//����4.8������ͼG�����ڽӱ�洢�����һ���㷨���󲻴�Ȩ������ͨͼG�дӶ���u������v��һ�����·����
//�⣺ͼG�ǲ���Ȩ��������ͨͼ��һ���ߵĳ��ȼ�Ϊ1����ˣ��󶥵�u�Ͷ���v�����·��������붥��u������v�ı������ٵĶ������С�
//���ù�����ȱ����㷨����u����һ��һ���������չ����չ��ĳ������ʱ��¼��ǰ�����㣬
//����һ���ҵ�����vʱ�����б������Ӷ���u������v�����·���������ö���������·����


void ShortPath(AdjGraph *G, int u, int v, vector<int> &path)
//��ͼG�дӶ���u������v����̣��棩·��path
{
	ArcNode *p; int w;
	queue<int> qu;			//����һ������qu
	int pre[MAXV];			//��ʾǰ����ϵ
	int visited[MAXV];			//�����Ŷ���ķ��ʱ�־������
	memset(visited, 0, sizeof(visited));	//���ʱ�־�����ʼ��
	qu.push(u);				//����u����
	visited[u] = 1;
	pre[u] = -1;				//��ʼ�����ǰ����Ϊ-1
	while (!qu.empty())			//�Ӳ���ʱѭ��
	{
		w = qu.front(); qu.pop();		//���Ӷ���w
		if (w == v)				//�ҵ�vʱ���·��֮�沢�˳�
		{
			//Findpath(pre, v, path);
			return;
		}
		p = G->adjlist[w].firstarc;		//��w�ĵ�һ���ڽӵ�
		while (p != NULL)   //���ڽڵ�û��ȫ������ʱѭ��
		{
			if (visited[p->adjvex] == 0)
			{
				visited[p->adjvex] = 1;	//����w���ڽӵ�
				qu.push(p->adjvex);		//��w���ڽӵ����
				pre[p->adjvex] = w;		//����p->adjvex�����ǰ��Ϊw
			}
			p = p->nextarc;			//��w����һ���ڽӵ�
		}
	}
}
