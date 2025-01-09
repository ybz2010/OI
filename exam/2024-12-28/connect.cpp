#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define square(x) ((x) * (x))
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
const int maxn = 5e4 + 5;
int n,k;
int fa[maxn],siz[maxn];
vector<int>v[maxn];
struct Nahida{int x,y,k;}a[maxn];
bool operator<(Nahida x,Nahida y){return x.x ^ y.x ? x.x < y.x : x.y < y.y;}
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
int dis(int x,int y) {return square(a[x].x - a[y].x) + square(a[x].y - a[y].y);}
int merge(int x,int y)
{
    x = find(x),y = find(y);
    if (x == y)
        return siz[x];
    siz[x] += siz[y];
    fa[y] = x;
    return siz[x];
}
bool check(int x)
{
    iota(fa + 1,fa + n + 1,1);
    fill(siz + 1,siz + n + 1,1);
    set<pii>st;
    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        while (idx + 1 < i && square(a[idx + 1].x - a[i].x) > x)
        {
            idx ++;
            st.erase(st.lower_bound(mkp(a[idx].y,idx)));
        }
        for (auto j = st.lower_bound(mkp(a[i].y - ceil(sqrt(x)) - 1,-1)); j != st.end(); j++)
        {
            if (dis(j->second,i) <= x)
            {
                if (merge(i,j->second) >= k)
                    return 1;
            }
        }
        st.insert(mkp(a[i].y,i));
    }
    for (int i = 1; i <= n; i++)
        v[i].clear();
    for (int i = 1; i <= n; i++)
        v[find(i)].push_back(a[i].k);
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] != i)
            continue;
        bitset<30>b;
        b[0] = 1;
        for (auto j : v[i])
        {
            if (b[k - j])
                return 1;
            b |= (b << j) | (b >> (k - j));
        }
    }
    return 0;
}
signed main()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].k);
        a[i].k %= k;
    }
    sort(a + 1,a + n + 1);
    int l = 1,r = 1145141919810,mid,ans = inf;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    printf("%.3lf",sqrt(ans));
    return 0;
}