#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll fibBottomUpDp(ll n) {
	ll* dp = new ll[n + 1];
	dp[0] = 1;
	dp[1] = 2;
	for (ll i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main()
{
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << fibBottomUpDp(n) << endl;
	}
	return 0;
}