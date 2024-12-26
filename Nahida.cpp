#include <bits/stdc++.h>
using namespace std;
int dp[1 << 24];
int n, a[25];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    n++;
    for (int i = n; i >= 1; i--)
        a[i] -= a[i - 1];
    for (int i = 1; i < 1 << n; i++)
    {
        long long sum = 0;
        for (int j = 1; j <= n; j++)
            if (i & (1 << (j - 1)))
                sum += a[j];
        dp[i] = -n;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                dp[i] = max(dp[i], dp[i ^ (1 << j)]);
        if (!sum)
            dp[i]++;
    }
    cout << n - dp[(1 << n) - 1] << '\n';
}