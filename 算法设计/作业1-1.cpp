#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//1. ������������ö������洢�ṹ��ţ����ֵΪint���ͣ����һ���ݹ��㷨�������bt������Ҷ�ӽ��ֵ֮�͡�
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


void BTSum(BTNode *bt,int &sum) {
	

	if (bt->lchild == NULL && bt->rchild == NULL) 
		sum+=bt->data;
	else 
		{ BTSum(bt->lchild, sum); BTSum(bt->rchild, sum); }
}
//
//
//int main1() {
//	int pre[] = { 1,2,4,5,3 };
//	int in[] = { 4,2,5,1,3 };
//	BTNode *B = CreatBTprein(pre,in,5);  //���������
//	int S = 0;
//	BTSum(B, S);
//	cout << S;  //���12,����ͨ��
//	return 0;
//}