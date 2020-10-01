#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//【例4.5】有两个字符串s和t，设计一个算法求t在s中出现的次数。例如，s = "abababa"，t = "aba"，则t在s中出现2次。
int Count(string s, string t)		//求t在s中出现的次数
{
	int num = 0;				//累计出现次数
	int i = 0, j = 0;
	while (i < s.length() && j < t.length())
	{
		if (s[i] == t[j])		//比较的两个字符相同时
		{
			i++;
			j++;
		}
		else				//比较的两个字符不相同时
		{
			i = i - j + 1;			//i回退
			j = 0;				//j从0开始
		}
		if (j == t.length())
		{
			num++;			//出现次数增1
			j = 0;			//j从0开始继续
		}
	}
	return num;
}
