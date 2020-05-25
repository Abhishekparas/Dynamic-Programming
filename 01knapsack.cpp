#include<bits/stdc++.h>
using namespace std;

int knapsackrecursive(int* weight, int* price, int s, int n) {
	if (n == 0 or s == 0) {
		return 0;
	}

	if (weight[n - 1] <= s) {
		return max(price[n - 1] + knapsackrecursive(weight, price, s - weight[n - 1], n - 1), knapsackrecursive(weight, price, s, n - 1));
	}

	else if (weight[n - 1] > s) {
		return knapsackrecursive(weight, price, s, n - 1);
	}

}

int memo[1002][1002];

int knapsackmemoized(int* weight, int* price, int s, int n) {
	if (n == 0 or s == 0) {
		return 0;
	}

	if (memo[n][s] != -1) {
		return memo[n][s];
	}

	if (weight[n - 1] <= s) {
		memo[n][s] = max(price[n - 1] + knapsackmemoized(weight, price, s - weight[n - 1], n - 1), knapsackmemoized(weight, price, s, n - 1));
	}

	else if (weight[n - 1] > s) {
		memo[n][s] = knapsackmemoized(weight, price, s, n - 1);
	}
	return memo[n][s];

}

int knapsackbottomup(int* weight, int* price, int s, int n) {

	int dp[n + 1][s + 1];

	for (int i = 0; i < n + 1 ; ++i)
	{
		for (int j = 0; j < s + 1; ++j)
		{
			if (i == 0 or j == 0) {
				dp[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < n + 1 ; ++i)
	{
		for (int j = 1; j < s + 1; ++j)
		{
			if (weight[i - 1] <= j) {
				dp[i][j] = max(price[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);

			}
			else if (weight[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][s];

}


int main(int argc, char const *argv[])
{
	int n, s;
	cin >> n >> s;
	int weight[100];
	int price[100];
	for (int i = 0; i < n; ++i)
	{
		cin >> weight[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> price[i];
	}

	memset(memo, -1, sizeof(memo));
	cout << knapsackrecursive(weight, price, s, n) << endl;
	cout << knapsackmemoized(weight, price, s, n) << endl;
	cout << knapsackbottomup(weight, price, s, n) << endl;
	return 0;
}