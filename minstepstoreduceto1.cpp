#include<bits/stdc++.h>
using namespace std;
int minstepsto1recursive(int n) {
    if (n == 1) {
        return 0;
    }

    int div3 = INT_MAX;
    int div2 = INT_MAX;
    int sub1 = INT_MAX;

    if (n % 3 == 0) {
        div3 = minstepsto1recursive(n / 3);
    }
    if (n % 2 == 0) {
        div2 = minstepsto1recursive(n / 2);
    }
    sub1 = minstepsto1recursive(n - 1);
    return 1 + min(div3, min(div2, sub1));


}

int minstepsto1topdown(int n) {
    if (n == 1) {
        return 0;
    }

    int div3 = INT_MAX;
    int div2 = INT_MAX;
    int sub1 = INT_MAX;

    if (n % 3 == 0) {
        div3 = minstepsto1topdown(n / 3);
    }
    if (n % 2 == 0) {
        div2  = minstepsto1topdown(n / 2);
    }
    sub1 = minstepsto1topdown(n - 1);

    return 1 + min(div3, min(div2, sub1));
}


int minstepsto1bottomup(int n) {
    int* dp = new int[n + 1];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; ++i)
    {
        int div3 = INT_MAX;
        int div2 = INT_MAX;
        int sub1 = INT_MAX;

        if (i % 3 == 0) {
            div3 = dp[i / 3];
        }
        if (i % 2 == 0) {
            div2  = dp[i / 2];
        }
        sub1 = dp[i - 1];

        dp[i] =  1 + min(div3, min(div2, sub1));
    }
    return dp[n];
}
int main() {
    int n;
    cin >> n;
    cout << minstepsto1recursive(n) << endl;
    cout << minstepsto1topdown(n) << endl;
    cout << minstepsto1bottomup(n);
    return 0;
}