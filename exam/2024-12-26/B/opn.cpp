#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define mkp(x,y) make_pair(x,y)
using namespace std;
int n;
vector<int>a,ed;
map<pair<vector<int>,int>,int>dp;
int dfs(vector<int>x,int stp)
{
    if (x == ed)
        return stp;
    if (dp[mkp(x,stp)])
        return dp[mkp(x,stp)];
    int ret = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int _min = inf;
            for (int k = i; k <= j; k++)
                _min = min(_min,x[k]);
            if (_min == 0)
                continue;
            vector<int>tmp = x;
            for (int k = i; k <= j; k++)
                tmp[k] -= _min;
            ret = min(ret,dfs(tmp,stp + 1));
        }
    }
    return dp[mkp(x,stp)] = ret;
}
signed main()
{
    scanf("%lld",&n);
    a.resize(n + 5,0);
    ed.resize(n + 5,0);
    for (int i = 1; i <= n; i++)
        scanf("%lld",&a[i]);
    cout << dfs(a,0);
    return 0;
}
//我是stl仙人