#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

//3. �������ɸ�������a0��a0 ������an - 1 ������ѡ����������ʹ���ǵĺ�ǡ��Ϊk��Ҫ����ѡ��Ԫ�ظ������ٵĽ⡣
//�˴�����һ���Ƚϱ��ķ��������ݷ�����ݼ����ҳ��ܼ���Ԫ�غ�Ϊk�ļ���װ���µ��ݼ����ٱ����õ����и������ٵġ�
//�������ݣ�
int a[] = { 1,2,3,4,5 };
int length = 5;
int M = 7;
int x[];

vector<vector<int> > ps;		//����ݼ���Ӧ����һ��ȫ�ֱ����������յĽ����
void PSet(int n[])			//��a[]�ݼ�
{
	vector<vector<int> > ps1;		//���ݼ�
	vector<vector<int> >::iterator it;//�ݼ�������
	vector<int> s;					//һ���ռ���
	ps.push_back(s);			//���{}�ռ���Ԫ��
	for (int i = 0; i < length; i++)		//ѭ�����a[]�е�Ԫ��
	{
		ps1 = ps;				//ps1�����һ���õ����ݼ�
		for (it = ps1.begin(); it != ps1.end(); ++it)
			(*it).push_back(a[i]);		//��ps1��ÿ������Ԫ��ĩβ���i
		for (it = ps1.begin(); it != ps1.end(); ++it)
			ps.push_back(*it);		//��ps1��ÿ������Ԫ����ӵ�ps��
	}
}
int sum(vector<int> v);
vector<int> getresult(vector<vector<int> > ps) {
	vector<vector<int> >::iterator it;//�ݼ�������
	vector<int>::iterator it1; //���ϵ�����
	vector<int> minv = ps.back();  //Ҫ����Сֵ������Ӧ���ѳ�ʼֵ��Ϊ���ֵ���Ǳ������һ�����ϳ������
	for (it = ps.begin(); it != ps.end(); ++it) {
		if ((*it).size() < minv.size() && sum(*it) == M) { minv = *it; }  //��Ѱ���������ҳ��ȸ�С�ĵļ���
	}

	return minv;

}
int sum(vector<int> v) {
	int sum = 0;
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
	}
	return sum;
}

int main() {
	PSet(a);
	vector<int> result = getresult(ps);
	for (unsigned int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	return 0; //���{3 4} ͨ����
}

