#include<bits/stdc++.h>
using namespace std;

int countsetbits(int n) {
	int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}

int countsetbitsapproach2(int n) {
	int count = 0;
	while (n) {
		n = n & (n - 1);
		count++;
	}
	return count;
}

int countsetbitsrecursive(int n) {
	if (n == 0 or n == 1) {
		return n;
	}

	int count = 0;
	if (n % 2 == 0) {
		count = countsetbitsrecursive(n / 2);
	}
	else {
		count = 1 + countsetbitsrecursive(n / 2);
	}
	return count;
}


int countsetbitstopdown(int n, int *memo) {
	if (n == 0 or n == 1) {
		memo[n] = n;
		return n;
	}

	if (memo[n] != 0) {
		return memo[n];
	}

	int count = 0;
	if (n % 2 == 0) {
		count = countsetbitstopdown(n / 2, memo);
	}
	else {
		count = 1 + countsetbitstopdown(n / 2, memo);
	}
	memo[n] = count;
	return count;
}

int countsetbitsbottomup(int n) {
	int *dp = new int[n + 1];

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (i % 2 == 0) {
			dp[i] = dp[i / 2];
		}
		else {
			dp[i] = 1 + dp[i / 2];
		}
	}
	return dp[n];

}

int main(int argc, char const *argv[])
{
	int n;
	int memo[1000] = {0};
	cin >> n;
	cout << countsetbits(n) << endl;
	cout << countsetbitsapproach2(n) << endl;
	cout << countsetbitsrecursive(n) << endl;
	cout << countsetbitstopdown(n, memo) << endl;
	cout << countsetbitsbottomup(n) << endl;
	return 0;
}