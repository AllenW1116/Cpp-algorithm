#pragma once
#include<iostream>
using namespace std;
typedef int ElemType;

//一.顺序表
typedef struct {  //SqList为顺序表
	ElemType data[50];
	int length;
}SqList;

//初始化顺序表
void InitList(SqList *&L) {
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
//销毁线性表
void DestroyList(SqList *&L) {
	free(L);
}
//判断是否为空表
bool ListEmpty(SqList *L) {
	return (L->length == 0);
}
//判断线性表长度
int ListLength(SqList *L) {
	return(L->length);
}
//输出线性表
void DispList(SqList *L) {
	for (int i = 0; i < L->length; i++) {
		cout << L->data[i];
	}
	cout << endl;
}
//求表中第i个元素的值
bool GetElem(SqList *L, int i, ElemType &e) {
	if (i<1 || i>L->length)
		return false;
	else
		return(L->data[i - 1]);
}
//插入数据元素(在表中的第i个位置插入新元素e，1<=i<=n+1)
bool InsertList(SqList *&L, int i, ElemType e) {
	int j;
	if (i<1 || i>L->length + 1)
		return false;
	else
		i--;
	for (j = L->length-1; j >= i; j--) {
		L->data[j+1] = L->data[j];
	}
	L->data[i] = e;
	L->length++;
}
//删除数据元素(删除表中的第i个元素，并返回被删元素的值)
bool ListDelete(SqList *&L, int i, ElemType &e) {
	int j;
	if (j<1 || j>L->length)
		return false;
	else
		i--;
	for (j = i; j < L->length - 1; j++) {
		L->data[j] = L->data[j + 1];
	}
	L->length++;
}

//二.单链表
typedef struct LNode {
	ElemType e;
	struct LNode *next;

}LinkNode;

//头插法建立单链表
void CreatListL(LinkNode *&L, int A[], int n) {
	LNode *s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		s= (LinkNode*)malloc(sizeof(LinkNode));
		s->e = A[i];
		s->next = L->next;
		L->next=s;
	}
}

//尾插法建立单链表
void CreatListR(LinkNode *&L, int A[], int n) {
	LNode *s, *R;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	R = L;
	for (int i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->e = A[i];
		R->next = s;
		R = s;
	}
	R->next = NULL;
}