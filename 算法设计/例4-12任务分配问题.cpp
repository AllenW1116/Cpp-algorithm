#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//��������������n��n��1����������Ҫ�����n����ִ�У�ÿ������ֻ�ܷ����һ���ˣ�ÿ����ֻ��ִ��һ������
//��i����ִ�е�j������ĳɱ���c[i][j]��1��i��j��n��������ܳɱ���С�ķ��䷽����
//��������⡿��νһ�ַ��䷽�������ɵ�i����ִ�е�j�������ã�a1��a2������an����ʾ��
//����1����ִ�е�a1�����񣬵�2����ִ�е�a2�������Դ����ơ�ȫ���ķ��䷽��ǡ����1��n��ȫ���С�
//�������������ٷ�������еķ��䷽��ps��ȫ���У����ټ����ÿ�ַ����ĳɱ����Ƚ������С�ɱ��ķ����������ŷ�����




//������4-11�е�������ȫ�����㷨��
vector<vector<int> > ps;		//����ݼ�

void Insert(vector<int> s, int i, vector<vector<int> > &ps1)
//��ÿ������Ԫ���м����i�õ�ps1
{
	vector<int> s1;
	vector<int>::iterator it;
	for (int j = 0; j < i; j++)	//��s(��i-1������)��ÿ��λ�ò���i
	{
		s1 = s;
		it = s1.begin() + j;	//�������λ��
		s1.insert(it, i);	//��������i
		ps1.push_back(s1);	//��ӵ�ps1��
	}
}

void Perm(int n)			//��1��n������ȫ����
{
	vector<vector<int> > ps1;		//��ʱ���������
	vector<vector<int> >::iterator it;//ȫ���е�����
	vector<int> s, s1;
	s.push_back(1);
	ps.push_back(s);			//���{1}����Ԫ��
	for (int i = 2; i <= n; i++)		//ѭ�����1��n
	{
		ps1.clear();			//ps1��Ų���i�Ľ��
		for (it = ps.begin(); it != ps.end(); ++it)
			Insert(*it, i, ps1);		//��ÿ������Ԫ���м����i�õ�ps1
		ps = ps1;
	}
}

//�ȵ��г���Ա������������
int c[][4] = { {9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4} };


void Allocate(int n, int &mini, int &minc)  //����nӦ=4
//�����������������ŷ���
{
	Perm(n);				//���ȫ����ps
	for (int i = 0; i < ps.size(); i++)	//��ÿ�������ĳɱ�
	{
		int cost = 0;
		for (int j = 0; j < ps[i].size(); j++)
			cost += c[j][ps[i][j] - 1];   //c����Ա������������
		if (cost < minc)			//�Ƚ�����С�ɱ��ķ���
		{
			minc = cost;
			mini = i;
		}
	}
}


