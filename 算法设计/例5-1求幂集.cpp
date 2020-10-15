#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

//【例5.3】有一个含n个整数的数组a，所有元素均不相同，设计一个算法求其所有子集（幂集）。
//例如，a[] = { 1，2，3 }，所有子集是：{}，{ 3 }，{ 2 }，{ 2，3 }，{ 1 }，{ 1，3 }，{ 1，2 }，{ 1，2，3 }（输出顺序无关）。

//解：显然本问题的解空间为子集树，每个元素只有两种扩展，要么选择，要么不选择。
//采用深度优先搜索思路。解向量为x[]，x[i] = 0表示不选择a[i]，x[i] = 1表示选择a[i]。
//用i扫描数组a，也就是说问题的初始状态是（i = 0，x的元素均为0），目标状态是（i = n，x为一个解）。从状态（i，x）可以扩展出两个状态：
//不选择a[i]元素  下一个状态为（i + 1，x[i] = 0）。
//选择a[i]元素  下一个状态为（i + 1，x[i] = 1）。

void dfs(int a[], int n, int i, int x[]) //n：集合元素个数，也即解空间树层数 i：当前解空间树层数；x[]解向量
//回溯算法求解向量x
{
	if (i >= n)
		dispasolution(a, n, x);
	else
	{
		x[i] = 0; dfs(a, n, i + 1, x);		//不选择a[i]
		x[i] = 1; dfs(a, n, i + 1, x);		//选择a[i]
	}
}
void dispasolution(int a[], int n, int x[]) {
	for (int i = 0; i < n; i++) {
		if (x[i] == 1)  cout << a[i] << " ";
		else cout << "  ";
	}
	cout << endl;
}
//int main() {
//	int a[] = { 1,2,3,4 };
//	int x[] = { 0 };
//	dfs(a, 4, 0, x);
//	return 0;
//} 通过！

