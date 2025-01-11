#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a,b,c;
int dp[maxn][3];
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        dp[i][0] = max(dp[i - 1][1],dp[i - 1][2]) + a;
        dp[i][1] = max(dp[i - 1][0],dp[i - 1][2]) + b;
        dp[i][2] = max(dp[i - 1][0],dp[i - 1][1]) + c;
    }
    printf("%lld",max({dp[n][0],dp[n][1],dp[n][2]}));
    return 0;
}