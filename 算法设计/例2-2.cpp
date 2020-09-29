#include<iostream>
using namespace std;
//【例2.2】分析二叉树的二叉链存储结构的递归性，设计求非空二叉链bt中所有结点值之和的递归算法，假设二叉链的data域为int型。
typedef struct BNode
{
	int data;
	struct BNode *lchild,*rchild;
} BTNode;		//二叉链结点类型 ,定义是递归的


int Sumbt(BTNode *bt)		//求二叉树bt中所有结点值之和
{
	if (bt->lchild == NULL && bt->rchild == NULL)
		return bt->data;	//只有一个结点时返回该结点值
	else				//否则返回左、右子树结点值之和加上根结点值
		return Sumbt(bt->lchild) + Sumbt(bt->rchild) + bt->data;
}

