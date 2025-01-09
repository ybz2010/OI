#include <bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
int const maxn = 2e5 + 5;
int n, k, sum, ans, cnt;
struct hash
{
    int operator()(int x){return x * 0xCF32D346 % 0x595C918FB4ACD128;}
};
gp_hash_table<int, int> apr;
vector<int> a, L;
void solve()
{
    scanf("%lld%lld", &n, &k);
    a.clear();
    L.clear();
    apr.clear();
    a.push_back(-114514);
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%lld", &tmp);
        if (!apr[tmp])
            a.push_back(tmp);
        apr[tmp]++;
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < a.size(); i++)
    {
        int tmp = a[i] - a[i-1];
        if(tmp != 1)
            L.push_back(i);
    }
    L.push_back(a.size());
    sum=ans=cnt=0;
    for(int i = 0; i < L.size() - 1; i++)
    {
        int st = L[i];
        int en = L[i + 1] - 1;
        sum = 0;
        for(int j = st; j <= min(en, st + k - 1); j++)
            sum += apr[a[j]];
        ans = max(ans, sum);
        for(int j = st + k; j <= en; j++)
        {
            sum = sum + apr[a[j]] - apr[a[j - k]];
            ans = max(ans, sum);
        }
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld", &t);
    while (t--)
        solve();
    return 0;
}