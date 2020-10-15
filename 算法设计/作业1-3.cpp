#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//3. 假设二叉树采用二叉链存储结构存放，所有结点值均不相同，设计一个递归算法求值为x的结点的层次（根结点的层次为1），没有找到这样的结点时返回0。
typedef struct BNode
{
	int data;
	struct BNode *lchild, *rchild;
} BTNode;		//二叉链结点类型 ,定义是递归的

BTNode *CreatBTprein(int *pre, int *in, int n) { //已知先序和中序序列和节点个数，可以构造一个二叉树
	BTNode *b;
	int *p;
	int k;
	if (n <= 0) return NULL;
	b = (BTNode*)malloc(sizeof(BTNode));
	b->data = *pre; //pre指向一个字符串，*pre指向第一个字符
	for (p = in; p <= in + n; p++) {
		if (*p == *pre)  //*加指针名，表示取值
			break;
	}
	k = p - in;           ///k存放根结点在in中的相对位置
	b->lchild = CreatBTprein(pre + 1, in, k);
	b->rchild = CreatBTprein(pre + k + 1, p + 1, n - k - 1);
	return b;
}

int FindX(BTNode *bt, int x, int level)
{

	if (bt == NULL)//两种情况 树为空 或者 未找到 x
		return 0;
	else
	{
		if (bt->data == x)//找到x 返回层数
			return level;
		else
		{

			int l1 = FindX(bt->lchild, x, level + 1);//利用递归 继续寻找左子树 注意层数要增加
			if (l1 != 0)
				return l1;
			else
			{
				
				int l2 = FindX(bt->rchild, x,level + 1);//利用递归 继续寻找右子树 注意层数要增加
				if (l2 != 0)
					return l2;
				else
					return 0;//最后没找到 返回0
			}

		}
	}
}

//int main() {
//	int pre[] = { 1,2,4,5,3 };
//	int in[] = { 4,2,5,1,3 };
//	BTNode *B = CreatBTprein(pre, in, 5);  //构造二叉树
//
//	cout << FindX(B, 3, 1);  //输出2,测试通过
//	cout << FindX(B, 4, 1);  //输出3,测试通过
//	return 0;
//}
