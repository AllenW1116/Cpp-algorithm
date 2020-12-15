//4.����һ�ַ������޻���Ȩ��ͨͼ������Ȩֵ�Ǹ����дӶ���s������t��һ�����·����
//ʹ�ñ����������㷨������Ȩֵ��Ϊ���������·������������·��
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<vector>
#define MAXV 10
#define INF 500
using namespace std;
typedef struct {
    int edges[50][50];  //�ڽӾ�������
    int n, e; //n������e����
    //Vertextype vexs[50]; //һά�������ڴ�Ŷ���
}MGraph; //һ���ڽӾ���
void Dispath(MGraph g, int* dist, int* path, int v, int t);
void BellmanFord(MGraph g, int v, int t) //dist[t]��Ϊ��
{
    int i, k, u;
    int dist[MAXV], path[MAXV];
    for (i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v][i];		//��dist(1)[i]��ʼ��
        if (i != v && dist[i] < INF)
            path[i] = v;			//��path(1)[i]��ʼ��
        else
            path[i] = -1;
    }
    for (k = 2; k < g.n; k++)
        //��dist1[u]���Ƴ�dist2[u]�� ����distn-1[u]ѭ��n-1��
    {
        for (u = 0; u < g.n; u++)		//�޸�ÿ�������dist��path
        {
            if (u != v)
            {
                for (i = 0; i < g.n; i++)	//��������ÿ������
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
    Dispath(g, dist, path, v, t);	//������·��������
}
void Dispath(MGraph g, int* dist, int* path, int v, int t) {
    int n = g.n;//�������
    int end = t;

    vector<int> apath;
    apath.push_back(t);
    //�������path
    while (path[t] != 0) {

        apath.push_back(path[t]);
        t = path[t];
    }
    if (path[apath.back()] == v) {  //ԭ����Ե���õ�
        apath.push_back(v);//��Դ�����
        cout << "�·��Ϊ��";
        vector<int>::reverse_iterator it;		//���巴�������
        for (it = apath.rbegin(); it != apath.rend(); ++it) {//�������
            cout << *it << " ";
        }
        cout << "����Ϊ" << -dist[end];
    }
}
int main() {
    MGraph M = { { {0,3,4,INF,17},
        {INF,0,8,5,11},
        {INF,INF,0,INF,10},
        {INF,INF,INF,0,5},
        {INF,INF,INF,INF,0} },5,8 };
    //�ڽӾ����ø�
    for (int i = 0; i < M.n; i++) {
        for (int j = 0; j < M.n; j++) {
            if (M.edges[i][j] != INF) { M.edges[i][j] = -M.edges[i][j]; }
        }
    }
    BellmanFord(M, 0, 4);
    return 0;
}
