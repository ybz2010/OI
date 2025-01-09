#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k;
void solve()
{
    scanf("%lld%lld",&n,&k);
    if (n <= 60 && (1ll << (n - 1)) < k)
    {
        puts("-1");
        return;
    }
    k --;
    vector<bool>d;
    while (k)
    {
        d.push_back(k & 1);
        k >>= 1;
    }
    while (d.size() < n - 1)
        d.push_back(0);
    reverse(d.begin(),d.end());
    vector<int>a,b;
    for (int i = 0; i < n - 1; i++)
    {
        if (!d[i])
            a.push_back(i + 1);
        else
            b.push_back(i + 1);
    }
    reverse(b.begin(),b.end());
    for (auto i : a)
        printf("%lld ",i);
    printf("%lld ",n);
    for (auto i : b)
        printf("%lld ",i);
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}