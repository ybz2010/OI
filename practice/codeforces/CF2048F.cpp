#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn],b[maxn];
int ls[maxn],rs[maxn];
int st[maxn],top;
int dp[maxn][64];
void dfs(int u)
{
    if (ls[u])
        dfs(ls[u]);
    if (rs[u])
        dfs(rs[u]);
    memset(dp[u],0x3f,sizeof dp[u]);
    int i,j;
    i = j = 0;
    while (i + j < 64)
    {
        int tmp = max(a[u],max(dp[ls[u]][i],dp[rs[u]][j]));
        dp[u][i + j] = min(dp[u][i + j],tmp);
        if (dp[ls[u]][i] > dp[rs[u]][j])
            i ++;
        else
            j ++;
    }
    for (int i = 1; i < 64; i++)
        dp[u][i] = min(dp[u][i],(dp[u][i - 1] - 1) / b[u] + 1);
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= n; j++)
        cin >> b[j];
    fill(ls + 1,ls + n + 1,0);
    fill(rs + 1,rs + n + 1,0);
    st[top = 1] = 1;
    for (int i = 2; i <= n; i++)
    {
        while (top && b[st[top]] > b[i])
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
    dfs(st[1]);
    int ans = 0;
    for (int i = 0; i < 64; i++)
    {
        if (dp[st[1]][i] == 1)
        {
            ans = i;
            break;
        }
    }
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