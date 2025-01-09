#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k;
void solve()
{
    scanf("%lld%lld",&n,&k);
    vector<int>a(n + 5,0);
    for (int i = 1; i <= n; i++)
        scanf("%lld",&a[i]);
    sort(a.begin() + 1,a.begin() + n + 1);
    vector<int>cnt;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] ^ a[i - 1])
            cnt.push_back(0);
        cnt.back()++;
    }
    sort(cnt.begin(),cnt.end());
    for (auto i = cnt.begin(); i != cnt.end(); i++)
    {
        if (*i > k)
        {
            printf("%lld\n",cnt.end() - i);
            return;
        }
        k -= *i;
    }
    puts("1");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}