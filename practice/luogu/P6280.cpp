#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,mod;
bool ipr[maxn];
int dp[maxn];
basic_string<int>pr;
void prime()
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr.push_back(i);
        for (auto j = pr.begin(); j != pr.end() && i * *j <= n; j++)
        {
            ipr[i * *j] = 1;
            if (i % *j == 0)
                break;
        }
    }
}
signed main()
{
    scanf("%lld%lld",&n,&mod);
    prime();
    dp[0] = 1;
    for (auto i : pr)
    {
        for (int j = n; j >= i; j--)
        {
            int tmp = i;
            while (tmp <= j)
            {
                dp[j] = (dp[j] + dp[j - tmp] * tmp % mod) % mod;
                tmp *= i;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = (ans + dp[i]) % mod;
    printf("%lld",ans);
    return 0;
}