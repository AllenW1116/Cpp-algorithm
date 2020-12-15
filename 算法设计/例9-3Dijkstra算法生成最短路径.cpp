#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
#include"�ڽӾ���.h"
using namespace std;
#define INF 32767
//�㷨���̣�ppt32ҳ
//��Դ���ص����·���������Դ�㵽ÿһ���������̾��롣

//����һ������dist[0..n - 1]��dist[i]���������Դ��v������i��Ŀǰ���·�����ȣ�
//���ĳ�ֵΪ<v��i>���ϵ�Ȩֵ��������v������iû�бߣ���Ȩֵ��Ϊ�ޡ�
//�Ժ�ÿ����һ���µ��м��ʱ��dist[i]��ֵ���ܱ��޸Ķ���С��
//����һ������path[0..n - 1]���ڱ������·����
//path[j]���浱ǰ���·���е�ǰһ������ı�ţ����ĳ�ֵΪԴ��v�ı�ţ�����v������j�б�ʱ���� - 1������v������i�ޱ�ʱ����
void Dijkstra(Matgraph g, int v)		//Dijkstra�㷨
{
    int dist[MAXV], path[MAXV];
    int S[MAXV];  //S[i]=1:i����S�С�Ϊ0��V�С�
    int mindis, i, j, u;
    for (i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v][i];		//�����ʼ��
        S[i] = 0;				//S[]�ÿ�
        if (g.edges[v][i] < INF)		//·����ʼ��
            path[i] = v;	//����v������i�б�ʱ���ö���i��ǰһ������Ϊv
        else
            path[i] = -1;	//����v������iû��ʱ���ö���i��ǰһ������Ϊ-1
    }
    S[v] = 1; path[v] = 0;			//Դ����v����s��
    for (i = 0; i < g.n; i++)	//ѭ��ֱ�����ж�������·�������
    {
        mindis = INF;		//mindis����С·������
        for (j = 0; j < g.n; j++)	//ѡȡ����s���Ҿ�����С����Ķ���u
            if (S[j] == 0 && dist[j] < mindis)
            {
                u = j;
                mindis = dist[j];
            }
        S[u] = 1;				//����u����s��
        for (j = 0; j < g.n; j++)		//�޸Ĳ���S�еĶ���ľ���
            if (S[j] == 0)
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]) //��һ��������ʵ���Բ���
                {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
    }
    //Dispath(g,dist,path,S,v);	������·��
}
void Dispath(Matgraph g, int *dist, int *path,int* S, int v) {
    int cur = 0;
    vector<int> apath;
    vector<int>::reverse_iterator it;  //���巴�������
    for (int i = 0; i < g.n; i++) {//���Դ�㵽ÿһ�������·��
        cout << "Դ�㵽����" << i << "��·����"<<endl;
        cur = i;
        while (path[cur] != 0 || path[cur] != -1) {
            apath.push_back(cur);
            cur = path[cur];
        }
        //path[cur]==0,cur=v
        if (cur == v) {//has path
            apath.push_back(v);
            for (it = apath.rbegin(); it != apath.rend(); ++it) {//�������
            cout << *it << " ";
             }
        }
        //path[cur]==-1,cur=nonsense
        cout << endl;
    }
}



