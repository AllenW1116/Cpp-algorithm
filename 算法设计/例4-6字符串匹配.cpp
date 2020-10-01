#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//暴力算法，s是原串，t是子串
int BF(string s, string t)	//字符串匹配
{
	int i = 0, j = 0;
	while (i < s.length() && j < t.length())
	{
		if (s[i] == t[j])		//比较的两个字符相同时
		{
			i++;
			j++;
		}
		else			//比较的两个字符不相同时
		{
			i = i - j + 1;		//i回退（i-j就是回到了本次匹配的开始字符；下次匹配应该从它的下一个字符开始）
			j = 0;			//j从0开始
		}
	}
	if (j == t.length())		//t的字符比较完毕
		return i - j;		//t是s的子串,返回位置
	else				//t不是s的子串
		return -1;		//返回-1
}
