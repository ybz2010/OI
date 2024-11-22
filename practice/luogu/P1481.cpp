#include<bits/extc++.h>
using namespace std;
const int maxn = 2005;
int n;
char s[maxn][80];
int dp[maxn];
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%s",s[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (strstr(s[i],s[j]) == s[i])
                dp[i] = max(dp[i],dp[j] + 1);
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}