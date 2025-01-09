#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
void solve()
{
    cin >> n;
    int ans = 1;
    while (n > 3)
    {
        ans <<= 1;
        n >>= 2;
    }
    cout << ans << endl;
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