//这个算法是课本的改进版；实现了结点data的自动识别
/*#include <iostream>
#include<cmath>
using namespace std;
#pragma once
typedef struct node {       //链式存储二叉树的结点声明
	int intdata;
	char chardata;
	struct node *lchild;
	struct node *rchild;

}BTNode;

void CreateBTree(BTNode *&b, char str[]) {        //用一个字符数组初始化一个二叉树（需已知树形）
	BTNode *St[50], *p;            //St数组作为顺序栈,p始终指向栈顶元素
	int top = -1, flag=2, j = 0;   //top为指向栈顶的指针；flag为标识，为0时开始处理左子树，为1时处理右子树；
	char ch='A'; int i=0; int k; int w;
	b = NULL;   


	if (str[0] >= 'a' && str[0] <= 'z')   //对根节点进行初始化；
	{
		ch = str[0];
	}
	
	else if (str[0] >= '0' && str[0] <= '9') {  //需要注意，第一个节点可能就是多位数
		int data[10];
		for (k = 0; str[k] >= '0' && str[k] <= '9'; k++) {
			data[k] = int(str[k]) - 48; }//把n位数存进数组；注意要把字符1转变为数字1！
		
		for (w=k-1; w >= 0; w--) { i += data[w] * pow(10, (k-1 - w)); }//存进根节点的intdata
		j = j + k - 1;  //j要永远指向多位数的最后一位
	}



	while (str[j] != '\0') {
		switch (str[j]) {
		case'(':top++; St[top] = p; flag = 0; break;  //p指向栈顶元素；开始处理左孩子节点
		case')':top--; break;           //栈顶结点的子树处理完毕，返回到它的双亲结点
		case',':flag = 1; break;     //开始处理右子树
		default:{
			p = (BTNode*)malloc(sizeof(BTNode));
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
		
		if (str[j] >= 'a' && str[j] <= 'z')
		{
			ch = str[j];
		}
		else if (str[j] >= '0' && str[j] <= '9') {  //需要注意，节点可能是多位数
			int data[10];
			for (k = 0; str[j + k] >= '0' && str[j + k] <= '9'; k++) {
				data[k] = int(str[j + k]) - 48;
			}//把n位数存进数组；注意要把字符1转变为数字1！
			
			
			
			for (w = (k-1); w >= 0; w--) { i += data[w] * pow(10, (k-1 - w)); }//存进节点intdata
			j = j + k - 1;
		}
	}
}*/



