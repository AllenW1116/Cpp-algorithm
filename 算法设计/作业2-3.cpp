#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

//3. 给定若干个正整数a0、a0 、…、an - 1 ，从中选出若干数，使它们的和恰好为k，要求找选择元素个数最少的解。
//此处采用一个比较笨的方法：回溯法求出幂集，找出密集中元素和为k的集合装入新的幂集，再遍历得到其中个数最少的。
//测试数据：
int a[] = { 1,2,3,4,5 };
int length = 5;
int M = 7;
int x[];

vector<vector<int> > ps;		//存放幂集（应当是一个全局变量，存最终的结果）
void PSet(int n[])			//求a[]幂集
{
	vector<vector<int> > ps1;		//子幂集
	vector<vector<int> >::iterator it;//幂集迭代器
	vector<int> s;					//一个空集合
	ps.push_back(s);			//添加{}空集合元素
	for (int i = 0; i < length; i++)		//循环添加a[]中的元素
	{
		ps1 = ps;				//ps1存放上一步得到的幂集
		for (it = ps1.begin(); it != ps1.end(); ++it)
			(*it).push_back(a[i]);		//在ps1的每个集合元素末尾添加i
		for (it = ps1.begin(); it != ps1.end(); ++it)
			ps.push_back(*it);		//将ps1的每个集合元素添加到ps中
	}
}
int sum(vector<int> v);
vector<int> getresult(vector<vector<int> > ps) {
	vector<vector<int> >::iterator it;//幂集迭代器
	vector<int>::iterator it1; //集合迭代器
	vector<int> minv = ps.back();  //要求最小值，我们应当把初始值设为最大值！那便是最后一个集合长度最大
	for (it = ps.begin(); it != ps.end(); ++it) {
		if ((*it).size() < minv.size() && sum(*it) == M) { minv = *it; }  //找寻满足条件且长度更小的的集合
	}

	return minv;

}
int sum(vector<int> v) {
	int sum = 0;
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
	}
	return sum;
}

int main() {
	PSet(a);
	vector<int> result = getresult(ps);
	for (unsigned int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	return 0; //输出{3 4} 通过！
}

