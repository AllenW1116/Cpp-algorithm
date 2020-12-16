#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
using namespace std;
//【问题描述】设要编码的字符集为{ d1，d2，…，dn }，它们出现的频率为{ w1，w2，…，wn }，
//应用哈夫曼树构造最优的不等长的由0、1构成的编码方案。
//
//
//哈夫曼树（Huffman Tree）的定义：设二叉树具有n个带权值的叶子结点，从根结点到每个叶子结点都有一个路径长度。
//从根结点到各个叶子结点的路径长度与相应结点权值的乘积的和称为该二叉树的带权路径长度。
//由n个叶子结点可以构造出多种二叉树，其中具有最小带权路径长度的二叉树称为哈夫曼树（也称最优树）。
//不难想象，权值小的在下面的结点；权值大的靠近根节点
//
//构造一棵哈夫曼树的方法如下：
//（1）由给定的n个权值{ w1，w2，…，wn }构造n棵只有一个叶子结点的二叉树，从而得到一个二叉树的集合F = { T1，T2，…，Tn }。
//（2）在F中选取根结点的权值最小和次小的两棵二叉树作为左、右子树构造一棵新的二叉树，
//这棵新的二叉树根结点的权值为其左、右子树根结点权值之和。即合并两棵二叉树为一棵二叉树。
//（3）重复步骤（2），当F中只剩下一棵二叉树时，这棵二叉树便是所要建立的哈夫曼树。

int n;
struct HTreeNode			//哈夫曼树结点类型
{
	char data;				//字符
	int weight;				//权值
	int parent;				//双亲的位置
	int lchild;				//左孩子的位置
	int rchild;				//右孩子的位置
};
HTreeNode ht[MAX];			//存放哈夫曼树

map<char, string> htcode;		//存放哈夫曼编码

struct NodeType			//优先队列结点类型
{
	int no;				//对应哈夫曼树ht中的位置
	char data;				//字符
	int  weight;			//权值
	bool operator<(const NodeType& s) const
	{					//用于创建小根堆，先出来的是权值小的
		return s.weight < weight;
	}
};
//哈夫曼树，n个叶子节点必有n-1个非叶子节点	；
void CreateHTree()			//构造哈夫曼树
{
	NodeType e, e1, e2;
	priority_queue<NodeType> qu;
	for (int k = 0; k < 2 * n - 1; k++)		//设置所有结点的指针域
		ht[k].lchild = ht[k].rchild = ht[k].parent = -1;
	for (int i = 0; i < n; i++)		//将n个结点进队qu，构成小根堆
	{
		e.no = i; e.data = ht[i].data;
		e.weight = ht[i].weight; qu.push(e);
	}
	for (int j = n; j < 2 * n - 1; j++)		//构造哈夫曼树的【n-1个非叶子结点】
	{
		e1 = qu.top();  qu.pop();		//出队权值最小的结点e1
		e2 = qu.top();  qu.pop();		//出队权值次小的结点e2
		ht[j].weight = e1.weight + e2.weight; //构造哈夫曼树的非叶子结点j	
		ht[j].lchild = e1.no;
		ht[j].rchild = e2.no;
		ht[e1.no].parent = j;		//修改e1.no的双亲为结点j
		ht[e2.no].parent = j;		//修改e2.no的双亲为结点j
		e.no = j;				//构造队列结点e（非叶子节点不需要data值，只需要weight和编号）
		e.weight = e1.weight + e2.weight;
		qu.push(e);
	}
}

void CreateHCode()		      //构造哈夫曼编码
{
	string code;
	code.reserve(MAX);     //预定一个空间
	for (int i = 0; i < n; i++)	      //构造叶子结点i的哈夫曼编码
	{
		code = "";
		int curno = i;
		int f = ht[curno].parent;
		while (f != -1)		      //循环到根结点
		{
			if (ht[f].lchild == curno)  //curno为双亲f的左孩子
				code = '0' + code;
			else			      //curno为双亲f的右孩子
				code = '1' + code;
			curno = f; f = ht[curno].parent;
		}
		htcode[ht[i].data] = code;     //得到ht[i].data字符的哈夫曼编码
	}
}
//编码是从叶子节点往根节点编