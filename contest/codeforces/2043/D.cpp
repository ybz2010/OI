#include<bits/extc++.h>
#define int long long
using namespace std;
int L,R,g;
int l,r;
void solve()
{
    cin >> L >> R >> g;
    l = ceil(1.0 * L / g);
    r = floor(1.0 * R / g);
    
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