#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1.5e5 + 5;
int n,m,q;
const int len = 400;
int a[maxn],bel[maxn],sum[maxn],py[maxn];
vector<int>cir[maxn],pre[maxn],big;
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",bel + i);
        cir[bel[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        if (cir[bel[i]].size() <= 500)
            sum[(i - 1) / len + 1] += a[i];
        pre[bel[i]].push_back(a[i] + (pre[bel[i]].empty() ? 0 : pre[bel[i]][pre[bel[i]].size() - 1]));
    }
    for (int i = 1; i <= m; i++)
        if (cir[i].size() > 500)
            big.push_back(i);
    int op,x,y,l,r;
    while (q--)
    {
        scanf("%lld",&op);
        if (op == 1)
        {
            scanf("%lld%lld",&x,&y);
            int ans = 0;
            for (auto i : big)
            {
                l = lower_bound(cir[i].begin(),cir[i].end(),x) - cir[i].begin();
                r = upper_bound(cir[i].begin(),cir[i].end(),y) - cir[i].begin() - 1;
                if (l > r)
                    continue;
                l = (l + py[i]) % cir[i].size();
                r = (r + py[i]) % cir[i].size();
                ans += pre[i][r];
                if (l)
                    ans -= pre[i][l - 1];
                if (l > r)
                    ans += pre[i][pre[i].size() - 1];
            }
            for (; (x - 1) % len && x <= y; x++)
                if (cir[bel[x]].size() <= 500)
                    ans += a[x];
            for (; (y - 1) % len < 399 && x <= y; y--)
                if (cir[bel[y]].size() <= 500)
                    ans += a[y];
            if (x <= y)
                for (; x <= y; x += len)
                    ans = ans + sum[(x - 1) / len + 1];
            printf("%lld\n",ans);
        }
        else
        {
            scanf("%lld",&x);
            if (cir[x].size() <= 500)
            {
                if (cir[x].size() > 1)
                {
                    for (int i = 0; i < cir[x].size(); i++)
                        sum[(cir[x][i] - 1) / len + 1] -= a[cir[x][i]];
                    for (int i = cir[x].size() - 1; i; i--)
                        swap(a[cir[x][i]],a[cir[x][i - 1]]);
					for (int i = 0; i < cir[x].size(); ++i)
						sum[(cir[x][i] - 1) / len + 1] += a[cir[x][i]];
                }
            }
            else
			    py[x] = py[x] > 0 ? py[x] - 1 : py[x] - 1 + cir[x].size();
        }
    }
    return 0;
}