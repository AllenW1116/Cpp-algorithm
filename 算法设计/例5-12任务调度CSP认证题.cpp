#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>
#include <stdio.h>
#define INF 0x3f3f3f3f		//���������
#define MAXN 42			//������ҵ��
#define max(x,y) ((x)>(y)?(x):(y))
#define max3(x,y,z) max(max(x,y),z)
#define min(x,y) ((x)<(y)?(x):(y))
#define min3(x,y,z) min(min(x,y),z)
using namespace std;
//�������ƣ��������
//ʱ�����ƣ�1.0s
//�ڴ����ƣ�256.0MB
//���������������ɸ�������Ҫ��һ̨���������С�����֮��û��������ϵ����� ���Ա���������˳��ִ�С�
//�û���������CPU��һ��GPU������ÿ�����������Ϊ�����䲻ͬ��Ӳ����Դ��

//1. �ڵ���CPU�����С�
//2. ������CPU��ͬʱ���С�
//3. �ڵ���CPU��GPU��ͬʱ���С�
//4. ������CPU��GPU��ͬʱ���С�

//һ������ʼִ���Ժ󣬽����ռ�����õ�������Ӳ����Դ�������жϣ�ֱ��ִ�н���Ϊֹ��
//��i�������õ���CPU������CPU������CPU��GPU������CPU��GPU���������ĵ�ʱ��ֱ�Ϊai��bi��ci �� di��
//������Ҫ������������Ҫ������ʱ����԰����и�����������ɡ�

//�����ʽ������ĵ�һ��ֻ��һ�������� n(1 �� n �� 40)�� ���ܹ���Ҫִ�е��� �������
//�������� n ��ÿ�����ĸ�������ai��bi��ci��di(ai��bi��ci��di ��������10)���Կո������
//�����ʽ�����ֻ��һ������������ɸ����������������������ʱ�䡣
//�������룺
//3
//4 4 2 2
//7 4 7 4
//3 3 3 3
//�������
//7
//����˵�����кܶ��ֵ��ȷ���������7��ʱ�䵥λ����ɸ����������������������е�һ�ַ�����
//ͬʱ���е�һ�����񣨵�CPU����GPU���͵��������񣨵�CPU�������Ƿֱ���ʱ��2��ʱ��3��ɡ���ʱ��3��ʼ˫CPU��������2����ʱ��7��ɡ�


//�����ʾ
int n;					//������
struct node
{
	int a, b, c, d;
} A[MAXN];  // acbd��Ӧ����ִ�з���

int x[MAXN];
int bestf = INF;				//��ŵ���ʱ��
void swap(int& x, int& y)		//����x��y
{
	int tmp = x;
	x = y; y = tmp;
}

// cpu1 cpu2 gpuָ����Ӳ���ϵ�����ʱ�䣬��ʼʱӦ�ö�Ϊ0
void dfs(int i, int cpu1, int cpu2, int gpu)	//�ӵ�i�㿪ʼ����
{
    int m, k, tcpu1, tcpu2, tgpu;
    if (i == n)				//����Ҷ���,����һ�ֵ��ȷ���
    {
        m = max3(cpu1, cpu2, gpu);
        if (m < bestf)			//�ҵ����Ž�
            bestf = m;
    }
    else
    {
        for (int j = i; j < n; j++)		//û�е���Ҷ���
        {
            swap(x[i], x[j]);		//���ǵ�i��ѡ������x[j]	
            for (k = 1; k <= 5; k++)		//�������з�ʽ
            {
                tcpu1 = cpu1; tcpu2 = cpu2; tgpu = gpu;
                if (k == 1)			//����1������CPU������-CPU1
                    cpu1 += A[x[i]].a;
                else if (k == 2)		//����1������CPU������-CPU2
                    cpu2 += A[x[i]].a;
                else if (k == 3)	//����3����CPU1��GPU��ͬʱ����
                {
                    m = max(cpu1, gpu) + A[x[i]].c;
                    cpu1 = gpu = m;
                }
                else if (k == 4)	//����3����CPU2��GPU��ͬʱ����
                {
                    m = max(cpu2, gpu) + A[x[i]].c;
                    cpu2 = gpu = m;
                }
                else if (k == 5)	//����4��������CPU+GPU��ͬʱ����
                {
                    m = max3(cpu1, cpu2, gpu) + A[x[i]].d;
                    cpu1 = cpu2 = gpu = m;
                }
                m = max3(cpu1, cpu2, gpu);
                if (m < bestf)	  	//��֦:������չ��ǰ��ʱ��С��bestf�Ľ��
                    dfs(i + 1, cpu1, cpu2, gpu);
                cpu1 = tcpu1; cpu2 = tcpu2; gpu = tgpu;
            }
            swap(x[i], x[j]);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int k = 0; k < n; k++)  //���ó�ʼ����Ϊ��ҵ0,1,��,n-1��˳��
        x[k] = k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &A[i].a, &A[i].b, &A[i].c, &A[i].d);
        if (A[i].b < A[i].d) A[i].d = A[i].b;
    }
    dfs(0, 0, 0, 0);
    printf("%d\n", bestf);
    return 0;
}
