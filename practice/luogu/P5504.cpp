#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
typedef long double ld;
const ld eps = 1e-10;
const int maxn = 1e5 + 5;
int n;
int s[maxn],c[maxn],lst[maxn];
int dp[maxn];
vector<int>st[maxn];
int x(int j){return c[j];}
int y(int j){return dp[j - 1] + s[j] * sq(c[j]);}
int k(int i){return 2 * s[i] * (c[i] + 1);}
ld slope(int i,int j){return ((ld)y(j) - (ld)y(i)) / ((ld)x(j) - (ld)x(i));}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",s + i);
        c[i] = c[lst[s[i]]] + 1;
        lst[s[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + s[i];
        while (st[s[i]].size() > 1 && slope(st[s[i]][st[s[i]].size() - 1],st[s[i]][st[s[i]].size() - 2]) - k(i) < -eps)
            st[s[i]].pop_back();
        if (!st[s[i]].empty())
        {
            int j = st[s[i]].back();
            dp[i] = max(dp[i],dp[j - 1] + s[i] * sq(c[i] - c[j] + 1));
        }
        while (st[s[i]].size() > 1 && slope(st[s[i]][st[s[i]].size() - 2],st[s[i]][st[s[i]].size() - 1]) - slope(st[s[i]][st[s[i]].size() - 2],i) < -eps)
            st[s[i]].pop_back();
        st[s[i]].push_back(i);
    }
    printf("%lld",dp[n]);
    return 0;
}