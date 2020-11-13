#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//5. 采用递归回溯法设计一个算法求1～n的n个整数中取出m个元素的排列，
//要求每个元素最多只能取一次。
//例如，n = 3，m = 2的输出结果是（1，2），（1，3），（2，1），（2，3），（3，1），（3，2）。
//排列过程=先找到m个元素的组合，再将每种组合分别进行全排列
//所以先使用蛮力法求出所有可能的组合（增序），再将每个组合求全排列。
//测试数据：n = 3，m = 2的输出结果是（1，2），（1，3），（2，1），（2，3），（3，1），（3，2）。



int n = 3;
int m = 2;
int a[50]; //存放一个组合
vector<vector<int> > psc;		//存放组合

vector<int> getv(int A[]) {  //数组转为vector
	
	vector<int> v(A, A + m);
	return v;
}

void comb(int n, int m)	//求1..n中m个整数的组合
{
	if (m == 0)			//k为0时将该组合存入ps
		psc.push_back(  getv(a) );
	else
	{
		for (int i = m; i <= n; i++)
		{
			a[m - 1] = i;		//a[k-1]位置取k～n的整数
			comb(i - 1, m - 1);
		}
	}
}




vector<vector<int> > psv;   //存放排列
bool repeat(vector<int> s, vector < vector<int> > p) {
	vector<vector<int> >::iterator it;
	bool repeatflag = false;
	for (it = p.begin(); it != p.end(); ++it) {
		if ((*it) == s) repeatflag = true;
	}
	return repeatflag;
}

void Insert(vector<int> s, int i, vector<vector<int> > &ps1)
{
	vector<int> s1;
	vector<int>::iterator it;
	for (int j = 0; j < i + 1; j++)	//在s(含i-1个整数)的每个位置插入
	{
		s1 = s;
		it = s1.begin() + j;	//求出插入位置
		s1.insert(it, a[i]);	//插入整数i
		if (!repeat(s1, ps1)) {    //ps1不包含s1
			ps1.push_back(s1);
		}//添加到ps1中
	}
}

void Perm(vector<int > a)			//a[m]的所有排列
{
	vector<vector<int> > ps1;		//临时存放子排列
	vector<vector<int> >::iterator it;//全排列迭代器
	vector<int> s, s1;
	s.push_back(a[0]);
	psv.push_back(s);
	for (int i = 1; i < a.size(); i++)		//循环添加
	{
		ps1.clear();			//ps1存放插入i的结果
		for (it = psv.begin(); it != psv.end(); ++it)
		{
			Insert(*it, i, ps1);
		}
		psv = ps1;
	}
} 


int main() {
	comb(n,m); //将组合存入psc中
	vector<vector<int> >::iterator it;
	vector<vector<int> >::iterator itv;
	vector<int>::iterator it1;
	for (it = psc.begin(); it != psc.end(); ++it) {
		psv.clear();
		//求该组合的全排列
		Perm(*it);

		//输出该次psv
		for (itv = psv.begin(); itv != psv.end(); ++itv) {
			for (it1 = (*itv).begin(); it1 != (*itv).end(); ++it1) {
				cout << *it1 << " ";
			}
			cout << endl;
		}

	}
	return 0;
}



