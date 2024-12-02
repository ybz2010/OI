#include<bits/extc++.h>
#define inf 0x7f7f7f7f7f7f
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;
int n,k;
ll a[maxn];
bool check(ll x)
{
    ll ret = 0;
    for (int i = 1; i <= n; i++)
        ret += min(a[i],x);
    return (ret / x >= k);
}
void solve()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    ll l = 1,r = inf,mid,ans = -inf;
    while (l <= r)
    {
        mid = l + r >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}