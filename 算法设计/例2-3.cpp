#include<iostream>
using namespace std;
//����2.3�� Fibonacci���ж���Ϊ��
//Fib(n) = 1			n = 1
//Fib(n) = 1			n = 2
//Fib(n) = Fib(n - 1) + Fib(n - 2)	n > 2
int Fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}
