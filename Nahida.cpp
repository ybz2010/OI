#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 100005;
int q, n;
bool dp[61][1 << 20];
int f[1 << 20];
int shift(int x){return (x >> 1) + ((x & 1) << n - 1);}
int main()
{
    scanf("%d%d", &q, &n);
    const int m = 3 * n;
    memset(f, -1, sizeof f);
    for (int i = 0; i < 1 << n; i++)
    {
        int x = i;
        while (f[x] == -1)
            f[x] = i, x = shift(x);
    }
    dp[0][0] = 1;
    for (int i = 1, z = 0; i <= m; i++)
    {
        z ^= 1 << (i - 1) % n;
        for (int j = 0; j < 1 << n; j++)
        {
            dp[i][f[j]] |= dp[i - 1][f[j ^ z]];
        }
    }
    while (q--)
    {
        int a = 0, b = 0;
        for (int i = n - 1, x; i >= 0; i--)
        {
            scanf("%1d", &x);
            a |= x << i;
        }
        for (int i = n - 1, x; i >= 0; i--)
        {
            scanf("%1d", &x);
            b |= x << i;
        }
        if (a == 0)
        {
            puts("0");
            continue;
        }
        for (int i = 1; ; i++, b = shift(b))
        {
            a ^= b;
            if (dp[i][f[a]])
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}