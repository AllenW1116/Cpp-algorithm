#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//2. ������������ö������洢�ṹ��ţ����ֵΪint���ͣ����һ���ݹ��㷨�������bt�����н��ֵ���ڵ���k�Ľ�������
//typedef struct BNode
//{
//	int data;
//	struct BNode *lchild, *rchild;
//} BTNode;		//������������� ,�����ǵݹ��
//
//BTNode *CreatBTprein(int *pre, int *in, int n) { //��֪������������кͽڵ���������Թ���һ��������
//	BTNode *b;
//	int *p;
//	int k;
//	if (n <= 0) return NULL;
//	b = (BTNode*)malloc(sizeof(BTNode));
//	b->data = *pre; //preָ��һ���ַ�����*preָ���һ���ַ�
//	for (p = in; p <= in + n; p++) {
//		if (*p == *pre)  //*��ָ��������ʾȡֵ
//			break;
//	}
//	k = p - in;           ///k��Ÿ������in�е����λ��
//	b->lchild = CreatBTprein(pre + 1, in, k);
//	b->rchild = CreatBTprein(pre + k + 1, p + 1, n - k - 1);
//	return b;
//}
//
//void BiggerK(BTNode *bt,int k,int &count) {
//	if (bt->lchild == NULL && bt->rchild == NULL) {
//		if (bt->data >= k) count++;
//	}
//	else {
//		BiggerK(bt->lchild,k,count);
//		BiggerK(bt->lchild,k,count);
//	}
//}
//
//int main() {
//	int pre[] = { 1,2,4,5,3 };
//	int in[] = { 4,2,5,1,3 };
//	BTNode *B = CreatBTprein(pre, in, 5);  //���������
//	int count = 0;
//	BiggerK(B, 3, count);
//	cout << count;  //���4,����ͨ��
//	return 0;
//}