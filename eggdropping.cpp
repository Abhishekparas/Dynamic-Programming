#include <bits/stdc++.h>
using namespace std;

int eggRecursive(int eggs, int floors) {
	if (floors == 0 or floors == 1) {
		return floors;
	}

	if (eggs == 0 or eggs == 1) {
		return floors;
	}

	int minFloors = INT_MAX;

	for (int k = 1; k <= floors; k++) {
		int temp = 1 + max(eggRecursive(eggs - 1, k - 1), eggRecursive(eggs, floors - k)); // attempts + max is taken because we have to find the attempts in worst case
		minFloors = min(minFloors, temp);   	//min is used because we have to minimize the attempts
	}
	return minFloors;
}

static int dp[100][100];

int eggMemoized(int eggs, int floors) {
	if (floors == 0 or floors == 1) {
		return floors;
	}

	if (eggs == 0 or eggs == 1) {
		return floors;
	}

	if (dp[eggs][floors] != -1) {
		return dp[eggs][floors];
	}

	int minFloors = INT_MAX;

	for (int k = 1; k <= floors; k++) {
		int temp = 1 + max(eggMemoized(eggs - 1, k - 1), eggMemoized(eggs, floors - k)); // attempts + max is taken because we have to find the attempts in worst case
		minFloors = min(minFloors, temp);   	//min is used because we have to minimize the attempts
	}

	dp[eggs][floors] = minFloors;
	return dp[eggs][floors];

}

int eggOptimized(int eggs, int floors) {

	int low, high;

	if (floors == 0 or floors == 1) {
		return floors;
	}

	if (eggs == 0 or eggs == 1) {
		return floors;
	}

	if (dp[eggs][floors] != -1) {
		return dp[eggs][floors];
	}


	int minFloors = INT_MAX;

	for (int k = 1; k <= floors; k++) {
		if (dp[eggs - 1][k - 1] != -1) {
			low = dp[eggs - 1][k - 1];
		}
		else {
			low = eggOptimized(eggs - 1, k - 1);
			dp[eggs - 1][k - 1] = low;
		}
		if (dp[eggs][floors - k] != -1) {
			high = dp[eggs][floors - k];
		}
		else {
			high = eggOptimized(eggs, floors - k);
			dp[eggs][floors - k] = high;
		}
		int temp = 1 + max(low, high); // attempts + max is taken because we have to find the attempts in worst case
		minFloors = min(minFloors, temp);   	//min is used because we have to minimize the attempts
	}

	dp[eggs][floors] = minFloors;
	return dp[eggs][floors];
}

int main(int argc, char const *argv[])
{
	memset(dp, -1, sizeof(dp));
	int t;
	cin >> t;
	while (t--) {
		int k, n;
		cin >> k >> n; //k plates and n floors
		cout << eggRecursive(k, n) << endl;
		cout << eggMemoized(k, n) << endl;
		cout << eggOptimized(k, n) << endl;
	}
	return 0;
}