#include<bits/extc++.h>
#define int long long
using namespace std;
int l,r;
int a,b,c;
void solve()
{
    scanf("%lld%lld",&l,&r);
    int cnt = 31 - __builtin_clz(l ^ r);
    a = l | ((1 << cnt) - 1);
    b = a + 1;
    c = (a ^ l ? l : r);
    printf("%lld %lld %lld\n",a,b,c);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}