#include<iostream>
using namespace std;
//�������ĵݹ��㷨���
//��������һ�ֵ��͵ĵݹ����ݽṹ����һ�ö��������ö�����b�洢ʱ��
//�������bΪ������������������ĳ����Ϊ�������⡱��
//�����������������ͬ����Ϊ��С���⡱��
//�ɴ�С����֮��Ľ��ϵ�õ��ݹ��塣
//�ٿ������������ͨ���Ƕ�����Ϊ�ջ���ֻ��һ�����ʱ����ʱ��������⣬�Ӷ��õ��ݹ���ڡ�
//
//
//����2.8�����ں�n��n > 0�������Ķ����������н��ֵΪint���ͣ����һ���㷨������������a����������b������Ӧ�Ķ������洢�ṹ��
typedef int ElemType;
typedef struct BNode
{
	int data;
	struct BNode *lchild, *rchild;
} BTNode;		//������������� ,�����ǵݹ��
BTNode *CreateBTree(ElemType a[], ElemType b[], int n)
//����������a[0..n-1]����������b[0..n-1]�����������洢�ṹbt
{
	int k;
	if (n <= 0) return NULL;
	ElemType root = a[0];				//�����ֵ
	BTNode *bt = (BTNode *)malloc(sizeof(BTNode));
	bt->data = root;
	for (k = 0; k < n; k++)			//��b�в���b[k]=root�ĸ����
		if (b[k] == root)
			break;
	bt->lchild = CreateBTree(a + 1, b, k);			//�ݹ鴴��������
	bt->rchild = CreateBTree(a + k + 1, b + k + 1, n - k - 1);	//�ݹ鴴��������
	return bt;
}
