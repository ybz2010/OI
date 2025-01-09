#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = (1 << 18) + 5;
const int mod = 998244353;
int n,m;
int u[400],v[400];
int dp[maxn];
bool vis[maxn];
void read(int &x)
{
    x = 0;
    int f(1);
    char ch(getchar());
    while (!isdigit(ch)){f = (ch == '-' ? -1 : 1); ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
signed main()
{
    read(n),read(m);
    if (!m)
    {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= m; i++)
        read(u[i]),read(v[i]);
    dp[0] = 1;
    for (int k = 1; k < (1 << n); k++)
    {
        for (int i = 1; i <= m; i++)
        {
            if ((k & (1 << (u[i] - 1))) && (k & (1 << (v[i] - 1))))
            {
                vis[k] = 1;
                break;
            }
        }
    }
    for (int i = 1; i < (1 << n); i++)
        for (int j = i; j; j = i & (j - 1))
            if (!vis[j])
                dp[i] = (dp[i] + dp[i ^ j] * (((__builtin_popcount(j)) & 1) ? 1 : -1) + mod) % mod;
    int ans = dp[(1 << n) - 1] * m % mod * 499122177 % mod;
    printf("%lld",ans);
    return 0;
}