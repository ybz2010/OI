#include<bits/extc++.h>
#define int long long
#define vi vector<int>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5,n = 1e6;
const int maxm = 300,m = 290;
int val[maxn];
vi pr,v[maxn];
map<vi,vi>mp;
void prime()
{
    for (int i = 2; i <= n; i++)
    {
        if (!val[i])
        {
            pr.push_back(i);
            val[i] = i;
        }
        for (auto j = pr.begin(); j != pr.end() && *j * i <= n; j++)
        {
            val[*j * i] = *j;
            if (i % *j == 0)
                break;
        }
    }
}
signed main()
{
    prime();
    for (int i = 2; i <= n; i++)
    {
        v[i] = v[i / val[i]];
        if (val[i] != val[i / val[i]])
            v[i].push_back(2);
        else
            v[i].back()++;
    }
    for (int i = 1; i <= n; i++)
        sort(v[i].begin(),v[i].end(),greater<int>());
    mp[v[1]].resize(maxm);
    mp[v[1]][1] = 0;
    for (int i = 2; i <= m; i++)
        mp[v[1]][i] = mp[v[1]][i / val[i]] + val[i] - 1;
    for (int i = 2; i <= n; i++)
    {
        if (mp.count(v[i]))
            continue;
        vi tmp = v[i];
        tmp.pop_back();
        mp[v[i]].resize(maxm);
        for (int j = 1; j <= m; j++)
            mp[v[i]][j] = mp[tmp][j] + v[i].back() - 1;
        for (int j = 1; j <= m; j++)
            for (int k = 1; k * j <= m; k++)    
                mp[v[i]][j * k] = min({mp[v[i]][j * k],mp[tmp][j] + abs(v[i].back() - k),mp[v[i]][j] + k - 1});
    }
    int t,x,y;
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld%lld",&x,&y);
        int ans = inf;
        vi tmp1 = mp[v[x]],tmp2 = mp[v[y]];
        for (int i = 1; i <= m; i++)
            ans = min(ans,tmp1[i] + tmp2[i]);
        printf("%lld\n",ans);
    }
    return 0;
}