#include <bits/stdc++.h>
using namespace std;

int countWaysRecursive(int n, int m) {
	if (n == 0) {
		return 0;
	}

	if (n < m or n == 1) {
		return 1;
	}

	if ( n == m) {
		return 2;
	}

	int count = 0;

	count += countWaysRecursive(n - 1, m) + countWaysRecursive(n - m, m);

	return count;
}

int countWaysDp(int n, int m) {
	int count[n + 1];

	count[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (i > m) {
			count[i] = count[i - 1] +  count[i - m];
		}

		else if (i < m or i == 1) {
			count[i] =  1;
		}
		else if ( i == m) {
			count[i] =  2;
		}
	}
	return count[n];
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << countWaysDp(n, m) << endl;
	}
	return 0;
}
