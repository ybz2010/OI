#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
// #define int long long
#define pb push_back
#define endl '\n'
using ll = long long;
constexpr ll inf = 1ll << 60;
constexpr ll mod = 998244353;
const int N = 2e5 + 100;

/*
dp[i][j] 代表只包含 [0, i] 的数，且 min(cnt[0], cnt[1], ..., cnt[i]) = j 的子序列数量
显然有 dp[0][j] = C(cnt[0], j)
*/

inline void add(ll &a, ll b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
inline ll mul(ll a, ll b)
{
    a *= b;
    if (a >= mod)
        a %= mod;
    return a;
}
inline ll sub(ll a, ll b)
{
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}
inline ll ksm(ll a, int b)
{
    ll res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
    }
    return res;
}

ll fac[N], inv[N], ifac[N];
inline void comb_init(int n)
{
    fac[0] = 1, fac[1] = 1;
    inv[0] = 0, inv[1] = 1;
    ifac[0] = 1, ifac[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }
}
inline ll C(int n, int m)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int n, a[N];
void solve()
{
    cin >> n;
    vector<int> cnt(n + 10);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    vector<ll> suf(n + 10);
    for (int i = n - 1; i >= 0; --i)
        suf[i] = suf[i + 1] + cnt[i];
    for (int i = 0; i < n; ++i)
        suf[i] = ksm(2, suf[i]);
    vector<vector<ll>> dp(n + 5);
    dp[0].resize(cnt[0] + 1, 0);
    for (int i = 0; i <= cnt[0]; ++i)
        dp[0][i] = C(cnt[0], i);
    vector<ll> suf2(n + 10, 0);
    for (int i = cnt[0]; i >= 0; --i)
        suf2[i] = (suf2[i + 1] + dp[0][i]) % mod;
    int m = cnt[0];
    for (int i = 1; i < n; ++i)
    {
        m = min(m, cnt[i]);
        dp[i].resize(m + 1, 0);
        vector<ll> suf3(cnt[i] + 5, 0);
        for (int j = cnt[i]; j >= 0; --j)
            suf3[j] = (suf3[j + 1] + C(cnt[i], j)) % mod;
        for (int j = 0; j <= m; ++j)
        {
            add(dp[i][j], mul(suf2[j + 1], C(cnt[i], j)));
            add(dp[i][j], mul(suf3[j], dp[i - 1][j]));
        }
        suf2[m + 1] = 0;
        for (int j = m; j >= 0; --j)
            suf2[j] = (suf2[j + 1] + dp[i][j]) % mod;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int sz = dp[i].size();
        for (int j = 1; j < sz; ++j)
            add(ans, mul(mul(dp[i][j], j), (suf[i + 1] == 0 ? 1 : suf[i + 1])));
    }
    cout << ans << endl;
}
signed main(void)
{
    comb_init(200010);
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int Test = 1;
    cin >> Test;
    while (Test--)
        solve();
    return 0;
}
