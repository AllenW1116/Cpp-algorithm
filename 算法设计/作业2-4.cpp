
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
int a[] = { 1,2,2,3,4 }; 
int n = 5;

vector<vector<int> > ps;		//����ݼ�

bool repeat(vector<int> s, vector < vector<int> > p) {
	vector<vector<int> >::iterator it;
	bool repeatflag = false;
	for (it = p.begin(); it != p.end(); ++it) {
		if ((*it) == s) repeatflag = true;
	}
	return repeatflag;
}

void Insert(vector<int> s, int i, vector<vector<int> > &ps1)
{
	vector<int> s1;
	vector<int>::iterator it;
	for (int j = 0; j < i + 1; j++)	//��s(��i-1������)��ÿ��λ�ò���
	{
		s1 = s;
		it = s1.begin() + j;	//�������λ��
		s1.insert(it, a[i]);	//��������i
		if (!repeat(s1, ps1)) {    //ps1������s1
			ps1.push_back(s1);
		}//��ӵ�ps1��
	}
}

void Perm(int a[])			//a[]����������
{
	vector<vector<int> > ps1;		//��ʱ���������
	vector<vector<int> >::iterator it;//ȫ���е�����
	vector<int> s, s1;
	s.push_back(a[0]);
	ps.push_back(s);
	for (int i = 1; i < n; i++)		//ѭ�����
	{
		ps1.clear();			//ps1��Ų���i�Ľ��
		for (it = ps.begin(); it != ps.end(); ++it)
		{
			Insert(*it, i, ps1);
		}
		ps = ps1;
	}
}

int main() {
	Perm(a);
	vector<vector<int> >::iterator it;
	vector<int> ::iterator it1;
	for (it = ps.begin(); it != ps.end(); ++it)
	{
		for (it1 = (*it).begin(); it1 != (*it).end(); ++it1) {
			cout << (*it1) << " ";
		}
		cout << endl;
	}
	return 0; //����ͨ����
}