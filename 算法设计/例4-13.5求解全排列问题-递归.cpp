#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
vector<vector<int> > ps;		//���ȫ����
void Insert(vector<int> s, int i, vector<vector<int> >& ps1)
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