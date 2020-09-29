#include<iostream>
using namespace std;
//二叉树的递归算法设计
//二叉树是一种典型的递归数据结构，当一棵二叉树采用二叉链b存储时：
//设求解以b为根结点的整个二叉树的某功能为“大问题”。
//求解其左、右子树的相同功能为“小问题”。
//由大小问题之间的解关系得到递归体。
//再考虑特殊情况，通常是二叉树为空或者只有一个结点时，这时很容易求解，从而得到递归出口。
//
//
//【例2.8】对于含n（n > 0）个结点的二叉树，所有结点值为int类型，设计一个算法由其先序序列a和中序序列b创建对应的二叉链存储结构。
typedef int ElemType;
typedef struct BNode
{
	int data;
	struct BNode *lchild, *rchild;
} BTNode;		//二叉链结点类型 ,定义是递归的
BTNode *CreateBTree(ElemType a[], ElemType b[], int n)
//由先序序列a[0..n-1]和中序序列b[0..n-1]建立二叉链存储结构bt
{
	int k;
	if (n <= 0) return NULL;
	ElemType root = a[0];				//根结点值
	BTNode *bt = (BTNode *)malloc(sizeof(BTNode));
	bt->data = root;
	for (k = 0; k < n; k++)			//在b中查找b[k]=root的根结点
		if (b[k] == root)
			break;
	bt->lchild = CreateBTree(a + 1, b, k);			//递归创建左子树
	bt->rchild = CreateBTree(a + k + 1, b + k + 1, n - k - 1);	//递归创建右子树
	return bt;
}
