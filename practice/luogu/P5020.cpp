#include<bits/extc++.h>
using namespace std;
int n;
int a[105];
int dp[25000005];
void solve()
{
    cin >> n;
    memset(a,0,sizeof a);
    memset(dp,0,sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[a[i]] = 2;
    }
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= a[n]; i++)
    {
        if (!dp[i])
            continue;
        for (int j = 1; j <= n && i + a[j] <= a[n]; j++)
            dp[i + a[j]] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= a[n]; i++)
        ans += (dp[i] == 2);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}