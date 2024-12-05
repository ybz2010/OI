#include <bits/stdc++.h>
using namespace std;

int n, mm;

long long m[14][15];
long long w[15][4100];
long long dp[15][4100];

// 1 << (i - 1)表示第i位为1
// j & (j - 1)表示把自己所有子集都枚举一遍
// 若j是i的子集,i - j是j的补集
// 1 << n == 2 ^ n 0
// (1 << n) - 1 == 2^0 + 2^1...+2^(n-1)

int main()
{
    memset(dp, 0x3f, sizeof(dp));
    memset(m, 0x3f, sizeof(m));
    memset(w, 0x3f, sizeof(w));
    scanf("%d%d", &n, &mm);

    for (int i = 1; i <= n; i++)
        dp[1][1 << (i - 1)] = 0;
    for (int i = 1; i <= mm; i++)
    {
        int x, y;
        long long z;
        scanf("%d%d%lld", &x, &y, &z);
        m[x][y] = min(z, m[x][y]);
        m[y][x] = m[x][y];
    }

    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= (1 << n) - 1; k++)
            for (int j = 1; j <= n; j++)
                if ((1 << (j - 1) & k) && (!(1 << (i - 1) & k)))
                    w[i][k] = min(w[i][k], m[i][j]);

    long long ans = 0x3f3f3f3f3f3f;
    for (int i = 1; i <= (1 << n) - 1; i++)
    {
        for (int j = i & (i - 1); j != 0; j = i & (j - 1))
        {
            long long nw = 0;
            for (int k = 1; k <= n; k++)
            {
                if (1 << (k - 1) & (i - j))
                {
                    if (w[k][j] > ans)
                        nw = 0x3f3f3f3f3f3f;
                    else
                        nw += w[k][j];
                }
            }
            for (int k = 2; k <= n; k++)
                dp[k][i] = min(dp[k - 1][j] + nw * (k - 1), dp[k][i]);
        }
    }
    for (int i = 2; i <= n; i++)
        ans = min(ans, dp[i][(1 << n) - 1]);
    if (ans >= 0x3f3f3f3f3f3f)
        printf("0\n");
    else
        printf("%lld\n", ans);
}