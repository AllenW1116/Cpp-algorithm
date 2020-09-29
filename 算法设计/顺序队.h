#pragma once
#include<iostream>
using namespace std;
//typedef char ElemType;
typedef int ElemType;
typedef struct {
	ElemType data[50];
	int front, rear; //队头、队尾指针；front存的是队头元素的下标再-1，而rear存的是队尾元素的下标！
}SqQueue;

//初始化队列
void InitQueue(SqQueue *&s) {
	s = (SqQueue *)malloc(sizeof(SqQueue));
	s->rear = s->front = -1;
}

//销毁队列
void DestroyQueue(SqQueue *&q) {
	free(q);
}

//判断队列是否为空
bool QueueEmpty(SqQueue *&q) {
	return(q->rear == q->front);
}

//进队列
bool enQueue(SqQueue *&q, ElemType e) {//从队尾进
	if (q->rear == 49)
		return false;
	else
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

//出队列
bool deQueue(SqQueue *&q, ElemType &e) {
	if (QueueEmpty(q))
		return false;
	else
	{
		q->front++;
		e = q->data[q->front];
		return true;
	}
	    
}

