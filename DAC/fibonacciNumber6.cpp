// Program to print the nth fibonacci number - Time: O(logn) - Space: O(1)

/*
 If n is even then k = n/2:
F(n) = [2*F(k-1) + F(k)]*F(k)

If n is odd then k = (n + 1)/2
F(n) = F(k)*F(k) + F(k-1)*F(k-1)
*/


#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

int f[MAX] = {0};

int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (f[n] = 1);

	if (f[n])
		return f[n];

	int k = (n & 1)? (n+1)/2 : n/2;

	f[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1))
		: (2*fib(k-1) + fib(k))*fib(k);

	return f[n];
}

int main()
{
	int n = 9;
	printf("%d\n", fib(n));
	return 0;
}
