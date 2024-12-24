#include<bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;
random_device seed;
mt19937 rnd(seed());
const int maxn = 3e5 + 5;
int n;
int a[maxn],pre[maxn];
vector<int>apr[maxn];
gp_hash_table<int,int>mp;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        apr[i].clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        apr[a[i]].push_back(i);
    }
    memset(pre,0,sizeof pre);
    int sum;
    for (int i = 1; i <= n; i++)
    {
        if (apr[i].empty())
            continue;
        int siz = apr[i].size();
        sum = 0;
        for (int j = 0; j < siz - 1; j++)
        {
            signed x = rnd();
            pre[apr[i][j]] = x;
            sum += x;
        }
        pre[apr[i][siz - 1]] = -sum;
    }
    mp.clear();
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += pre[i];
        ans += mp[sum];
        mp[sum] ++;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}