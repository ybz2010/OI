#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,m;
struct edge
{
    int a,v;
}a[maxn];
bool cmp(edge x,edge y){return x.v > y.v;}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld",&a[i].a,&a[i].v);
    sort(a + 1,a + n + 1,cmp);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = min(m,a[i].a);
        m -= tmp;
        ans += tmp * a[i].v;
    }
    printf("%lld",ans);
    return 0;
}