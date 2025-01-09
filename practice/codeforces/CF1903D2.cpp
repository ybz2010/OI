#include<bits/extc++.h>
#pragma GCC optimize(2)
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 1 << 20 | 5;
int n,q,sum;
int a[maxn];
int dp1[20][maxm],dp2[20][maxm];
inline void read(int &x)
{
    x = 0;
    short f(1);
    char ch(getchar());
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
signed main()
{
    read(n),read(q);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        sum += (1 << 20) - a[i];
    }
    for (int i = 19; ~i; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!(a[j] & (1 << i)))
            {
                dp1[i][a[j]]++;
                dp2[i][a[j]] += (a[j] & ((1 << i) - 1));
            }
        }
        for (int j = 0; j < 20; j++)
        {
            for (int k = (1 << 20); ~k; k--)
            {
                if (k & (1 << j))
                {
                    dp1[i][k ^ (1 << j)] += dp1[i][k];
                    dp2[i][k ^ (1 << j)] += dp2[i][k];
                }
            }
        }
    }
    int x;
    while (q--)
    {
        read(x);
        int ans = 0,idx = 0;
        if (x >= sum)
        {
            printf("%lld",(1 << 20) + (x - sum) / n);
            goto end;
        }
        for (int i = 19; ~i; i--)
        {
            int tmp = idx * (1 << i) + dp1[i][ans] * (1 << i) - dp2[i][ans];
            if (x >= tmp)
            {
                idx += dp1[i][ans];
                ans += (1 << i);
                x -= tmp;
            }
        }
        printf("%lld",ans);
        end : putchar('\n');
    }
    return 0;
}