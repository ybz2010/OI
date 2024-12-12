#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k;
string s;
void solve()
{
    scanf("%lld%lld",&n,&k);
    cin >> s;
    vector<int>a(n,0);
    for (int i = n - 1; i; i--)
        a[i - 1] = a[i] + (s[i] == '1' ? 1 : -1);
    a.pop_back();
    sort(a.begin(),a.end(),greater<int>());
    int ans = 1,sum = 0;
    for (auto i : a)
    {
        if (sum >= k)
            break;
        sum += i;
        ans ++;
    }
    if (sum < k)
        puts("-1");
    else
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