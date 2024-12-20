#include <bits/stdc++.h>
#define fq(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
#define int long long
inline int rd()
{
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch))
		(ch == '-' ? (f = -1) : 0), ch = getchar();
	int num = 0;
	while (isdigit(ch))
		num = num * 10 + ch - '0', ch = getchar();
	return num * f;
}
#define d rd()

const int maxn = 550;
const int mod = 1e9 + 7;
int n = d, k = d, h[maxn];
int ls[maxn], rs[maxn], sk[maxn], top;
int mul[1001000], invm[1001000];
bool cmp(int a, int b)
{
	return h[a] < h[b];
}
int dp[maxn][maxn], g[maxn], siz[maxn];
void prew(int u)
{
	siz[u] = 1;
	if (ls[u])
		prew(ls[u]), siz[u] += siz[ls[u]];
	if (rs[u])
		prew(rs[u]), siz[u] += siz[rs[u]];
}
int A(int N, int M)
{
	if (M > N)
		return 0;
	return mul[N] * invm[N - M] % mod;
}
int calc(int N, int M, int K)
{
	return A(N, K) * A(M, K) % mod * invm[K] % mod;
}
void dfs2(int u, int hei)
{
	int hu = h[u] - hei;
	if (!ls[u] && !rs[u])
	{
		dp[u][0] = 1;
		fq(i, 1, k) dp[u][i] = calc(siz[u], hu, i);
		return;
	}
	if (!ls[u] || !rs[u])
	{
		int v;
		if (!ls[u])
			v = rs[u];
		else
			v = ls[u];
		dfs2(v, h[u]);
		memset(g, 0, sizeof g);
		g[0] = 1;
		fq(i, 1, k) fq(j, 0, i) g[i] = (g[i] + dp[0][j] * dp[v][i - j]) % mod;
		dp[u][0] = 1;
		fq(i, 1, k) fq(j, 0, i) dp[u][i] = (dp[u][i] + g[j] * calc(hu, siz[u] - j, i - j)) % mod;
		return;
	}
	dfs2(ls[u], h[u]);
	dfs2(rs[u], h[u]);
	memset(g, 0, sizeof g);
	g[0] = 1;
	fq(i, 1, k) fq(j, 0, i) g[i] = (g[i] + dp[ls[u]][j] * dp[rs[u]][i - j]) % mod;
	dp[u][0] = 1;
	fq(i, 1, k) fq(j, 0, i) dp[u][i] = (dp[u][i] + g[j] * calc(hu, siz[u] - j, i - j)) % mod;
}
int power(int a, int b, int p)
{
	int c = 1;
	while (b)
	{
		if (b & 1)
			c = c * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return c;
}
signed main()
{
	mul[0] = invm[0] = 1;
	fq(i, 1, 1000000)
	{
		mul[i] = mul[i - 1] * i % mod;
		invm[i] = invm[i - 1] * power(i, mod - 2, mod) % mod;
	}
	fq(i, 1, n) h[i] = d;
	fq(i, 1, n)
	{
		int kk = top;
		while (kk && h[sk[kk]] > h[i])
			--kk;
		if (kk)
			rs[sk[kk]] = i;
		if (kk != top)
			ls[i] = sk[kk + 1];
		sk[top = ++kk] = i;
	}
	prew(sk[1]);
	dp[0][0] = 1;
	dfs2(sk[1], 0);
	cout << dp[sk[1]][k] << endl;
	return 0;
}