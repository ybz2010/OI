#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
using namespace std;
#define MAXN 125
#define P 1000000000
typedef long long ll;
ll n, t, k;

struct matrx
{
    ll a[MAXN][MAXN];
} G[70], tmp, cur;

bool work(matrx &a)
{
    ll p = 0;
    for (ll i = 1; i <= n; ++i)
        if ((k <= (p += a.a[i][0] - 1)))
            return true;
    return false;
}

void mul(matrx &x, matrx &y)
{
    for (ll i = 0; i <= 3 * n; ++i)
        for (ll j = 0; j <= 3 * n; ++j)
        {
            tmp.a[i][j] = 0;
            for (ll p = 0; p <= 3 * n; ++p)
                tmp.a[i][j] += x.a[i][p] * y.a[p][j];
        }
}

int main()
{
    ll m;
    cin >> n >> m >> k;
    G[0].a[0][0] = 1;
    for (ll i = 1; i <= n; ++i)
        cur.a[i][i] = G[0].a[i][0] = G[0].a[i][i + n] = G[0].a[i + n][i + 2 * n] = 1;
    for (ll i = 0, u, v, w; i < m; ++i)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        ++G[0].a[u + (w - 1) * n][v];
    }
    ll i;
    for (i = 1;; ++i)
    {
        if (i > 65)
            return puts("-1"), 0;
        mul(G[i - 1], G[i - 1]), G[i] = tmp;
        if (work(G[i]))
            break;
    }
    long long ans = 0;
    for (i--; ~i; --i)
    {
        mul(cur, G[i]);
        if (!work(tmp))
            cur = tmp, ans += (1ll << i);
    }
    cout << ans;
}
// qwq