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
//��Դ�����·�����е㶯̬�滮��ζ����
//�㷨���̣�ppt44ҳ
void BellmanFord(Matgraph g,int v)
{
    int i,k,u;
    int dist[MAXV],path[MAXV];
    for (i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v][i];		//��dist(1)[i]��ʼ��
        if (i != v && dist[i] < INF)
            path[i] = v;			//��path(1)[i]��ʼ��
        else
            path[i] = -1;
    }
    for (k = 2; k < g.n; k++)//ѭ�����壺��ڶ��ּ��Ժ��dist
        //��dist1[u]���Ƴ�dist2[u]�� ����distn-1[u]ѭ��n-1��
    {
        for (u = 0; u < g.n; u++)		//ѭ�����壺��һ����ÿ�������dist��path.
        {
            if (u != v)
            {
                for (i = 0; i < g.n; i++)	//ѭ�����壺��ÿһ�������dist path����Ҫ������һ�����ж����dist path
                {
                    if (g.edges[i][u]<INF &&
                        dist[u]>dist[i] + g.edges[i][u])
                    {
                        dist[u] = dist[i] + g.edges[i][u];
                        path[u] = i;
                    }
                }
            }
        }
    }
    //Dispath(g��dist��path��v);	//������·��������
}
