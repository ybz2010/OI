#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e6 + 5;
int n, k, h[N], g[N][21], lg[N];
ll sum[N], ans;
inline int gcd(int l, int r)
{
    int k = lg[r - l + 1];
    return __gcd(g[l][k], g[r - (1 << k) + 1][k]);
}
inline ll solve(int r)
{
    int l = 1;
    ll res = 0;
    while (l <= r - k + 1)
    {
        const int glr = gcd(l, r);
        res = max(res, glr * (sum[r] - sum[l - 1]));
        if (glr == h[r])
            break;
        int L = l + 1, R = r, pos = r;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (gcd(mid, r) > glr)
                pos = mid, R = mid - 1;
            else
                L = mid + 1;
        }
        l = pos;
    }
    return res;
}
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + h[i];
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; i++)
        g[i][0] = h[i];
    for (int j = 1; j <= lg[n]; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            g[i][j] = __gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
    for (int i = k; i <= n; i++)
        ans = max(ans, solve(i));
    cout << ans << endl;
    return 0;
}