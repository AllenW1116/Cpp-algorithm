#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

//n=8为例
//非递归回溯框架
int q[8];  //q[i]代表第i行的皇后放第几列
void Queens(int n)	//求解n皇后问题
{
	int i = 1;		//i表示当前行,也表示放置第i个皇后
	q[i] = 0;		//q[i]是当前列,每个新考虑的皇后初始位置置为0列
	while (i >= 1)	//尚未回溯到头，循环
	{
		q[i]++;		//原位置后移动一列
		while (q[i] <= n && !place(i))  //试探一个位置(i,q[i])
			q[i]++;
		if (q[i] <= n)	//为第i个皇后找到了一个合适位置(i,q[i])
		{
			if (i == n)	//若放置了所有皇后,输出一个解
			{
				for (int j = 0; j < 8; j++) { cout << q[j]+" "; };
			}
			else		//皇后没有放置完
			{
				i++;	//转向下一行,即开始下一个新皇后的放置
				q[i] = 0;	//每个新考虑的皇后初始位置置为0列
			}
		}
		else i--; 	//若第i个皇后找不到合适的位置,则回溯到上一个皇后
	}
}

bool place(int i)	//测试第i行的q[i]列上能否摆放皇后
{
	int j = 1;
	if (i == 1) return true;
	while (j < i)			//j=1～i-1是已放置了皇后的行
	{
		if ((q[j] == q[i]) || (abs(q[j] - q[i]) == abs(j - i)))
			//该皇后是否与以前皇后同列，位置(j,q[j])与(i,q[i])是否同对角线
			return false;
		j++;
	}
	return true;
}

//【算法分析】该算法中每个皇后都要试探n列，共n个皇后，其解空间是一棵子集树，不同于前面一般的二叉树子集树，这里每个结点可能有n棵子树。
//对应的算法时间复杂度为O(n^n)。