#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//5. ���õݹ���ݷ����һ���㷨��1��n��n��������ȡ��m��Ԫ�ص����У�
//Ҫ��ÿ��Ԫ�����ֻ��ȡһ�Ρ�
//���磬n = 3��m = 2���������ǣ�1��2������1��3������2��1������2��3������3��1������3��2����
//���й���=���ҵ�m��Ԫ�ص���ϣ��ٽ�ÿ����Ϸֱ����ȫ����
//������ʹ��������������п��ܵ���ϣ����򣩣��ٽ�ÿ�������ȫ���С�
//�������ݣ�n = 3��m = 2���������ǣ�1��2������1��3������2��1������2��3������3��1������3��2����



int n = 3;
int m = 2;
int a[50]; //���һ�����
vector<vector<int> > psc;		//������

vector<int> getv(int A[]) {  //����תΪvector
	
	vector<int> v(A, A + m);
	return v;
}

void comb(int n, int m)	//��1..n��m�����������
{
	if (m == 0)			//kΪ0ʱ������ϴ���ps
		psc.push_back(  getv(a) );
	else
	{
		for (int i = m; i <= n; i++)
		{
			a[m - 1] = i;		//a[k-1]λ��ȡk��n������
			comb(i - 1, m - 1);
		}
	}
}




vector<vector<int> > psv;   //�������
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

void Perm(vector<int > a)			//a[m]����������
{
	vector<vector<int> > ps1;		//��ʱ���������
	vector<vector<int> >::iterator it;//ȫ���е�����
	vector<int> s, s1;
	s.push_back(a[0]);
	psv.push_back(s);
	for (int i = 1; i < a.size(); i++)		//ѭ�����
	{
		ps1.clear();			//ps1��Ų���i�Ľ��
		for (it = psv.begin(); it != psv.end(); ++it)
		{
			Insert(*it, i, ps1);
		}
		psv = ps1;
	}
} 


int main() {
	comb(n,m); //����ϴ���psc��
	vector<vector<int> >::iterator it;
	vector<vector<int> >::iterator itv;
	vector<int>::iterator it1;
	for (it = psc.begin(); it != psc.end(); ++it) {
		psv.clear();
		//�����ϵ�ȫ����
		Perm(*it);

		//����ô�psv
		for (itv = psv.begin(); itv != psv.end(); ++itv) {
			for (it1 = (*itv).begin(); it1 != (*itv).end(); ++it1) {
				cout << *it1 << " ";
			}
			cout << endl;
		}

	}
	return 0;
}



