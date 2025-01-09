#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int n;
int a[maxn],cnt[maxn];
int p2[maxn];
void solve()
{
	scanf("%lld",&n);
	for (int i = 1; i <= n; i++)
		scanf("%lld",a + i);
	priority_queue<int,vector<int>,greater<int>>q;
	fill(cnt + 1,cnt + n + 1,0);
	for (int i = 2,_max = a[1]; i <= n; i++)
	{
		while (!q.empty() && a[i] > q.top())
		{
			q.pop();
			cnt[i]++;
		}
		if (a[i] < _max)
			q.push(a[i]);
		_max = max(_max,a[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt[i] += cnt[i - 1];
		ans = (ans + p2[cnt[i]]) % mod;
	}
	printf("%lld\n",ans);
}
signed main()
{
	p2[0] = 1;
	for (int i = 1; i <= 1e5; i++)
		p2[i] = (p2[i - 1] << 1) % mod;
	int t;
	scanf("%lld",&t);
	while (t--)
		solve();
	return 0;
}