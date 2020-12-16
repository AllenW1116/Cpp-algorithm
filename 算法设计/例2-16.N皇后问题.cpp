#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

bool place(int i, int j)		//测试(i,j)位置能否摆放皇后
{
    if (i == 1) return true;		//第一个皇后总是可以放置
    int k = 1;
    while (k < i)			//k=1～i-1是已放置了皇后的行
    {
        if ((q[k] == j) || (abs(q[k] - j) == abs(i - k)))
            return false;
        k++;
    }
    return true;
}
void queen(int i, int n)		//放置1～i的皇后。i是第i行 初始1
{
    if (i > n)
        dispasolution(n);		//所有皇后放置结束
    else
    {
        for (int j = 1; j <= n; j++)	//在第i行上试探每一个列j（之前的子集树两分 三分，现在是n分）
            if (place(i, j))		//在第i行上找到一个合适位置(i,j)
            {
                q[i] = j;
                queen(i + 1, n);
            }
    }
}