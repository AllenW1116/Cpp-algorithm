#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
using namespace std;
//【问题描述】有n个作业（编号为1～n）要在由两台机器M1和M2组成的流水线上完成加工。
//每个作业加工的顺序都是先在M1上加工，然后在M2上加工。M1和M2加工作业i所需的时间分别为ai和bi（1≤i≤n）。
//流水作业调度问题要求确定这n个作业的最优加工顺序，使得从第一个作业在机器M1上开始加工，
//到最后一个作业在机器M2上加工完成所需的时间最少。
//可以假定任何作业一旦开始加工，就不允许被中断，直到该作业被完成，即非优先调度。

//【贪心性质】：让(a,b)中a比较小的尽可能先执行，(a,b)中b比较小的尽可能后执行！总体而言就是尽可能减少等待时间！
//推导过程：ppt86-88页。当时没太看明白……
//Johnson贪心算法：
//（1）把所有作业按M1、M2的时间分为两组，a[i]≤b[i]对应第1组N1，a[i] > b[i]对应第0组N2。
//（2）将N1的作业按a[i]递增排序，N2的作业按b[i]递减排序。
//（3）按顺序先执行N1的作业，再执行N2的作业，得到的就是耗时最少的最优调度方案。
//示例：ppt90页
struct NodeType
{
	int no;			//作业序号
	bool group;			//1代表第一组N1,0代表第二组N2（先按a增序执行N1；再按b降序执行N2）
	int time;			//a,b的最小时间
	bool operator<(const NodeType& s) const
	{
		return time < s.time;	//用于按time递增排序
	}
};

//问题表示
int n = 4;
int a[N] = { 5,12,4,8 };		//对应M1的时间
int b[N] = { 6,2,14,7 };		//对应M2的时间
struct NodeType
{
	int no;			//作业序号
	bool group;			//1代表第一组N1,0代表第二组N2
	int time;			//a,b的最小时间
	bool operator<(const NodeType& s) const
	{
		return time < s.time;	//按time递增排序
	}
};
//求解结果表示
int best[N];			//最优调度序列

int solve()		//求解流水作业调度问题
{
	int i, j, k;
	NodeType c[N];
	for (i = 0; i < n; i++)	//n个作业中,求出每个作业的最小加工时间 
	{
		c[i].no = i;
		c[i].group = (a[i] <= b[i]);
		//a[i]<=b[i]对应第1组N1,a[i]>b[i]对应第0组N2
		c[i].time = a[i] <= b[i] ? a[i] : b[i];
		//第1组存放a[i],第0组存放b[i]
	}
	sort(c, c + n);	//c元素按time递增排序（N1按a递增；N2按b递增）
	j = 0; k = n - 1;


	for (i = 0; i < n; i++)		//扫描c所有元素,产生最优调度方案
	{
		if (c[i].group == 1)	//第1组,按time递增排列放在best的前面部分
			best[j++] = c[i].no; //best[]0号元素没用吗？？？应该是用了，先给数组赋值，再j++
		else			//第0组,按time递减排列放到best的后面部分
			best[k--] = c[i].no;//同理，best[]最后一个元素也用了。先给数组赋值，再k--
	}


	int f1 = 0;			//累计M1上的执行时间
	int f2 = 0;			//最优调度下的消耗总时间
	for (i = 0; i < n; i++)
	{
		f1 += a[best[i]];
		f2 = max(f2, f1) + b[best[i]];
	}
	return f2;
}


