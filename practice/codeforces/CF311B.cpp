#include<bits/extc++.h>
#define int long long
using namespace std;
typedef long double ld;
const int maxn = 1e5 + 5;
int n,m,p;
int dis[maxn],sum[maxn],t[maxn];
int dp[105][maxn],q[maxn],head,tail;
int x(int k){return k;}
int y(int k,int i){return sum[k] + dp[i - 1][k];}
int K(int j){return t[j];}
ld slope(int j,int k,int i){return ((ld)y(k,i) - (ld)y(j,i)) / ((ld)x(k) - (ld)x(j));}
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&p);
    for (int i = 2; i <= n; i++)
    {
        scanf("%lld",dis + i);
        dis[i] += dis[i - 1];
    }
    for (int i = 1,x; i <= m; i++)
    {
        scanf("%lld%lld",&x,t + i);
        t[i] -= dis[x];
    }
    sort(t + 1,t + m + 1);
    for (int i = 1; i <= m; i++)
        sum[i] = sum[i - 1] + t[i];
    for (int i = 1; i <= m; i++)
        dp[1][i] = t[i] * i - sum[i];
    int ans = dp[1][m];
    for (int i = 2; i <= p; i++)
    {
        head = tail = 1;
        q[1] = 0;
        for (int j = 1; j <= m; j++)
        {
            while (head < tail && slope(q[head],q[head + 1],i) < K(j))
                head++;
            int k = q[head];
            dp[i][j] = dp[i - 1][k] + (j - k) * t[j] - (sum[j] - sum[k]);
            while (head < tail && slope(q[tail - 1],q[tail],i) > slope(q[tail],j,i))
                tail--;
            q[++tail] = j;
        }
        ans = min(ans,dp[i][m]);
    }
    printf("%lld",ans);
    return 0;
}