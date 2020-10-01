#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【例4.1】编写一个程序，输出2～1000之间的所有完全数。所谓完全数，是指这样的数，该数的各因子（除该数本身外）之和正好等于该数本身，例如：
//6 = 1 + 2 + 3
//28 = 1 + 2 + 4 + 7 + 14
//解：先考虑对于一个整数m，如何判断它是否为完全数。
//从数学知识可知：一个数m的除该数本身外的所有因子都在1～m / 2之间。
//算法中要取得因子之和，只要在1～m / 2之间找到所有整除m的数，将其累加起来即可。
//如果累加和与m本身相等，则表示m是一个完全数，可以将m输出。
void main1()
{
	int m, i, s;
	for (m = 2; m <= 1000; m++)
	{
		s = 0;
		for (i = 1; i <= m / 2; i++)
			if (m%i == 0) s += i;	//i是m的一个因子
		if (m == s)
			printf("%d ", m);
	}
	printf("\n");
}

