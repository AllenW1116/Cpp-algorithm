#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//֮ǰ������ѭ���ķ�ʽ������ݼ����⡣��ʹ�õݹ飺
//�����⣺f(i��n)�������i��n�������������n - i + 1���������������ݼ�ps��
//С���⣺f(i + 1��n)�������i + 1��n���������������n - i���������������ݼ�ps��
//f(1��n)��������1��n���������϶�Ӧ���ݼ�ps��
//������һ�ε����Ĳ�������ó������������ݹ�



vector<vector<int> > ps;			//����ݼ�

void Inserti(int i)
//���ݼ�ps��ÿ������Ԫ�����i�����뵽ps��
{
	vector<vector<int> > ps1;			//���ݼ�
	vector<vector<int> >::iterator it;	//�ݼ�������
	ps1 = ps;					//ps1���ԭ�����ݼ�
	for (it = ps1.begin(); it != ps1.end(); ++it)
		(*it).push_back(i);	//��ps1��ÿ������Ԫ��ĩβ���i
	for (it = ps1.begin(); it != ps1.end(); ++it)
		ps.push_back(*it);	//��ps1��ÿ������Ԫ����ӵ�ps��
}

void PSet(int i, int n)   //��1��n���ݼ�ps
{
	if (i <= n)
	{
		Inserti(i);	//��i���뵽�����Ӽ��в������Ӽ�
		PSet(i + 1, n);	//�ݹ����
	}
}


