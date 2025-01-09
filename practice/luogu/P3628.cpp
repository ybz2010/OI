#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
const int maxn = 1e6 + 5;
int n,a,b,c;
int sum[maxn],dp[maxn];
int q[maxn],head,tail;
int x(int i){return sum[i];}
int y(int i){return dp[i] + a * sq(sum[i]) - b * sum[i];}
int k(int i){return 2 * a * sum[i];}
long double slope(int i,int j){return (long double)(y(j) - y(i)) / (x(j) - x(i));}
void solve()
{
    scanf("%lld",&n);
    scanf("%lld%lld%lld",&a,&b,&c);
    fill(sum + 1,sum + n + 1,0);
    fill(dp + 1,dp + n + 1,0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",sum + i);
        sum[i] += sum[i - 1];
    }
    head = tail = 1;
    q[1] = 0;
    for (int i = 1,j; i <= n; i++)
    {
        while (tail > head && slope(q[head],q[head + 1]) >= k(i))
            head++;
        j = q[head];
        dp[i] = dp[j] + a * sq(sum[i] - sum[j]) + b * (sum[i] - sum[j]) + c;
        while (tail > head && slope(q[tail - 1],q[tail]) <= slope(q[tail],i))
            tail--;
        q[++tail] = i;
    }
    printf("%lld",dp[n]);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}