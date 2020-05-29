#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n) {

	if (m == 0 or n == 0) {
		return 0;
	}

	if (s1[m - 1] == s2[n - 1]) {
		return 1 + lcs(s1, s2, m - 1, n - 1);
	}
	else {
		return max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));
	}

}

static int memo[1001][1001];

int lcsmemoized(string s1, string s2, int m, int n) {

	if (m == 0  or n == 0) {
		return 0;
	}

	if (memo[m][n] != -1) {
		return memo[m][n];
	}

	if (s1[m - 1] == s2[n - 1]) {
		memo[m][n] =  1 + lcsmemoized(s1, s2, m - 1, n - 1);
	}
	else {
		memo[m][n] =  max(lcsmemoized(s1, s2, m, n - 1), lcsmemoized(s1, s2, m - 1, n));
	}

	return memo[m][n];
}

int lcsbottomup(string s1, string s2, int m, int n) {
	int dp[m + 1][n + 1];

	for (int i = 0; i < m + 1; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			if (i == 0 or j == 0) {
				dp[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[m][n];
}

int main(int argc, char const *argv[])
{

	memset(memo, -1, sizeof(memo));
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int m =  str1.length();
	int n = str2.length();


	cout << lcs(str1, str2, m, n) << endl;
	cout << lcsmemoized(str1, str2, m, n) << endl;
	cout << lcsbottomup(str1, str2, m, n) << endl;
	return 0;
}