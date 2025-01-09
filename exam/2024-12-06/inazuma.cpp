#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n;
bool ipr[maxn];
int dp[maxn],pr[maxn],idx;
void prime()
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr[++idx] = i;
        for (int j = 1; j <= idx && pr[j] * i <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
}
signed main()
{
    scanf("%lld",&n);
    prime();
    dp[0] = 1;
    for (int i = 1; i <= idx; i++)
        for (int j = n; j >= pr[i]; j--)
            for(int k = pr[i]; k <= j; k *= pr[i])
                dp[j] = (dp[j] + dp[j - k] * k) % mod;
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = (ans + dp[i]) % mod;
    printf("%lld",ans % mod);
    return 0;
}