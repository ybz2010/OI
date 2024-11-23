#include <bits/extc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 998244353;
int randseed;
ll n, m, q;
ll x[maxn],y[maxn],pos[maxn],ans[maxn];
ll t[maxn],u[maxn],v[maxn],id[maxn];
unsigned int rnd()
{
    unsigned int r;
    r = randseed = randseed * 1103515245 + 12345;
    return (r << 16) | ((r >> 16) & 0xFFFF);
}
void init()
{
    cin >> n >> m >> q >> randseed;
    for (int i = 1; i <= m; i++)
    {
        x[i] = rnd() % n + 1;
        y[i] = rnd() % n + 1;
    }
    for (int i = 1; i <= q; i++)
    {
        t[i] = rnd() % m + 1;
        u[i] = rnd() % n + 1;
        v[i] = rnd() % n + 1;
        id[i] = rnd() % n + 1;
    }
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    ll ans = 0;
    for (int i = 1; i <= q; i++)
    {
        for (int j = 1; j <= n; j++)
            pos[j] = j;
        for (int j = 1; j <= m; j++)
        {
            if (j == t[i])
                swap(pos[u[i]],pos[v[i]]);
            else
                swap(pos[x[j]],pos[y[j]]);
        }
        ll tmp = pos[id[i]];
        ans = (ans + tmp * i % mod) % mod;
    }
    cout << ans;
    return 0;
}