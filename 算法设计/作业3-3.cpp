//3. ����ˮ���ӽ���һ����ˮ�������ڸ���ˮ��ȡ����Ҫ����������а�������ǰ����ˮ�����ֵ���ĸ�������������Ҫ�����̡�
//Ҳ����˵��ǰ��һ��ˮ������arr1����ˮ������arr�������У���һ��ˮ������arr2Ҳ����ˮ������arr�������С����һ���㷨��arr��
//���磺��������3��ˮ�����ƣ�
//apple peach
//ananas banana
//pear peach
//�������ˮ���������£�
//appleach
//bananas
//pearch
//����Ĺؼ��ǣ��жϴ�s�Ƿ�Ϊ��t�������С�
//��������ʹ��һ���Ƚϱ��ķ�����̰�����������е����ַ�ƥ�䣬��s��ָ��++��
//������sָ����ָ��s��ĩβ��˵��s��t��������
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
map<string, int> mark; // ��¼���ɵ�newname�ĳ���
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
	//����map mark�е�newname
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

