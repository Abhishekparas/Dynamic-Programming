#include<bits/stdc++.h>
using namespace std;
int fibonaccirecursive(int n) {
	if (n == 0 or n == 1) {
		return n;
	}
	int ans = fibonaccirecursive(n - 1) + fibonaccirecursive(n - 2);
	return ans;
}

int fibonaccitopdown(int n, int *memo) {
	if (n == 0 or n == 1) {
		memo[n] = n;
		return memo[n];
	}

	if (memo[n] != 0) {
		return memo[n];
	}
	int ans = fibonaccitopdown(n - 1, memo) + fibonaccitopdown(n - 2, memo);
	memo[n] = ans;
	return memo[n];

}

int fibonaccibottomup(int n) {
	int* dp = new int[n + 1];

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int fibonaccibottomupspaceoptimised(int n) {
	int a = 0;
	int b = 1;
	int c;
	for (int i = 2; i <= n; ++i)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;

}
int main() {
	int n;
	cin >> n;
	int memo[1000] = {0};
	cout << fibonaccirecursive(n) << endl;
	cout << fibonaccitopdown(n, memo) << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << memo[i] << " ";
	}
	cout << endl;
	cout << fibonaccibottomup(n) << endl;
	cout << fibonaccibottomupspaceoptimised(n) << endl;

	return 0;
}