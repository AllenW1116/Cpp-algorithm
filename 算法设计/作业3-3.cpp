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
//本题的关键在于如何判断【串s是否是串t的子序列】
//对于s中的每个字符，不需要从t的开头开始搜索，而是从上一个匹配位置开始搜索。
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include <queue>		
#include<map>
using namespace std;
bool issub (string t, string s) {

}
