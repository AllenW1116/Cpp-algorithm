//3. 两种水果杂交出一种新水果，现在给新水果取名，要求这个名字中包含了以前两种水果名字的字母，并且这个名字要尽量短。
//也就是说以前的一种水果名字arr1是新水果名字arr的子序列，另一种水果名字arr2也是新水果名字arr的子序列。设计一个算法求arr。
//例如：输入以下3组水果名称：
//apple peach
//ananas banana
//pear peach
//输出的新水果名称如下：
//appleach
//bananas
//pearch
//该题的关键是：判断串s是否为串t的子序列。
//这里我们使用一个比较笨的方法：贪心搜索，若有单个字符匹配，则s的指针++。
//若最终s指针能指向s的末尾，说明s是t的子序列
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
#include<vector>
#define MAXV 10
#define INF 500
using namespace std;
map<string, int> mark; // 记录生成的newname的长度
bool isson(string s, string t) {
	int i = 0, j = 0;
	while (i < s.length() && j < t.length()) {
		if (s[i] == t[j]) { i++; }
		j++;
	}
	return i == s.length();
}
string confirm(string a, string b) {
	int i = 0, j = 0;
	for (i = 0; i < a.length(); i++) {
		string left = a.substr(0, i + 1);   //"abcd".substr(0,1)="a";
		for (j = 0; j < b.length(); j++) {
			string right = b.substr(b.length() - j - 1, j + 1);
			string newname = left + right;
			if (isson(a, newname) && isson(b, newname)) { mark[newname] = newname.length(); }
		}
	}
	map<string, int>::iterator it = mark.begin();
	string ansname = it->first;
	int minlength = it->second; it++;
	//遍历map mark中的newname
	while (it != mark.end()) {
		if (it->second < minlength) { ansname = it->first; }
		it++;
	}
	return ansname;
}
int main() {
	map<string, int>::iterator it = mark.begin();
	cout << confirm("apple", "peach");
	return 0;
}

