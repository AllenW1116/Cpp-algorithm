#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//����������������n����ͬ������������w = ��w1��w2������wn����һ��������W��
//Ҫ���ҳ�w���Ӽ�s��ʹ���Ӽ�������Ԫ�صĺ�ΪW��
//���磬��n = 4ʱ��w = ��11��13��24��7����W = 31��������Ҫ����Ӽ�Ϊ��11��13��7���ͣ�24��7����
int x[];//������
int n=4;
int W = 31;
int w[] = { 11,13,24,7 };
void dfs(int i, int tw, int rw, int x[]) //����Ӽ���
{
	if (i > n)				//�ҵ�һ��Ҷ�ӽ��
	{
		if (tw == W)			//�ҵ�һ�����������Ľ�,�����
			dispasolution(x);
	}
	else					//��δ������������
	{
		if (tw + w[i] <= W)			//���ӽ���֦
		{
			x[i] = 1;			//ѡȡ��i������
			dfs(i + 1, tw + w[i], rw - w[i], x);
		}
		if (tw + rw - w[i] >= W)		//�Һ��ӽ���֦
		{
			x[i] = 0;			//��ѡȡ��i������,����
			dfs(i + 1, tw, rw - w[i], x);
		}
	}
}


//�ж��Ӽ��������Ƿ���ڽ�
//���Ҫ�ж������Ƿ���ڽ⣨һ�����߶���������Խ���⺯����Ϊbool���ͣ�
//���ҵ��κ�һ����ʱ����true�����򷵻�false����Ҫע����ǵ�����û�н�ʱ��Ҫ�������н�ռ䡣

bool dfs(int i, int tw, int rw)	  		//����Ӽ���
{
	if (i > n)					//�ҵ�һ��Ҷ�ӽ��
	{
		if (tw == W)				//�ҵ�һ�����������Ľ�
			return true;
	}
	else						//��δ����������Ʒ
	{
		if (tw + w[i] <= W)				//���ӽ���֦
			return dfs(i + 1, tw + w[i], rw - w[i]);	//ѡȡ��i������
		if (tw + rw - w[i] >= W)			//�Һ��ӽ���֦
			return dfs(i + 1, tw, rw - w[i]);		//��ѡȡ��i������,����
	}
	return false;
}

bool solve()				//�ж��Ӽ��������Ƿ���ڽ�
{
	int rw = 0;
	for (int j = 1; j <= n; j++)		//������������rw
		rw += w[j];
	return dfs(1, 0, rw);		//i��1��ʼ
}



