#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n,m,v;
pair<int,int> a[maxn];
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
int calc(int x)
{
    int ret = binpow(v,x << 1);
    ret = (ret + mod - binpow(v,x)) % mod;
    ret = (ret + binpow(v,x - 1)) % mod;
    return ret;
}
void solve()
{
    scanf("%lld%lld%lld",&n,&m,&v);
    for (int i = 1; i <= m; i++)
        scanf("%lld%lld",&a[i].first,&a[i].second);
    sort(a + 1,a + m + 1);
    int ans = 1;
    for (int i = 2; i <= m; i++)
    {
        if (a[i].first == a[i - 1].first && a[i].second != a[i - 1].second)
        {
            puts("0");
            return;
        }
        else if (a[i].first != a[i - 1].first)
            ans = ans * calc(a[i].first - a[i - 1].first) % mod;
    }
    ans = ans * binpow(v,a[1].first - 1 << 1) % mod;
    ans = ans * binpow(v,n - a[m].first << 1) % mod;
    printf("%lld\n",ans);
}
signed main()
{
    int t,x;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}