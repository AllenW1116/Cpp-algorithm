#include<iostream>
using namespace std;

int fun(int n)
{
	if (n == 1)			//语句1
		return(1);		//语句2（递归出口）
	else				//语句3
		return(fun(n - 1)*n);	//语句4（递归体）
}
//【例2.1】设计求n!（n为正整数）的递归算法。
//在该函数fun(n)求解过程中，直接调用fun(n - 1)（语句4）自身，所以它是一个直接递归函数。又由于递归调用是最后一条语句，所以它又属于尾递归。