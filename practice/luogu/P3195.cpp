#include<bits/extc++.h>
#define sq(x) ((x) * (x))
#define int long long
typedef long double ld;
using namespace std;
const int maxn = 5e4 + 5;
int n,l;
int c[maxn],sum[maxn],dp[maxn];
int q[maxn],head,tail;
ld x(int i){return sum[i];}
ld y(int i){return dp[i] + sq(sum[i] + l);}
ld k(int i){return (ld)2 * sum[i];}
ld slope(int i,int j){return (y(j) - y(i)) / (x(j) - x(i));}
signed main()
{
    scanf("%lld%lld",&n,&l);
    l++;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",c + i);
        sum[i] = sum[i - 1] + c[i] + 1;
    }
    head = 1,tail = 0;
    q[++tail] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head < tail && slope(q[head],q[head + 1]) <= k(i))
            head++;
        dp[i] = dp[q[head]] + sq(sum[i] - sum[q[head]] - l);
        while (head < tail && slope(q[tail - 1],q[tail]) >= slope(q[tail - 1],i))
            tail--;
        q[++tail] = i;
    }
    printf("%lld",dp[n]);
    return 0;
}