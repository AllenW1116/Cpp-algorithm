#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
using namespace std;
//��������������Ҫ������ַ���Ϊ{ d1��d2������dn }�����ǳ��ֵ�Ƶ��Ϊ{ w1��w2������wn }��
//Ӧ�ù��������������ŵĲ��ȳ�����0��1���ɵı��뷽����
//
//
//����������Huffman Tree���Ķ��壺�����������n����Ȩֵ��Ҷ�ӽ�㣬�Ӹ���㵽ÿ��Ҷ�ӽ�㶼��һ��·�����ȡ�
//�Ӹ���㵽����Ҷ�ӽ���·����������Ӧ���Ȩֵ�ĳ˻��ĺͳ�Ϊ�ö������Ĵ�Ȩ·�����ȡ�
//��n��Ҷ�ӽ����Թ�������ֶ����������о�����С��Ȩ·�����ȵĶ�������Ϊ����������Ҳ������������
//��������ȨֵС��������Ľ�㣻Ȩֵ��Ŀ������ڵ�
//
//����һ�ù��������ķ������£�
//��1���ɸ�����n��Ȩֵ{ w1��w2������wn }����n��ֻ��һ��Ҷ�ӽ��Ķ��������Ӷ��õ�һ���������ļ���F = { T1��T2������Tn }��
//��2����F��ѡȡ������Ȩֵ��С�ʹ�С�����ö�������Ϊ������������һ���µĶ�������
//����µĶ�����������ȨֵΪ���������������Ȩֵ֮�͡����ϲ����ö�����Ϊһ�ö�������
//��3���ظ����裨2������F��ֻʣ��һ�ö�����ʱ����ö�����������Ҫ�����Ĺ���������

int n;
struct HTreeNode			//���������������
{
	char data;				//�ַ�
	int weight;				//Ȩֵ
	int parent;				//˫�׵�λ��
	int lchild;				//���ӵ�λ��
	int rchild;				//�Һ��ӵ�λ��
};
HTreeNode ht[MAX];			//��Ź�������

map<char, string> htcode;		//��Ź���������

struct NodeType			//���ȶ��н������
{
	int no;				//��Ӧ��������ht�е�λ��
	char data;				//�ַ�
	int  weight;			//Ȩֵ
	bool operator<(const NodeType& s) const
	{					//���ڴ���С���ѣ��ȳ�������ȨֵС��
		return s.weight < weight;
	}
};
//����������n��Ҷ�ӽڵ����n-1����Ҷ�ӽڵ�	��
void CreateHTree()			//�����������
{
	NodeType e, e1, e2;
	priority_queue<NodeType> qu;
	for (int k = 0; k < 2 * n - 1; k++)		//�������н���ָ����
		ht[k].lchild = ht[k].rchild = ht[k].parent = -1;
	for (int i = 0; i < n; i++)		//��n��������qu������С����
	{
		e.no = i; e.data = ht[i].data;
		e.weight = ht[i].weight; qu.push(e);
	}
	for (int j = n; j < 2 * n - 1; j++)		//������������ġ�n-1����Ҷ�ӽ�㡿
	{
		e1 = qu.top();  qu.pop();		//����Ȩֵ��С�Ľ��e1
		e2 = qu.top();  qu.pop();		//����Ȩֵ��С�Ľ��e2
		ht[j].weight = e1.weight + e2.weight; //������������ķ�Ҷ�ӽ��j	
		ht[j].lchild = e1.no;
		ht[j].rchild = e2.no;
		ht[e1.no].parent = j;		//�޸�e1.no��˫��Ϊ���j
		ht[e2.no].parent = j;		//�޸�e2.no��˫��Ϊ���j
		e.no = j;				//������н��e����Ҷ�ӽڵ㲻��Ҫdataֵ��ֻ��Ҫweight�ͱ�ţ�
		e.weight = e1.weight + e2.weight;
		qu.push(e);
	}
}

void CreateHCode()		      //�������������
{
	string code;
	code.reserve(MAX);     //Ԥ��һ���ռ�
	for (int i = 0; i < n; i++)	      //����Ҷ�ӽ��i�Ĺ���������
	{
		code = "";
		int curno = i;
		int f = ht[curno].parent;
		while (f != -1)		      //ѭ���������
		{
			if (ht[f].lchild == curno)  //curnoΪ˫��f������
				code = '0' + code;
			else			      //curnoΪ˫��f���Һ���
				code = '1' + code;
			curno = f; f = ht[curno].parent;
		}
		htcode[ht[i].data] = code;     //�õ�ht[i].data�ַ��Ĺ���������
	}
}
//�����Ǵ�Ҷ�ӽڵ������ڵ��