#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//2. ���һ���㷨����װ�����⣬����һ����װ��Ҫװ��һ��������ΪW���ִ���
//���б��Ϊi��0��i��n - 1���ļ�װ�������Ϊwi����Ҫ��n����װ����ѡ������װ���ִ���
//ʹ���ǵ�����֮������ΪW������ҵ���һ�ֽⷵ��true�����򷵻�false��

//����һ���Ӽ���͵�����
//���ҵ��κ�һ����ʱ����true�����򷵻�false����Ҫע����ǵ�����û�н�ʱ��Ҫ�������н�ռ䡣
//�������ݣ�
int n = 5;
int W = 40;
int w[] = { 11,13,24,7,9 };

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

int main() {
	int i = 0;
	int tw = 0;
	int rw = 64;
	cout << dfs(i, tw, rw); //���1 ͨ��
	return 0;
}