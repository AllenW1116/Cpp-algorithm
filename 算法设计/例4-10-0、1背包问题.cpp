#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//��������������n�������ֱ�Ϊ{ w1��w2������wn }����Ʒ�����ǵļ�ֵ�ֱ�Ϊ{ v1��v2������vn }��
//����һ������ΪW�ı�������ƴ���Щ��Ʒ��ѡȡһ������Ʒ����ñ����ķ�����
//ÿ����ƷҪôѡ��Ҫô��ѡ�У�Ҫ��ѡ�е���Ʒ�����ܹ��ŵ������У����Ҿ������ļ�ֵ��
//
//��������⡿����n����Ʒ������ΪW�ı������⣬����ǰ�����ݼ��ķ���������е���Ʒ��ϡ�
//����ÿһ����ϣ�������������sumw���ܼ�ֵsumv����sumwС�ڵ���Wʱ���������һ�ֽ⣬
//��ͨ���ȽϽ���ѷ���������maxsumw��maxsumv�У����������еĽ����ѽ⡣
//����1234�ĸ���Ʒ��{12}{23}{123}�ֱ����������������
//���е�ѡ�񷽰�����Ȼ����{1 2 3 4}���ݼ����ݼ��е�ÿ��������һ�ֽ��������Ҳ��Ӧһ��sumw��sumv

vector<vector<int> > ps;		//����ݼ�
void PSet(int n)			//��1��n���ݼ�ps
{
	vector<vector<int> > ps1;		//���ݼ�
	vector<vector<int> >::iterator it;//�ݼ�������
	vector<int> s;
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

void Knap(int w[], int v[], int W)	//�����еķ�������ѷ�������Ʒ�������� ��Ʒ��ֵ���� ��������
{
	int count = 0;			//�������
	int sumw, sumv;			//��ǰ���������������ܼ�ֵ
	int maxi, maxsumw = 0, maxsumv = 0;	//��ѷ����ı�š����������ܼ�ֵ
	vector<vector<int> >::iterator it;	//�ݼ�������
	vector<int>::iterator sit;			//�ݼ���ļ���Ԫ�ص�����
	printf("  ���\tѡ����Ʒ\t������\t�ܼ�ֵ\t�ܷ�װ��\n");// \t���Ʊ�
	for (it = ps.begin(); it != ps.end(); ++it)	//ɨ��ps��ÿһ������Ԫ��
	{
		printf("  %d\t", count + 1);
		sumw = sumv = 0;
		printf("{");
		for (sit = (*it).begin(); sit != (*it).end(); ++sit)
		{
			printf("%d ", *sit);
			sumw += w[*sit - 1];			//w�����±��0��ʼ����ps�е��±��1��ʼ
			sumv += v[*sit - 1];			//v�����±��0��ʼ����ps�е��±��1��ʼ
		}
		printf("}\t\t%d\t%d  ", sumw, sumv);
		if (sumw <= W)
		{
			printf("��\n");
			if (sumv > maxsumv)			//�Ƚ������ŷ���
			{
				maxsumw = sumw;
				maxsumv = sumv;
				maxi = count;
			}
		}
		else printf("��\n");
		count++;					//�����������1
	}
	printf("��ѷ���Ϊ: ");
	printf("ѡ����Ʒ");
	printf("{ ");
	for (sit = ps[maxi].begin(); sit != ps[maxi].end(); ++sit)
		printf("%d ", *sit);
	printf("},");
	printf("������:%d,�ܼ�ֵ:%d\n", maxsumw, maxsumv);
}

	





