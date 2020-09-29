#pragma once
#include<iostream>
using namespace std;
typedef char ElemType;
typedef int ElemType;
typedef struct linknode {
	ElemType data;
	struct linknode *next;
}LinkStNode; //链栈结点类型 

//初始化栈
void InitStack(LinkStNode *s) {
	s = (LinkStNode *)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

//销毁栈
void DestroyStack(LinkStNode *s) { //和销毁单链表相同
	LinkStNode *pre = s, *p = s->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p - p->next;
	}
	free(pre);
}

//判断是否为空
bool StackEmpty(LinkStNode *s) {
	return(s->next == NULL);
}

//进栈
void Push(LinkStNode *&s, ElemType e) {  //单链表头插法;不存在栈满的情况，所以不用bool了
	LinkStNode *p;
	p = (LinkStNode *)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

//出栈
bool Pop(LinkStNode *&s, ElemType &e) {
	if (s->next == NULL)
		return false; //如果栈空返回false
	LinkStNode *p = s->next;
	e = p->data;
	p->next = s->next;
	free(p);
	return true;

}

//取栈顶元素
bool GetTop(LinkStNode *&s, ElemType &e) {
	if (s->next == NULL)
		return false; //如果栈空返回false
	LinkStNode *p = s->next;
	e = p->data;
	return true;

}
