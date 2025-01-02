#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 9;
int n,m,c,cnt;
int a[905][905];
int dp[35][35][15];
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&c);
    for (int i = 0; i <= n * m; i++)
        a[i][0] = 1;
    for (int i = 1; i <= n * m; i++)
        for (int j = 1; j <= i; j++)
            a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % mod;
    dp[0][0][0] = 1;
    for (int k = 1; k <= c; k++)
    {
        scanf("%lld",&cnt);
        int tmp[35][35] = {};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i * j < cnt)
                    continue;
                tmp[i][j] = a[i * j][cnt];
                for (int x = 1; x <= i; x++)
                    for (int y = 1; y <= j; y++)
                        if (x < i || y < j)
                            tmp[i][j] = ((tmp[i][j] - tmp[x][y] * a[i][x] % mod * a[j][y] % mod) % mod + mod) % mod;
            }
        }
        #define tx (i - x)
        #define ty (j - y)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                for (int x = 0; x < i; x++)
                    for (int y = 0; y < j; y++)
                        if (tx * ty >= cnt)
                            dp[i][j][k] = (dp[i][j][k] + dp[x][y][k - 1] * tmp[tx][ty] % mod * a[n - x][tx] % mod * a[m - y][ty] % mod) % mod;
        #undef tx
        #undef ty
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = (ans + dp[i][j][c]) % mod;
    printf("%lld",ans);
    return 0;
}