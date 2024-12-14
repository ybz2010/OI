#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n;
int a[maxn],pre[maxn];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int len = (n >> 1) + 1;
    int _max = 0,ans = pre[n];
    for (int l = 1; l + len - 1 <= n; l++)
    {
        int r = (l + len - 1);
        int sum = pre[l - 1] + pre[n] - pre[r];
        if (sum > _max)
        {
            _max = sum;
            ans = pre[n] - sum;
        }
    }
    cout << ans << " " << _max << endl;
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