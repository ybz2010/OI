#include<bits/extc++.h>
#define int long long
#define pii pair<int,int>
#define mkp(x,y) make_pair(x,y)
// #define LOCAL
using namespace std;
const int maxn = 1e6 + 5;
int n,k;
char a[maxn],b[maxn];
multiset<pii>st[2];
signed main()
{
    #ifdef LOCAL
    freopen("reedit.in","r",stdin);
    freopen("reedit.out","w",stdout);
    #endif
    scanf("%lld%lld%s%s",&n,&k,a + 1,b + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[i])
            continue;
        int x = (a[i] == '1');
        if (st[!x].empty())
            st[x].insert(mkp(i % k,i));
        else
        {
            auto j = st[!x].lower_bound(mkp(i % k,0));
            if (j == st[!x].end())
                j = st[!x].begin();
            ans += (i - j->second - 1) / k + 1;
            st[!x].erase(j);
        }
    }
    cout << ans;
    #ifdef LOCAL
    fclose(stdout);
    cout << clock();
    #endif
    return 0;
}