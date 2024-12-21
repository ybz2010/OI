#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 998244353;
int n;
int p[maxn],st[maxn],top;
int ls[maxn],rs[maxn];
void dfs(vector<int>&dp,int u,int fl)
{
    if (ls[u])
        dfs(dp,ls[u],fl | 0b01);
    if (rs[u])
        dfs(dp,rs[u],fl | 0b10);
    dp[u] = (dp[u] + dp[rs[u]] * dp[ls[u]] % mod) % mod;
    if (fl & 0b01)
        dp[u] = (dp[u] + dp[ls[u]]) % mod;
    if (fl & 0b10)
        dp[u] = (dp[u] + dp[rs[u]]) % mod;
    if (fl == 0b11)
        dp[u] = (dp[u] - 1 + mod) % mod;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    fill(ls + 1,ls + n + 1,0);
    fill(rs + 1,rs + n + 1,0);
    top = 0;
    st[++top] = 1;
    for (int i = 2; i <= n; i++)
    {
        while (top && p[st[top]] > p[i])
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
    vector<int>dp(n + 5);
    dp[0] = 1;
    if (ls[st[1]])
        dfs(dp,ls[st[1]],0b01);
    if (rs[st[1]])
        dfs(dp,rs[st[1]],0b10);
    cout << dp[ls[st[1]]] * dp[rs[st[1]]] % mod << endl;
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