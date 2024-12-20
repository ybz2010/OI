#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int n,m;
int a[maxn],ls[maxn],rs[maxn];
int st[maxn],top;
void dfs(vector<vector<int> >&dp,int u)
{
    for (int i = 1; i <= m; i++)
        dp[u][i] = 1;
    if (ls[u])
    {
        dfs(dp,ls[u]);
        for (int i = 1; i <= m; i++)
            dp[u][i] = dp[u][i] * dp[ls[u]][i - 1] % mod;
    }
    if (rs[u])
    {
        dfs(dp,rs[u]);
        for (int i = 1; i <= m; i++)
            dp[u][i] = dp[u][i] * dp[rs[u]][i] % mod;
    }
    for (int i = 1; i <= m; i++)
        dp[u][i] = (dp[u][i] + dp[u][i - 1]) % mod;
}
void solve()
{
    cin >> n >> m;
    fill(ls + 1,ls + n + 1,0);
    fill(rs + 1,rs + n + 1,0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    top = 0;
    st[++top] = 1;
    for (int i = 2; i <= n; i++)
    {
        while (top && a[st[top]] < a[i])
            top --;
        if (!top)
            ls[i] = st[top + 1];
        else
        {
            ls[i] = rs[st[top]];
            rs[st[top]] = i;
        }
        st[++top] = i;
    }
    vector<vector<int> >dp(n + 5,vector<int>(m + 5));
    dfs(dp,st[1]);
    cout << dp[st[1]][m] << endl;
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