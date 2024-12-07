#include<bits/extc++.h>
using namespace std;
const int maxn = 1005;
int n;
vector<int>cnt;
void solve()
{
    scanf("%d",&n);
    cnt.clear();
    cnt.resize(n + 5,0);
    for (int i = 1; i <= n; i++)
    {
        int c;
        scanf("%d",&c);
        cnt[c] ++;
    }
    for (vector<int>::iterator i = cnt.begin(); i != cnt.end();)
    {
        if (*i == 0)
            cnt.erase(i);
        else
            i ++;
    }
    int cnt1 = 0,ans = 0;
    for (auto i : cnt)
        if (i == 1)
            cnt1 ++;
    ans += (cnt1 + 1 >> 1) << 1;
    ans += cnt.size() - cnt1;
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}