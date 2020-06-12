#include <bits/stdc++.h>
using namespace std;

int lis(int* arr, int n) {
	int dp[1000] = {0};

	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
	}

	int maxLength = 0;

	for (int i = 1; i < n; ++i)			//started from 1 because for 1st element,length of lis will be 1
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxLength = max(maxLength, dp[i]);
	}
	return maxLength;
}

int main(int argc, char const *argv[])
{
	int arr[10] = {50, 3, 10, 7, 40, 50};
	int n = 6;
	cout << lis(arr, n) << endl;
	return 0;
}