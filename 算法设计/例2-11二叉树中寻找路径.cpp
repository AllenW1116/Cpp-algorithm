#include<iostream>
#include<vector>
using namespace std;
//【例2.11】假设二叉树采用二叉链存储结构，设计一个递归算法输出从根结点到值为x的结点的路径，假设二叉树中所有结点值不同。

//用vector<int>向量path存放从根结点到x结点的正向路径。
//f(b，x，path)的求解过程是：
//若b为空树，返回false；
//否则将b结点值加入到path中，如果b->data = x，查找成功返回true；
//如果b->data≠x，在左子树中查找，若在左子树找到值为x的结点，返回true，若在左子树没有找到值为x的结点，返回在右子树中的查找结果。
//左、右子树中查找都是“小问题”。
typedef struct BNode
{
	int data;
	struct BNode *lchild, *rchild;
} BTNode;		//二叉链结点类型 ,定义是递归的

bool Findxpath2(BTNode *bt, int x, vector<int> tmppath,vector<int> &path) 		//求根结点到x结点的（正向）路径;path作为全局变量存放解
{
	if (bt == NULL)			//空树返回false
		return false;
	tmppath.push_back(bt->data);	//当前结点加入path
	if (bt->data == x)			//当前结点值为x，返回true
	{
		path = tmppath;			//路径复制
		return true;
	}
	bool find = Findxpath2(bt->lchild, x, tmppath, path); //在左子树中查找
	if (find)				//左子树中成功找到
		return true;
	else				//左子树中没有找到，在右子树中查找
		return Findxpath2(bt->rchild, x, tmppath, path);
}

