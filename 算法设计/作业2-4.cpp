
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//4. ���������ظ�Ԫ�ص�����������㷨������n��Ԫ��a[] = { a0��a1������an - 1)��
//���п��ܺ����ظ���Ԫ�أ�����ЩԪ�ص����в�ͬ���С�
//��a[] = {1��1��2}���������ǣ�1��1��2)����1��2��1������2��1��1����
//������������������У��ټ����Ž�����ݼ�ʱ���ȱ���������ظ��Ͳ����
//�������ݣ�
int a[] = { 0,1,2,2,3,4 }; //�������Ԫ�ز���
int n = 6;

vector<vector<int> > ps;		//����ݼ�

bool repeat(vector<int> s, vector < vector<int> > p) {
	vector<vector<int> >::iterator it;

}

void Insert(vector<int> s, int i, vector<vector<int> > &ps1)  
{
	vector<int> s1;
	vector<int>::iterator it;
	for (int j = 0; j < i; j++)	//��s(��i-1������)��ÿ��λ�ò���
	{
		s1 = s;
		it = s1.begin() + j;	//�������λ��
		s1.insert(it, a[i]);	//��������i
		if(ps1������s1){
			ps1.push_back(s1);	
		}//��ӵ�ps1��
	}
}

void Perm(int a[])			//a[]����������
{
	vector<vector<int> > ps1;		//��ʱ���������
	vector<vector<int> >::iterator it;//ȫ���е�����
	vector<int> s, s1;
	s.push_back(a[1]);
	ps.push_back(s);			
	for (int i = 2; i < n; i++)		//ѭ�����
	{
		ps1.clear();			//ps1��Ų���i�Ľ��
		for (it = ps.begin(); it != ps.end(); ++it) 
		{
			Insert(*it, i,  ps1);
		}
		ps = ps1;
	}
}