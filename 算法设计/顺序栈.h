#pragma once
#include<iostream>
using namespace std;
typedef BTNode ElemType;

typedef struct {  //顺序栈结构体
	ElemType *data[50]; //存放栈中的元素
	int top; //存着栈顶元素的数组编号（栈为空时top为-1；栈满时为49）
}SqStack;

//初始化顺序栈：
void InitStack(SqStack *&s){  //参数是顺序栈指针
	s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1; //初始栈顶指针置为-1
}

//销毁顺序栈：
void DestroyStack(SqStack *&s) {
	free(s);
}

//判断顺序栈是否为空
bool StackEmpty(SqStack *&s) {
	return(s->top == -1);
}

//进栈
bool Push(SqStack *&s, ElemType *e) { //出口参数是一个定义好的顺序栈指针，和一个元素e;注意返回值是一个bool不是void
	if (s->top == 49)
		return false;  //栈满时返回false
	s->top++;
	s->data[s->top] = e; //栈顶指针先++，然后将要入栈的元素放入
	return true;
}

//出栈
bool Pop(SqStack *&s, ElemType *&e) { //入口参数为一个顺序栈指针，和一个用于存放取出的数据的ElemType；返回值类型是bool而非void
	if (s->top == -1)
		return false; //栈空时返回false
	e = s->data[s->top]; //取出栈顶元素存入e
	s->top--;
	return true;
}

//取栈顶元素
bool PopGetTop(SqStack *&s, ElemType *&e) { //入口参数为一个顺序栈指针，和一个用于存放取出的数据的ElemType；返回值类型是bool而非void
	if (s->top == -1)
		return false; //栈空时返回false
	e = s->data[s->top]; //取出栈顶元素存入e
	return true;
}





