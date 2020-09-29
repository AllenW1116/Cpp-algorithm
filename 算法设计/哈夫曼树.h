#pragma once
/*用数组构造、储存哈夫曼树；哈夫曼编码*/
#include<iostream>
#include<string>
using namespace std;
typedef struct {
	string data;   //字符是一个单词
	double weight;  
	int parent;
	int lchild;
	int rchild;   //int变量存放结点的数组编号
}HTNode;


void CreatHT(HTNode ht[], int n0) { /*ht数组存放着哈夫曼叶子结点，作为形参输入时，只需要
									定义叶子节点的权值即可（结构体中的其他数据会自动初始化为0）；*/

	int i, k, lnode, rnode;
	double min1, min2;  //min1存放最小值，min2存放次小值
	for (i = 0; i < 2 * n0 - 1; i++)
	{
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}//毕竟形参输入时这些都自动初始化为0了

	for (i = n0; i < 2 * n0 - 1; i++) {  //构造哈夫曼树的分支节点
		min1 = min2 = 32767;//int型最大值初始化，确保肯定比结点权值大
		lnode = rnode = -1;
		for (k = 0; k <=i-1; k++) {//这层循环的作用是：从当前余下的结点中找到权值最小的两个！
			if (ht[k].parent == -1) {    //还没加入到哈夫曼树里的结点！
				if (ht[k].weight < min1) {  //更新最小值结点
					min2 = min1; rnode = lnode;
					min1 = ht[k].weight; lnode = k;
				}
				else if (ht[k].weight < min2) {  //更新次小值结点
					min2 = ht[k].weight; rnode = k;
				}
			}
		}
		ht[lnode].parent = i; 
		ht[rnode].parent = i;
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode; ht[i].rchild = rnode;
		
	}
}

typedef struct {
	int cd[50];
	int start;
	int d;  //该字符哈夫曼编码的长度
	double p;//该字符出现的频率
}HCode;

void CreatHCode(HTNode ht[], HCode hcd[], int n0) {//入口参数是：一个存放哈夫曼树的数组ht【】；
	                                               //一个存放HCode的结构体数组hcd【】，其中每一个元素为一个HCode；n0为叶子节点数
	int i, f, c;
	HCode hc;
	double sum = 0;
	for (int k = 0; k < n0; k++) {   //根据字符出现的频度，计算它的频率
		sum = sum + ht[k].weight;   //sum为总频度
	}
	for (i = 0; i < n0; i++) {
		hc.start = n0; c = i;
		f = ht[i].parent;
		while (f != -1) {
			if (ht[f].lchild == c)
				hc.cd[hc.start--] = 0;
			else
				hc.cd[hc.start--] = 1;
			c = f; f = ht[f].parent;

		}
		hc.start++;  
		hc.d = n0 - hc.start + 1;
		hc.p = ht[i].weight / sum;
		cout << ht[i].data << ":";
		for (int j = hc.start; j <= n0; j++) {  //输出当前节点的哈夫曼编码
			cout<< hc.cd[j] << " ";
		}
		hcd[i] = hc;
		
		cout << endl;

	}
	double WPL=0.0;
	for (int s = 0; s < n0; s++) {
		WPL=WPL+ hcd[s].d*hcd[s].p;
	}
	cout << "平均查找长度=" << WPL;
}//若想输出某个结点i的哈夫曼编码，输出的是hcd[i]中cd数组的start到n0；

