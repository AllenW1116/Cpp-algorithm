#pragma once
#include<iostream>
#include<string>
#include"二叉树.h"
#include"二叉树遍历.h"
using namespace std;
BTNode *CreatBTprein(char *pre, char *in, int n) { //已知先序和中序序列和节点个数，可以构造一个二叉树
	BTNode *b;
	char *p;
	int k;             
	if (n <= 0) return NULL;
	b = (BTNode*)malloc(sizeof(BTNode));
	b->chardata = *pre; //pre指向一个字符串，*pre指向第一个字符
	for (p=in; p<= in+n; p++) {
		if ( *p== *pre)  //*加指针名，表示取值
			break;       
	}
	k = p - in;           ///k存放根结点在in中的相对位置
	b->lchild = CreatBTprein(pre + 1, in, k);
	b->rchild = CreatBTprein(pre + k + 1, p+1, n - k-1);
	return b;
}

BTNode *CreatBTinpost(char *post, char *in, int n) { //已知中序和后序序列和节点个数，可以构造一个二叉树
	BTNode *b;
	char *p;
	int k;
	if (n <= 0) return NULL;
	b = (BTNode*)malloc(sizeof(BTNode));
	b->chardata = *(post+n-1);
	for (p = in; p < in + n; p++) {
		if (*p == *(post+n-1))
			break;       
	}
	k = p - in;             //k存放根结点在in中的相对位置
	b->lchild = CreatBTinpost(post, in, k);
	b->rchild = CreatBTinpost(post+k,p+1, n - k - 1);
	return b;
}