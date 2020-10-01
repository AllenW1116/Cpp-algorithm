#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
//6. 对于大于1的正整数n，可以分解为n=x1*x2*…*xm，其中xi≥2。
//例如，n=12时有8种不同的分解式：12=12，12=6*2，12=4*3，12=3*4，12=3*2*2，12=2*6，12=2*3*2，12=2*2*3，
//设计一个算法求n的不同分解式个数。
//设f（n）为n的分解式的个数，观察可以发现：
//f（1） = 1：1 = 1
//f（2） = 1：2 = 2
//f（3） = 1：3 = 3
//f（4） = 2：4 = 4，4 = 2 * 2；f（4） = f（1） + f（2）
//f（6） = 3：6 = 6，6 = 2 * 3，6 = 3 * 2；f（6） = f（1） + f(2) + f(3);
//发现：n的分解式个数=n的所有因数的分解式个数之和
//检查题目中的示例：12的因数有1，2，3，4，6；f（12）=f（1）+ f（2）+ f（3）+ f（4）+ f（6）=1+1+1+2+3=8，完美！
int deposition(int x) {
	if (x < 1) {
		return -1;
	}
	else if (x == 1) {
		return 1;
	}
	else {
		int sum = 0;
		for (int i = 1; i <= x/2; i++) {
			if (x%i == 0) { //i是x的一个因数
				sum += deposition( i);
			}
		}
		return sum;
	}	
}
//int main() {
//	cout << deposition(12); //输出8 测试通过
//	return 0;
//}

