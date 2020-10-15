#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

//【例5.4】设计一个算法在1，2，…，9（顺序不能变）数字之间插入 + 或 - 或什么都不插入，使得计算结果总是100的程序，并输出所有的可能性。
//例如：1 + 2 + 34–5 + 67–8 + 9 = 100。

//解：用【数组a】存放1～9的整数，用【字符数组op】存放插入的运算符，op[i]表示在a[i]之前插入的运算符。
//采用回溯法产生和为100的表达式，op[i]只能取值 + 、 - 或者空格（不同于上一个示例，这里是三选一）。设计函数：
//fun(op，sum，prevadd，a，i)
//其中：sum记录考虑整数a[i]时前面表达式计算的整数和（初始值为a[0]），prevadd记录前面表达式中的一个数值（初始值为a[0]）
//，i从1开始到9结束，如果sum = 100，得到一个解。

const int N = 9;
void fun(char op[], int sum, int prevadd, int a[], int i)
{
	if (i == N)			  //扫描完所有位置
	{
		if (sum == 100)		  //找到一个解
		{
			printf("  %d", a[0]);	  //输出解
			for (int j = 1; j < N; j++)
			{
				if (op[j] != ' ')
					printf("%c", op[j]);
				printf("%d", a[j]);
			}
			printf("=100\n");
		}
		return;
	}
	op[i] = '+';		  //位置i插入'+'
	sum += a[i];		  //计算结果
	fun(op, sum, a[i], a, i + 1);	  //继续处理下一个位置
	sum -= a[i];		  //回溯



	op[i] = '-';		  //位置i插入'-'
	sum -= a[i];		  //计算结果
	fun(op, sum, -a[i], a, i + 1);	  //继续处理下一个位置
	sum += a[i];		  //回溯



	op[i] = ' ';		  //位置i插入' '  //插入空格的意思：3 4 means 34！
	sum -= prevadd;		  //先减去前面的元素值  它要作十位而不是一个单独的数了 故把它减去
	int tmp;			  //计算新元素值
	if (prevadd > 0)
		tmp = prevadd * 10 + a[i];	  //如prevadd=5,a[i]=6,结果为56
	else
		tmp = prevadd * 10 - a[i];	  //如prevadd=-5,a[i]=6,结果为-56
	sum += tmp;			  //计算合并结果
	fun(op, sum, tmp, a, i + 1);	  //继续处理下一个位置
	sum -= tmp;			  //回溯sum
	sum += prevadd;			//为啥这里要用一个新的变量temp来存两位数而不是用统一的prevadd？如果把prevadd中的单位数覆盖了，就没法回溯了！
}

void main()
{
	int a[N];
	char op[N];			//op[i]表示在位置i插入运算符
	for (int i = 0; i < N; i++)  	//为a赋值为1,2，...,9
		a[i] = i + 1;
	printf("求解结果\n");
	fun(op, a[0], a[0], a, 1);	//插入位置i从1开始
}

