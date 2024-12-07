#include<bits/extc++.h>
#define float double
#define pff pair<float,float>
using namespace std;
const int maxn = (1 << 18) + 5;
const float eps = 1e-8;
int n,m;
int low[maxn],vis[20][20];
int dp[maxn];
float x[20],y[20];
pff LuoHuan(float x1,float y1,float z1,float x2,float y2,float z2)
{
    pff ret;
    ret.second = (x1 * z2 - x2 * z1) / (x1 * y2 - x2 * y1);
    ret.first = (z1 - y1 * ret.second) / x1;
    return ret;
}
void solve()
{
    memset(vis,0,sizeof vis);
    memset(dp,0x3f,sizeof dp);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf",x + i,y + i);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (abs(x[i] - x[j]) < eps)
                continue;
            pff tmp = LuoHuan(x[i]*x[i],x[i],y[i],x[j]*x[j],x[j],y[j]);
            if (tmp.first > -eps)
                continue;
            for (int k = 1; k <= n; k++)
                if (abs(x[k] * x[k] * tmp.first + x[k] * tmp.second - y[k]) < eps)  
                    vis[i][j] |= (1 << (k - 1));
        }
    }
    dp[0] = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        int j = low[i];
        dp[i | (1 << (j - 1))] = min(dp[i | (1 << (j - 1))],dp[i] + 1);
        for (int k = 1; k <= n; k++)
            dp[i | vis[j][k]] = min(dp[i | vis[j][k]],dp[i] + 1);
    }
    printf("%d\n",dp[(1 << n) - 1]);
}
signed main()
{
    for (int i = 0; i < (1 << 18); i++)
    {
        int j = 1;
        while (j <= 18 && (i & (1 << (j - 1))))
            j ++;
        low[i] = j;
    }
    int t;
    scanf("%d",&t);
    while (t --)
        solve();
    return 0;
}