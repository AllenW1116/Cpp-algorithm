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



//����ֱ����������⣬��1��n�Ĵ��������a�У���������Ϊ���켯��a�������Ӽ���
//�輯��a[0..2] = { 1��2��3 }���������Ӽ���Ӧ�Ķ�����λ����ʮ���������¡�
void inc(int b[], int n)	//��b��ʾ�ġ�����������1��
{
	for (int i = 0; i < n; i++)	//��������b
	{
		if (b[i])		//��Ԫ��1��Ϊ0
			b[i] = 0;
		else			//��Ԫ��0��Ϊ1���˳�forѭ��
		{
			b[i] = 1;
			break;
		}
	}
}
void PSet(int a[], int b[], int n)	//���ݼ�
{
	int i, k;
	int pw = (int)pow(2, n);		//��2^n
	printf("1��%d���ݼ�:\n  ", n);
	for (i = 0; i < pw; i++)			//ִ��2^n��
	{
		printf("{ ");
		for (k = 0; k < n; k++)		//ִ��n��
			if (b[k])
				printf("%d ", a[k]);
		printf("} ");
		inc(b, n);			//b��ʾ�Ķ���������1
	}
	printf("\n");
}

