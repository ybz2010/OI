#include<bits/extc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n,m;
int ans[maxn << 1][maxn];
void solve()
{
    cin >> n >> m;
    if (m >= (n << 1))
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= m; i++)
    {
        int tmp = i;
        for (int j = 1; j <= n; j++)
        {
            ans[tmp][i] = ans[tmp % (n << 1) + 1][i] = j;
            tmp += 2;
            if (tmp > (n << 1))
                tmp -= (n << 1);
        }
    }
    for (int j = 1; j <= (n << 1); j++)
    {
        for (int i = 1; i <= m; i++)
            cout << ans[j][i] << " ";
        cout << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}