#include<bits/extc++.h>
#define int long long
#define inf 0x7fffffffffffffff
typedef double ld;
using namespace std;
const int maxn = 1e6 + 5;
int n;
int d[maxn],p[maxn],c[maxn];
int sum2[maxn],sum1[maxn],dp[maxn];
int q[maxn],tail,head;
int x(int i){return sum1[i];}
int y(int i){return dp[i] + sum2[i];}
int k(int i){return d[i];}
ld slope(int i,int j)
{return ld(x(j) - x(i) == 0 ? (!(y(j) - y(i)) ? 0 : (y(j) - y(i) < 0 ? -inf : inf)) : ld((y(j) - y(i)) * 1.0) / (x(j) - x(i)));}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld",d + i,p + i,c + i);
		sum1[i] = sum1[i - 1] + p[i];
		sum2[i] = sum2[i - 1] + d[i] * p[i];
	}
	tail = head = 1;
	q[1] = 0;
	for (int i = 1,j; i <= n; i++)
	{
		while (head < tail && slope(q[head],q[head + 1]) <= k(i))
			head++;
		j = q[head];
		dp[i] = dp[j] + c[i] + d[i] * (sum1[i] - sum1[j]) - sum2[i] + sum2[j];
		while (head < tail && slope(q[tail - 1],q[tail]) >= slope(q[tail],i))
			tail--;
		q[++tail] = i;
	}
	int ans = dp[n],i = n;
	while (p[i] == 0 && i)
		ans = min(ans,dp[--i]);
	cout << ans;
    return 0;
}
