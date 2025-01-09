#include<bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int maxn = 1005;
int n,m,sc;
int dp[maxn];
gp_hash_table<int,int>id;
vector<pair<int,int>>scc[maxn];
signed main()
{
    scanf("%lld%lld",&m,&n);
    for (int i = 1; i <= n; i++)
    {
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        if (!id[c])
            id[c] = ++sc;
        scc[id[c]].push_back({a,b});
    }
    for (int i = 1; i <= sc; i++)
        for (int k = m; k >= 0; k--)
            for (auto j : scc[i])
                if (k >= j.first)
                    dp[k] = max(dp[k],dp[k - j.first] + j.second);
    cout << dp[m];
    return 0;
}