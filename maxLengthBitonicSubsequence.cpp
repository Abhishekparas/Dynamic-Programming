#include <bits/stdc++.h>
using namespace std;

int solve(int* arr, int n) {
	int dp[1001];
	int ds[1001];
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
		ds[i] = 1;
	}

	for (int i = 1; i < n ; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j])
				ds[i] = max(ds[i], ds[j] + 1);
		}
	}

	int maxLength = 0;

	for (int i = 0; i < n; ++i)
	{
		if ( (dp[i] + ds[i] - 1) > maxLength) {
			maxLength = dp[i] + ds[i] - 1;
		}
	}
	return maxLength;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	int arr[1001];
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cout << solve(arr, n) << endl;
	}
	return 0;
}