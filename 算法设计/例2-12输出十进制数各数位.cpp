#include<iostream>
#include<vector>
using namespace std;

//【例2.12】设计一个递归算法，输出一个大于零的十进制数n的各数字位，如n = 123，输出各数字位为123。
//设f(n)的功能是输出十进制数n的各数字位，则f(n / 10)的功能是输出除a0（即n % 10，也就是最后一位）外的各数字位
//，前者是“大问题”，后者是“小问题”。
//f(n)  不做任何事件			当n = 0时
//f(n)  f(n / 10); 输出n％10		其他情况


void digits(int n)
{
	if (n != 0)
	{
		digits(n / 10);
		cout<<(n%10);
	}
}
