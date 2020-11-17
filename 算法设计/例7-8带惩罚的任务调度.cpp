#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
using namespace std;
//单处理器上带截止时间和惩罚的单位时间任务调度问题有以下输入：
//（1）n个单位时间任务的集合S = { a1,a2,…,an }；【单位时间任务】：执行时间为一个单位时间
//（2）n个整数表示截止时间d1, d2, …, dn，每个di满足1 <= di <= n，期望任务ai在时间di之前完成。
//（3）n个非负权重或者惩罚w1, w2, …, wn，若任务ai在时间di之前没有完成，就会受到wi这么多的惩罚
//，如果任务在截止时间之前完成，则不会受到惩罚。
//贪心选择方法：惩罚越大越优先执行！
//ppt76页!

void solve()				//求解问题
{
	memset(flag, 0, sizeof(flag));	//flag数组初始化
	sort(A, A + n);			//按逾期惩罚分递减排序
	int sum = 0;				//累计做过作业的时间
	for (int i = 0; i < n; i++)
	{
		if (A[i].d > sum)
		{
			flag[i] = true;		//选择做A[i]作业  
			sum++;			//时间加1
		}
	}
}

//CCSP题目：
//问题描述：小v上学，老师布置了n个作业，每个作业小v恰好需要一天做完，每个作业都有最后提交时间及其逾期的扣分。
//请你给出小v做作业的顺序，以便扣最少的分数。
//输入：输入包含多个测试用例。每个测试用例第一行为整数n（1≤n≤100），表示作业数，
//第2行包括n个整数表示每个作业最后提交的时间（天），第3行包括n个整数表示每个作业逾期的扣分。以输入n = 0结束。
//输出：每个测试用例对应两行输出，第一行为做作业的顺序（作业编号之间用空格分隔），第2行为最少的扣3分。
//输入样例：
//3			//3个作业
//1 3 1			//最后提交的时间（天）
//6 2 3			//逾期的扣分
//0
//样例输出：
//1 2
//3

//问题表示
struct Action
{
	int no;			  //作业编号
	int deadline;		  //最后提交的时间
	int score;			  //逾期的扣分
	bool operator < (const Action t) const
	{
		if (score == t.score)	  //扣分相同按提交时间递增排序
			return deadline < t.deadline;
		else
			return score > t.score;  //按逾期扣分递减排序
	}
};

int n;
Action A[MAX];			      //求解结果表示
bool flag[MAX];		      //空时间标志
int bests = 0;			      //最少的扣分
void solve()			      //求解赶作业问题
{
	int i, j;			      //累计做过作业的时间
	for (i = 0; i < n; i++)
	{
		for (j = A[i].deadline; j > 0; j--) //在当前作业最后提交时间之前找空时间
		{
			if (flag[j] == false)	      //找到了空时间
			{
				printf("%d ", A[i].no); //选择做作业A[i].no
				flag[j] = true;
				break;
			}
		}
		if (j == 0)		      //当前作业最后提交时间前找不到空时间
			bests += A[i].score;	      //不选择做作业A[i].no
	}
}








