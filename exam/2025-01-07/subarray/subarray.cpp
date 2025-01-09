#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,k;
int sum1,sum2;
int a[maxn];
multiset<int>down;
multiset<int,greater<int>>up;
int calc()
{
    int med = *down.begin();
    return sum2 - med * down.size() + med * up.size() - sum1;
}
void bal()
{
    if (down.size() > up.size() + 1)
    {
        sum1 += *down.begin();
        sum2 -= *down.begin();
        up.insert(*down.begin());
        down.erase(down.begin());
    }
    else if (up.size() > down.size())
    {
        sum1 -= *up.begin();
        sum2 += *up.begin();
        down.insert(*up.begin());
        up.erase(*up.begin());
    }
}
void solve()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        a[i] -= i;
    }
    int ans = 0;
    if (k == 0)
    {
        int _max = 0;
        for (int i = 2; i <= n; i++)
        {
            if (a[i] != a[i - 1])
                _max = 0;
            ans = max(ans,++_max);
        }
    }
    else
    {
        int l = 1,r = 1;
        up.clear(),down.clear();
        sum1 = sum2 = 0;
        for (; r <= n; r++)
        {
            if (down.empty() || a[r] >= *down.begin())
            {
                down.insert(a[r]);
                sum2 += a[r];
            }
            else
            {
                up.insert(a[r]);
                sum1 += a[r];
            }
            bal();
            while (l <= r && calc() > k)
            {
                if (!down.empty() && *down.begin() <= a[l])
                {
                    sum2 -= a[l];
                    down.erase(down.find(a[l]));
                    bal();
                }
                else if(!up.empty())
                {
                    sum1 -= a[l];
                    up.erase(up.find(a[l]));
                    bal();
                }
                l++;
            }
            ans = max(ans,r - l + 1);
        }
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}