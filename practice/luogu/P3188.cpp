#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,s;
int dp1[60][5000],dp2[60][5000];
vector<int>b[114514],v[114514];
signed solve()
{
    int u,val,tmp;
    for (int i = 0; i < 60; i++)
        b[i].clear(),v[i].clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> u >> val;
        tmp = 0;
        while (!(u & (1 << tmp)))
            tmp ++;
        v[tmp].push_back(val);
        b[tmp].push_back(u >> tmp);
    }
    s = 0;
    while (m >> s)
        s ++;
    memset(dp1,0,sizeof dp1);
    memset(dp2,0,sizeof dp2);
    for (int i = 0; i <= s; i++)
        for (int j = 0; j < b[i].size(); j++)
            for (int k = 500; k >= b[i][j]; k--)
                dp1[i][k] = max(dp1[i][k],dp1[i][k - b[i][j]] + v[i][j]);
    for (int i = 0; i <= s; i++)
        for (int j = 500; j >= 0; j--)
            for (int k = 0; k <= j; k++)
                dp2[i][j] = max(dp2[i][j],dp2[i - 1][((j - k) << 1) + ((m >> (i - 1)) & 1)] + dp1[i][k]);
    return dp2[s - 1][1];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while (~n)  
    {
        cout << solve() << endl;
        cin >> n >> m;
    }
}