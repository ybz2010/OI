#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
const int maxm = 1e6 + 5;
const int mod = 1e9 + 7;
int n,maxv;
int d,p,lft,cnt2,cnt5,cnt;
int a[maxn],hsh[maxn];
int dp[maxn][2],b0[maxm],b1[maxm];
signed main()
{
    while (1)
    {
        char ch = getchar();
        if (ch == ' ')
            break;
        a[++n] = ch - '0';
    }
    scanf("%lld",&d);
    p = d;
    lft = 1;
    while (p % 2 == 0)
    {
        cnt2++;
        lft *= 2;
        p /= 2;
    }
    while (p % 5 == 0)
    {
        cnt5++;
        lft *= 5;
        p /= 5;
    }
    cnt = max(cnt2,cnt5);
    for (int i = n,p10 = 1; i >= 1; i--,p10 = p10 * 10 % p)
    {
        hsh[i] = (hsh[i + 1] + a[i] * p10) % p;
        maxv = max(maxv,hsh[i]);
    }
    int sum = 1;
    dp[0][1] = 1;
    b0[hsh[1]] = b1[hsh[1]] = cnt == 0 ? 1 : 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = sum;
        bool fl = 1;
        for (int j = 0,tmp = 0,p10 = 1; j < min(i,cnt); j++,p10 = p10 * 10 % d)
        {
            tmp = (tmp + a[i - j] * p10 % d) % d;
            if (!tmp)
            {
                dp[i][0] = ((dp[i][0] - dp[i - j - 1][1]) % mod + mod) % mod;
                dp[i][1] = (dp[i][1] + dp[i - j - 1][0] + dp[i - j - 1][1]) % mod;
            }
            fl = !(tmp % lft);
        }
        if (fl)
        {
            dp[i][0] = ((dp[i][0] - b0[hsh[i + 1]]) % mod + mod) % mod;
            dp[i][1] = (dp[i][1] + b1[hsh[i + 1]]) % mod;
        }
        sum = (sum + dp[i][1]) % mod;
        if (i >= cnt)
        {
            b0[hsh[i - cnt + 1]] = (b0[hsh[i - cnt + 1]] + dp[i - cnt][1]) % mod;
            b1[hsh[i - cnt + 1]] = (b1[hsh[i - cnt + 1]] + dp[i - cnt][0] + dp[i - cnt][1]) % mod;
        }
    }
    printf("%lld",(dp[n][0] + dp[n][1]) % mod);
    return 0;
}