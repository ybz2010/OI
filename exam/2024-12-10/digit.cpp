#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
char s[maxn];
int n,d;
int dp[2][maxn];
void solve()
{
    cin >> (s + 1) >> d;
    n = strlen(s + 1);
    memset(dp,0,sizeof dp);
    dp[1][0] = 1;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        for (int j = i + 1; j <= n; j++)
        {
            tmp = (tmp * 10 + s[j] - '0') % d;
            if (tmp == 0)
                dp[1][j] = (dp[1][j] + dp[0][i] + dp[1][i]) % mod;
            else
                dp[0][j] = (dp[0][j] + dp[1][i]) % mod;
        }
    }
    cout << (dp[0][n] + dp[1][n]) % mod << endl;
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