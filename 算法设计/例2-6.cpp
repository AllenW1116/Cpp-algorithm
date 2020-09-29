#include<iostream>
using namespace std;
//【例2.6】有一个不带头结点的单链表L，设计一个算法释放其中所有结点。
//解：设L = { a1，a2，…，an }，f(L)的功能是释放a1～an的所有结点，则f(L->next)的功能是释放a2～an的所有结点，
//前者是“大问题”，后者是“小问题”。
//假设f(L->next)是已实现，则f(L)就可以采用先调用f(L->next)，然后释放L所指结点来求解。
//f(L) ≡不做任何事件		    当L = NULL时
//f(L) ≡ f(L->next); 释放L结点	    其他情况
typedef int ElemType;

typedef struct LNode {
	ElemType e;
	struct LNode *next;

}LinkNode;//数据结构定义是递归的

void DestroyList(LinkNode *&L)
//释放单链表L中所有结点
{
	if (L != NULL)
	{
		DestroyList(L->next);
		free(L);
	}
}
