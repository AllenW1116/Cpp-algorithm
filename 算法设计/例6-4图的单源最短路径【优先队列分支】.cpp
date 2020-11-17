#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
using namespace std;
struct NodeType		//���н������
{
	int vno;			//������
	int length;			//ԭ�㵽�õ��·������

	bool operator<(const NodeType& node) const
	{
		return length > node.length;	//lengthԽСԽ���ȳ���
	}

};
void bfs(int v)			//����㷨
{
    NodeType e, e1;
    priority_queue<NodeType> pqu;	//�������ȶ���
    e.vno = v;				//����Դ����e
    e.length = 0;
    pqu.push(e);			//Դ����e����
    dist[v] = 0;
    while (!pqu.empty())		//���в���ѭ��
    {
        e = pqu.top(); pqu.pop();		//�����н��e
        for (int j = 0; j < n; j++)
        {
            if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j])
            {  //��֦��e.vno������j�б߲���·�����ȸ���
                dist[j] = e.length + a[e.vno][j];
                prev[j] = e.vno;
                e1.vno = j;			//�������ڶ���j�Ľ��e1
                e1.length = dist[j];
                pqu.push(e1);		//���e1����
            }
        }
    }
}




