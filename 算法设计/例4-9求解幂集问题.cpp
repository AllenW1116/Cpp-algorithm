#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//���������������ڸ�����������n��n��1������1��n���ɵļ��ϵ������Ӽ����ݼ�����
//
//�����������������1��n���ݼ������̼�ppt45ҳ��
//�ʼһ���ռ��ϣ�
//ÿ�μ�һ��Ԫ�ؽ�ȥ�������ȫ���ݼ���
//�ټ�һ����Ԫ�أ������ݼ�����
//��ʵ���㷨ʱ����һ��vector<int>������ʾһ������Ԫ�أ���vector<vector<int> >��������ݼ��������ϵļ��ϣ���


vector<vector<int> > ps;		//����ݼ���Ӧ����һ��ȫ�ֱ����������յĽ����
void PSet(int n)			//��1��n���ݼ�ps
{
	vector<vector<int> > ps1;		//���ݼ�
	vector<vector<int> >::iterator it;//�ݼ�������
	vector<int> s;					//һ���ռ���
	ps.push_back(s);			//���{}�ռ���Ԫ��
	for (int i = 1; i <= n; i++)		//ѭ�����1��n
	{
		ps1 = ps;				//ps1�����һ���õ����ݼ�
		for (it = ps1.begin(); it != ps1.end(); ++it)
			(*it).push_back(i);		//��ps1��ÿ������Ԫ��ĩβ���i
		for (it = ps1.begin(); it != ps1.end(); ++it)
			ps.push_back(*it);		//��ps1��ÿ������Ԫ����ӵ�ps��
	}
}


