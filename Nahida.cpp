#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e6 + 5;
int n, k, h[N], g[21], pos[21], idx;
ll sum[N], ans;
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + h[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= idx; j++)
            g[j] = __gcd(g[j], h[i]);
        if (g[idx] != h[i])
            g[++idx] = h[i], pos[idx] = i;
        int idx1 = 0;
        for (int j = 1; j <= idx; j++)
            if (g[j] != g[j - 1])
                g[++idx1] = g[j], pos[idx1] = pos[j];
        idx = idx1;
        for (int j = 1; j <= idx; j++)
            if (i - pos[j] + 1 >= k)
                ans = max(ans, g[j] * (sum[i] - sum[pos[j] - 1]));
    }
    cout << ans << endl;
    return 0;
}