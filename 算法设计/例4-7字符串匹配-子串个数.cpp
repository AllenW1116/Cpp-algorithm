#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//����4.5���������ַ���s��t�����һ���㷨��t��s�г��ֵĴ��������磬s = "abababa"��t = "aba"����t��s�г���2�Ρ�
int Count(string s, string t)		//��t��s�г��ֵĴ���
{
	int num = 0;				//�ۼƳ��ִ���
	int i = 0, j = 0;
	while (i < s.length() && j < t.length())
	{
		if (s[i] == t[j])		//�Ƚϵ������ַ���ͬʱ
		{
			i++;
			j++;
		}
		else				//�Ƚϵ������ַ�����ͬʱ
		{
			i = i - j + 1;			//i����
			j = 0;				//j��0��ʼ
		}
		if (j == t.length())
		{
			num++;			//���ִ�����1
			j = 0;			//j��0��ʼ����
		}
	}
	return num;
}
