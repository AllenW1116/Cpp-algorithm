#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<stdlib.h>
#include"�ڽӾ���.h"
using namespace std;
#define INF 32767;

//��³˹������Kruskal���㷨��һ�ְ�Ȩֵ�ĵ�������ѡ����ʵı���������С�������ķ�����
//�㷨����� ppt15ҳ
//ʵ�ֿ�³˹�����㷨�Ĺؼ�������ж�ѡȡ�ı��Ƿ��������������еı��γɻ�·�������ͨ�������鼯�����������
//�����鼯����ppt18ҳ

//���鼯ģ�ͣ�
//���Ͷ��壺
typedef struct node
{
    int data;		//����Ӧ����
    int rank;		//����Ӧ�ȣ������������ڵ����������ֲ���ȫ��
    int parent;	    //����Ӧ˫���±�
} UFSTree;
//�������㣺
void MAKE_SET(UFSTree t[], int n)	//��ʼ�����鼯��
{
    for (int i = 0; i < n; i++)			//������Ϊ0��(n-1)
    {
        t[i].rank = 0;				//�ȳ�ʼ��Ϊ0
        t[i].parent = i;				//˫�׳�ʼ��ָ������
    }
}
int FIND_SET(UFSTree t[], int x)	//��x���������в��Ҽ��ϵı��
{
    if (x != t[x].parent)			//��˫�ײ������ѣ��ڵ���t[]�е������±���Ǹõ�ı�ţ���
        return(FIND_SET(t, t[x].parent));	//�ݹ���˫������x
    else
        return(x);				//��˫��������,����x
}
void UNION(UFSTree t[], int x, int y)	//��x��y���ڵ������ϲ�
{
    x = FIND_SET(t, x);
    y = FIND_SET(t, y);
    if (t[x].rank > t[y].rank)		//x�����ȴ���y������
        t[y].parent = x;			//��x�����Ϊy��˫�׽��
    else					//y�����ȴ��ڵ���x������
    {
        t[x].parent = y;			//��y�����Ϊx��˫�׽��
        if (t[x].rank == t[y].rank)	//x��y��������ͬ
            t[y].rank++;			//y��������1
    }
}


//��������������Kruskal�㷨���������ʵ�ֵ�
//���Edge
typedef struct
{
    int u;		//�ߵ���ʼ����
    int v;		//�ߵ���ֹ����
    int w;		//�ߵ�Ȩֵ
} Edge;
//��һ������E[]���ͼG�е����бߣ�Ҫ�������ǡ���Ȩֵ����С�����˳�����С��ģ�
//Ϊ���ȴ�ͼG�ġ��ڽӾ����л�ȡ���б߼�E���ٲ��á������򷨡��Ա߼�E��Ȩֵ��������
void Kruskal(Matgraph g)	//Kruskal�㷨
{
    int i, j, k, u1, v1, sn1, sn2;
    UFSTree t[MaxSize];
    Edge E[MaxSize];
    k = 0;
    for (i = 0; i < g.n; i++)	//��g�����ǲ��ֲ����ı߼�E��û�����򣬾��Ǵ��ȥ�ˣ�
        for (j = 0; j < i; j++)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
            {
                E[k].u = i; E[k].v = j; E[k].w = g.edges[i][j];
                k++;
            }//ѭ��������k==�ڵ����

    sort(E, E + k);		//����STL��sort()�㷨��w��������
    MAKE_SET(t, g.n);		//��ʼ�����鼯��t
    k = 1;				//k��ʾ��ǰ�����������ĵڼ�����,��ֵΪ1
    j = 0;				//E�бߵ��±�,��ֵΪ0
    while (k < g.n)		//���ɵı���С��nʱѭ��
    {
        u1 = E[j].u;
        v1 = E[j].v;		//ȡһ���ߵ�ͷβ������u1��v2
        sn1 = FIND_SET(t, u1);
        sn2 = FIND_SET(t, v1);	//�ֱ�õ��������������ļ��ϱ��
        if (sn1 != sn2)
            //��Ӹñ߲��ṹ�ɻ�·,������Ϊ��С��������һ�������
        {
            printf("  (%d,%d):%d\n", u1, v1, E[j].w);
            k++;			//���ɱ�����1
            UNION(t, u1, v1);	//��u1��v1��������ϲ�
        }
        j++;			//ɨ����һ����
    }
}

