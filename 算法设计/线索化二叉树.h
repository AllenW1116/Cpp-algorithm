#pragma once
#include<iostream>
#include"二叉树.h"
#include<cmath>
using namespace std;
typedef struct node {
	char chardata;
	int intdata;
	int ltag, rtag;
	struct node *lchild;
	struct node *rchild;
}TBTNode;


TBTNode *pre;



void Thread(TBTNode *&p);

TBTNode *CreateThread(TBTNode *b) {  //入口的参数是二叉树b的根节点！！！但返回的是线索化二叉树的头结点！！！
	TBTNode *root;
	root = (TBTNode*)malloc(sizeof(TBTNode));
	root->ltag = 0;  //ltag设为0；正常情况下头结点的左指针应指向根节点
	root->rtag =1 ;//root的rtag设为1！最后要手动让它指向最后一个节点 
	root->rchild = b;  //一开始先指向根节点；最后再手动让它指向最后一个结点就可
	if (b == NULL) {  //若为空树，头结点的左指针指向自己，右指针指向b（NULL）
		root->lchild = root;
	}
	else {
		root->lchild = b;
		pre = root;
		Thread(b);  //调用thread进行线索化

		pre->rchild = root;
		pre->rtag = 1;
		root->rchild = pre;   //手动把剩余被连上的线索连上
	}
	return root;

}

void Thread(TBTNode *&p) {
	if (p != NULL) {
		Thread(p->lchild);
		if (p->lchild == NULL) {
			p->lchild = pre;
			p->ltag = 1;
		}
		else
			p->ltag = 0;

		if (pre->rchild == NULL) {
			pre->rchild = p;
			pre->rtag = 1;
		}
		else
			pre->rtag = 0;

		pre = p;
		Thread(p->rchild);
	}
}

/*我们把中序二叉树进行线索化，目的就是遍历它可以更快。
现在我们来看看线索化二叉树的遍历算法！*/
void ThInorder(TBTNode *tb) {  //入口的参数是头结点！！！
	TBTNode *p = tb->lchild;//p指向根节点！
	while (p != tb) {
		while (p->ltag == 0) { p = p->lchild; }//找到最左下结点，即中序序列的开始结点
		cout << p->chardata;

		while (p->rtag == 1 && p->rchild != tb) {//p指向最后一个结点时，这层循环就结束啦
			p = p->rchild;
			cout << p->chardata;

		}
		p = p->rchild;

	}
}

//仿照前面建立BTNode二叉树的算法，此处设计一个建立TBTNode二叉树的算法(字符结点取大写字母)
void CreateTBTree(TBTNode *&b, char str[]) {        //用一个字符数组初始化一个二叉树（需已知树形）
	TBTNode *St[50], *p;            //St数组作为顺序栈,p始终指向栈顶元素
	int top = -1, flag = 2, j = 0;   //top为指向栈顶的指针；flag为标识，为0时开始处理左子树，为1时处理右子树；
	char ch = 'a'; int i = 0; int k; int w;
	b = NULL;


	if (str[0] >= 'A' && str[0] <= 'Z')   //对根节点进行初始化；
	{
		ch = str[0];
	}

	else if (str[0] >= '0' && str[0] <= '9') {  //需要注意，第一个节点可能就是多位数
		int data[10];
		for (k = 0; str[k] >= '0' && str[k] <= '9'; k++) {
			data[k] = int(str[k]) - 48;
		}//把n位数存进数组；注意要把字符1转变为数字1！

		for (w = k - 1; w >= 0; w--) { i += data[w] * pow(10, (k - 1 - w)); }//存进根节点的intdata
		j = j + k - 1;  //j要永远指向多位数的最后一位
	}



	while (str[j] != '\0') {
		switch (str[j]) {
		case'(':top++; St[top] = p; flag = 0; break;  //p指向栈顶元素；开始处理左孩子节点
		case')':top--; break;           //栈顶结点的子树处理完毕，返回到它的双亲结点
		case',':flag = 1; break;     //开始处理右子树
		default: {
			p = (TBTNode*)malloc(sizeof(TBTNode));
			p->chardata = ch;
			p->intdata = i;                //最后输出的时候决定输出哪种data就行了
			p->lchild = NULL; p->rchild = NULL;
			if (b == NULL)
			{
				b = p;
			}              //若尚未建立根节点，此时p所指的就是根节点（也即第一个字符）
			else {
				switch (flag) {
				case 0:St[top]->lchild = p; break;
				case 1:St[top]->rchild = p; break;
				}
			}
		}

		}
		j++;
		i = 0;  //intdata需要清零，因为要累加计算

		if (str[j] >= 'A' && str[j] <= 'Z')
		{
			ch = str[j];
		}
		else if (str[j] >= '0' && str[j] <= '9') {  //需要注意，节点可能是多位数
			int data[10];
			for (k = 0; str[j + k] >= '0' && str[j + k] <= '9'; k++) {
				data[k] = int(str[j + k]) - 48;
			}//把n位数存进数组；注意要把字符1转变为数字1！



			for (w = (k - 1); w >= 0; w--) { i += data[w] * pow(10, (k - 1 - w)); }//存进节点intdata
			j = j + k - 1;
		}
	}
}


void InOrder(TBTNode *b) {  //中序遍历二叉树，并直接输出结点值

	if (b != NULL) {
		InOrder(b->lchild);


		cout << b->chardata;

		InOrder(b->rchild);
	}
}