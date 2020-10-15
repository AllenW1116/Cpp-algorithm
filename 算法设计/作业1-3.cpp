#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//3. ������������ö������洢�ṹ��ţ����н��ֵ������ͬ�����һ���ݹ��㷨��ֵΪx�Ľ��Ĳ�Σ������Ĳ��Ϊ1����û���ҵ������Ľ��ʱ����0��
typedef struct BNode
{
	int data;
	struct BNode *lchild, *rchild;
} BTNode;		//������������� ,�����ǵݹ��

BTNode *CreatBTprein(int *pre, int *in, int n) { //��֪������������кͽڵ���������Թ���һ��������
	BTNode *b;
	int *p;
	int k;
	if (n <= 0) return NULL;
	b = (BTNode*)malloc(sizeof(BTNode));
	b->data = *pre; //preָ��һ���ַ�����*preָ���һ���ַ�
	for (p = in; p <= in + n; p++) {
		if (*p == *pre)  //*��ָ��������ʾȡֵ
			break;
	}
	k = p - in;           ///k��Ÿ������in�е����λ��
	b->lchild = CreatBTprein(pre + 1, in, k);
	b->rchild = CreatBTprein(pre + k + 1, p + 1, n - k - 1);
	return b;
}

int FindX(BTNode *bt, int x, int level)
{

	if (bt == NULL)//������� ��Ϊ�� ���� δ�ҵ� x
		return 0;
	else
	{
		if (bt->data == x)//�ҵ�x ���ز���
			return level;
		else
		{

			int l1 = FindX(bt->lchild, x, level + 1);//���õݹ� ����Ѱ�������� ע�����Ҫ����
			if (l1 != 0)
				return l1;
			else
			{
				
				int l2 = FindX(bt->rchild, x,level + 1);//���õݹ� ����Ѱ�������� ע�����Ҫ����
				if (l2 != 0)
					return l2;
				else
					return 0;//���û�ҵ� ����0
			}

		}
	}
}

//int main() {
//	int pre[] = { 1,2,4,5,3 };
//	int in[] = { 4,2,5,1,3 };
//	BTNode *B = CreatBTprein(pre, in, 5);  //���������
//
//	cout << FindX(B, 3, 1);  //���2,����ͨ��
//	cout << FindX(B, 4, 1);  //���3,����ͨ��
//	return 0;
//}
