#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include"�ڽӱ�.h"
#include"�ڽӾ���.h"
using namespace std;


//���ȿ�һ��ͼ��DFS���
//��1����ͼ��ĳ����ʼ����v���������ȷ��ʳ�ʼ����v��
//��2��Ȼ��ѡ��һ���붥��v������û�����ʹ��Ķ���wΪ��ʼ���㣬�ٴ�w���������������������
//��3���ظ�ֱ��ͼ���뵱ǰ����v�ڽӵ����ж��㶼�����ʹ�Ϊֹ����Ȼ��������������Ǹ��ݹ���̡�

int visited[] = { 0 };

//���ڽӾ���Ϊ�洢�ṹ��������������㷨
void DFS_M(Matgraph g, int v)	//�ڽӾ����DFS�㷨
{
	int w;
	printf("%3d", v);		//��������ʶ���ı��
	visited[v] = 1;		//���ѷ��ʱ��
	for (w = 0; w < g.n; w++)	//�Ҷ���v���������ڵ�
		if (g.edges[v][w] != 0 && g.edges[v][w] != 32767
			&& visited[w] == 0)
			DFS_M(g, w);		//�Ҷ���v��δ���ʹ������ڵ�w
}

//���ڽӱ�Ϊ�洢�ṹ��������������㷨��
void DFS_G( AdjGraph *G, int v)	//�ڽӱ��DFS�㷨
{
	ArcNode *p;
	printf("%3d", v);		//��������ʶ���ı��
	visited[v] = 1;		//���ѷ��ʱ��
	p = G->adjlist[v].firstarc;	//pָ�򶥵�v�ĵ�һ���ڽӵ�
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0) //��p->adjvex����δ����,�ݹ������
			DFS_G(G, p->adjvex);
		p = p->nextarc;		//pָ�򶥵�v����һ���ڽӵ�
	}
}







//����4.6������ͼG�����ڽӱ�洢�����һ���㷨�ж�ͼG�дӶ���u��v�Ƿ���ڼ�·����

bool ExistPath ( AdjGraph *G,int u, int v)
//�ж�G�дӶ���u��v�Ƿ���ڼ�·��
{
	int w; ArcNode *p;
	visited[u] = 1;		//���ѷ��ʱ��
	if (u == v)			//�ҵ���һ��·��������true
		return true;
	p = G->adjlist[u].firstarc;	//pָ�򶥵�u�ĵ�һ�����ڵ�
	while (p != NULL)
	{
		w = p->adjvex;		//wΪ����u�����ڶ���
		if (visited[w] == 0)	//��w����δ����,�ݹ������
		{
			bool flag = ExistPath(G, w, v);
			if (flag) return true;
		}
		p = p->nextarc;		//pָ�򶥵�u����һ�����ڵ�
	}
	return false;		//û���ҵ�v������false
}


//����4.7������ͼG�����ڽӱ�洢�����һ���㷨���ͼG�дӶ���u��v��һ����·��������ͼG�дӶ���u��v������һ����·������
//�⣺����������ȱ����ķ�����f(G��u��v��apath��path)����ͼG�дӶ���u��v��һ����·��path��
//ͨ������u��ͼG����������u = vʱ˵���ҵ�һ����u��v�ļ�·������apath���Ƶ�path�в����ء��������������ȱ�����

void FindaPath (AdjGraph *G, int u, int v, vector<int> apath,
	vector<int> &path)
{
	int w;
	ArcNode *p;
	visited[u] = 1;
	apath.push_back(u);		//����u���뵽apath·����
	if (u == v)				//�ҵ�һ��·��
	{
		path = apath;			//��apath���Ƶ�path
		return;				//����true
	}
	p = G->adjlist[u].firstarc;		//pָ�򶥵�u�ĵ�һ�����ڵ�
	while (p != NULL)
	{
		w = p->adjvex;			//���ڵ�ı��Ϊw
		if (visited[w] == 0)
			FindaPath(G, w, v, apath, path);
		p = p->nextarc;			//pָ�򶥵�u����һ�����ڵ�
	}
}

