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
//���������㷨���ڡ���̬�滮��������
//����һ����ά����A��ŵ�ǰ����֮������·�����ȣ�������A[i][j]��ʾ��ǰ����i������j�ġ����·�����ȡ���
//ͨ�����Ʋ���һ����������A0��A1������Ak������An - 1��
//����Ak[i][j]��ʾ�Ӷ���i������j��·�����������Ķ����Ų�����k�����·�����ȡ�
void Floyd(Matgraph g)
{
    int A[MAXV][MAXV],path[MAXV][MAXV];
    int i,j,k;
    for (i = 0; i < g.n; i++)  //��ʼ��
        for (j = 0; j < g.n; j++)
        {
            A[i][j] = g.edges[i][j];
            if (i != j && g.edges[i][j] < INF)
                path[i][j] = i;		//����i��j�б�ʱ
            else
                path[i][j] = -1;		//����i��jû�б�ʱ
        }
    for (k = 0; k < g.n; k++) //ѭ�����壺��k�����ƾ���
    {
        for (i = 0; i < g.n; i++)
            for (j = 0; j < g.n; j++)
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];	//�޸����·��
                }
    }
    //Dispath(g,A,path);			//������·��
}
