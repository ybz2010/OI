#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
typedef long double ld;
const int maxn = 3005;
int n,m;
int dis[maxn];
int dp[maxn][maxn];
int q[maxn],head,tail;
int k(int i){return 2 * m * dis[i];}
int x(int k){return dis[k];}
int y(int k,int j){return dp[k][j - 1] + m * sq(dis[k]) + 2 * dis[k] * dis[n];}
ld slope(int i,int k,int j){return ((ld)y(k,j) - (ld)y(i,j)) / ((ld)x(k) - (ld)x(i));}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",dis + i);
        dis[i] += dis[i - 1];
    }
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int j = 1; j <= m; j++)
    {
        head = tail = 1;
        q[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            while (tail > head && slope(q[head],q[head + 1],j) < k(i))
                head++;
            int k = q[head];
            dp[i][j] = dp[k][j - 1] + m * sq(dis[i] - dis[k]) - 2 * (dis[i] - dis[k]) * dis[n];
            while (tail > head && slope(q[tail - 1],q[tail],j) > slope(q[tail],i,j))
                tail--;
            q[++tail] = i;
        }
    }
    printf("%lld",dp[n][m] + sq(dis[n]));
    return 0;
}