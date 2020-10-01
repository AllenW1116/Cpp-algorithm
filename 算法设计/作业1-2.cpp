#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//2. 假设二叉树采用二叉链存储结构存放，结点值为int类型，设计一个递归算法求二叉树bt中所有结点值大于等于k的结点个数。
//typedef struct BNode
//{
//	int data;
//	struct BNode *lchild, *rchild;
//} BTNode;		//二叉链结点类型 ,定义是递归的
//
//BTNode *CreatBTprein(int *pre, int *in, int n) { //已知先序和中序序列和节点个数，可以构造一个二叉树
//	BTNode *b;
//	int *p;
//	int k;
//	if (n <= 0) return NULL;
//	b = (BTNode*)malloc(sizeof(BTNode));
//	b->data = *pre; //pre指向一个字符串，*pre指向第一个字符
//	for (p = in; p <= in + n; p++) {
//		if (*p == *pre)  //*加指针名，表示取值
//			break;
//	}
//	k = p - in;           ///k存放根结点在in中的相对位置
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
//	BTNode *B = CreatBTprein(pre, in, 5);  //构造二叉树
//	int count = 0;
//	BiggerK(B, 3, count);
//	cout << count;  //输出4,测试通过
//	return 0;
//}