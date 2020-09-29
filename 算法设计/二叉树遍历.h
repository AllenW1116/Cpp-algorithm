#include"二叉树.h"
#include<iostream>
#include"顺序栈.h"
using namespace std;
#pragma once
void PreOrder(BTNode *b) {   //先序遍历二叉树，并直接输出结点值
	if (b != NULL ) 
	{
		cout << b->chardata;
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}


void InOrder(BTNode *b) {  //中序遍历二叉树，并直接输出结点值

	if (b != NULL ) { 
		InOrder(b->lchild);

		
		cout << b->chardata;

		InOrder(b->rchild);
	}	
}







void PostOrder(BTNode *b) {  //后序遍历二叉树，并直接输出结点值
	if (b != NULL) {
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		cout << b->chardata;
	}
}







/*void inorder1(BTNode *b,char test[50]) {  //中序遍历非递归算法，并且把访问的结点存进test【】
	BTNode *p;
	SqStack *st;
	int i = 0;
	InitStack(st);
	p = b;
	while (!StackEmpty(st) || p != NULL) {
		while (p != NULL) {  //扫描p的所有左下结点并进栈
			bool t=Push(st, p);
			p = p->lchild;
		}
		if (!StackEmpty(st)) {
			Pop(st, p);
			
			test[i] = p->data; i++;    //访问结点并且存入test【】
			p = p->rchild;
			
		}
	}
	cout << endl;
	DestroyStack(st);
}*/

void inorder1(BTNode *b) {  //中序遍历非递归算法
	BTNode *p;
	SqStack *st;
	int i = 0;
	InitStack(st);
	p = b;
	while (!StackEmpty(st) || p != NULL) {
		while (p != NULL) {  //扫描p的所有左下结点并进栈
			bool t = Push(st, p);
			p = p->lchild;
		}
		if (!StackEmpty(st)) {
			Pop(st, p);

			cout << p->chardata;
			p = p->rchild;

		}
	}
	cout << endl;
	DestroyStack(st);





void LevelOrder(BTNode *b);  //层次遍历二叉树
