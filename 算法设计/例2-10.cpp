#include<iostream>
using namespace std;
//【例2.10】假设二叉树采用二叉链存储结构，设计一个递归算法由二叉树bt复制产生另一棵二叉树bt1。
//解：设f(bt，bt1)的功能是由二叉树bt复制产生另一棵二叉树bt1，它是“大问题”，
//则f(bt->lchild，bt1->lchild)的功能就是由bt的左子树复制产生bt1的左子树，
//f(bt->rchild，bt1->rchild)的功能就是由bt的右子树复制产生bt1的右子树，它们是“小问题”。
//
//f(bt，bt1)  bt1 = NULL				当b = NULL时
//f(bt，bt1)  由bt结点复制产生bt1结点;		其他情况
//f(bt->lchild，bt1->lchild);
//f(bt->rchild，bt1->rchild)

typedef struct BNode
{
	int data;
	struct BNode *lchild, *rchild;
} BTNode;		//二叉链结点类型 ,定义是递归的


void CopyBTree(BTNode *bt, BTNode *&bt1)
//由二叉树bt复制产生bt1
{
	if (bt == NULL)
		bt1 = NULL;
	else
	{
		bt1 = (BTNode *)malloc(sizeof(BTNode));
		bt1->data = bt->data;
		CopyBTree(bt->lchild, bt1->lchild);
		CopyBTree(bt->rchild, bt1->rchild);
	}
}
