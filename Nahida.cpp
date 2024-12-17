#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxl = 1e6 + 10;
const int mod = 1e9 + 7;

int n, m;
ll k, ans;
int fa[maxl];
vector<int> e[maxl];
ll son[maxl], fac[maxl], inv[maxl], dp1[maxl], dp2[maxl];

inline ll qp(ll a, ll b)
{
	ll ans = 1, cnt = a;
	while (b)
	{
		if (b & 1)
			ans = ans * cnt % mod;
		cnt = cnt * cnt % mod;
		b >>= 1;
	}
	return ans;
}

inline ll c(ll n, ll r)
{
	if (n < 0 || r < 0 || r > n)
		return 0;
	return fac[n] * inv[r] % mod * inv[n - r] % mod;
}

inline void prework()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		e[i].clear(), son[i] = 0;
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &fa[i]);
		e[fa[i]].push_back(i);
		e[i].push_back(fa[i]);
	}
	if (n == 1)
		return;
	k = (m - 1) / 2;
	dp1[1] = c(n - 1, m - 1);
	if (k < 1)
		dp1[1] = 0;
	for (int i = 2; i <= n - 1; i++)
		dp1[i] = ((dp1[i - 1] - (c(i - 2, k - 1) * c(n - i, m - 1 - k) % mod)) % mod + mod) % mod;
	for (int i = 1; i <= n - 1; i++)
	{
		dp2[i] = (i * dp1[i] % mod + dp1[n - i] * (n - i) % mod) % mod;
		if (m % 2 == 0)
			dp2[i] = (dp2[i] + c(i, m / 2) * c(n - i, m / 2) % mod * (m / 2) % mod) % mod;
	}
}

inline void dfs(int u, int fa)
{
	son[u] = 1;
	for (int v : e[u])
	{
		if (v == fa)
			continue;
		dfs(v, u);
		son[u] += son[v];
		ans = (ans + dp2[son[v]]) % mod;
	}
}

inline void mainwork()
{
	ans = 0;
	dfs(1, 0);
}

inline void print()
{
	printf("%lld\n", ans);
}

int main()
{
	fac[0] = 1;
	for (int i = 1; i < maxl; i++)
		fac[i] = fac[i - 1] * i % mod;
	inv[maxl - 1] = qp(fac[maxl - 1], mod - 2);
	for (int i = maxl - 2; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % mod;
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		prework();
		mainwork();
		print();
	}
	return 0;
}