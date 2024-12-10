#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 100005;
const int mod = 1e9 + 7;
char s[maxn];
int n,d;
int dp[maxn];
void solve()
{
    cin >> (s + 1) >> d;
    n = strlen(s + 1);
    memset(dp,0,sizeof dp);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int x = 0,tmp = 0;
        for (int j = i; j >= 1; j--)
        {
            tmp = (int)(tmp + (s[j] - '0') * pow(10,x++));
            if (tmp % d == 0)
                dp[i] = (dp[i] + dp[j - 1]) % mod;
        }
        cout << dp[i] << " ";
    }
    cout << dp[n] << endl;
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