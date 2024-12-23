#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,x,y;
int ans[maxn];
void solve()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
        ans[(x + i - 1) % n + 1] = (i & 1);
    if ((n & 2) || !((x - y) & 1))
        ans[x] = 2;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
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