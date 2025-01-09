#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,k;
int h[maxn];
int tr[maxn * 25][2],siz[maxn * 25],id = 1;
void insert(int x)
{
    int p = 1;
    for (int i = 21; i >= 0; i--)
    {
        int ch = (x >> i) & 1;
        if (!tr[p][ch])
            tr[p][ch] = ++id;
        p = tr[p][ch];
        siz[p] ++;
    }
}
int que(int x)
{
    int p = 1,ret = 0;
    bool fl = 0;
    for (int i = 21; i >= 0; i--)
    {
        int chx = (x >> i) & 1;
        int chk = (k >> i) & 1;
        if (chk)
            ret += siz[tr[p][1 - (chx ^ chk)]];
        if (!tr[p][chx ^ chk])
        {
            fl = 1;
            break;
        }
        p = tr[p][chx ^ chk];
    }
    if (!fl)
        ret += siz[p];
    return ret;
}
signed main()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",h + i);
        insert(h[i]);
    }
    int ans = 0;
    for (int i = 0; i < 1 << 21; i++)
    {
        ans = max(ans,que(i));
        if (ans == n)
            break;
    }
    cout << ans;
    return 0;
}