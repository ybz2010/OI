#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, b, s, t, cnt, sum;
int c[16], d[16], f[61][10], l[16], dep[61], head[61], fa[61];
long long mod = 1e9 + 7, ans, g;
struct node
{
	int next, to;
} e[121]; // 链式前向星
void add(int x, int y)
{
	e[++cnt].next = head[x];
	e[cnt].to = y;
	head[x] = cnt;
} // 建边
void dfs(int x, int fa)
{
	f[x][0] = fa;
	dep[x] = dep[fa] + 1;
	for (int i = head[x]; i; i = e[i].next)
	{
		int y = e[i].to;
		if (y != fa)
		{
			dfs(y, x);
		}
	}
} // 用于LCA预处理
int lca(int x, int y)
{
	if (dep[x] < dep[y])
		swap(x, y);
	int p = 6;
	while (~p)
	{
		if (dep[f[x][p]] >= dep[y])
			x = f[x][p];
		p--;
	}
	if (x == y)
		return x;
	p = 6;
	while (~p)
	{
		if (f[x][p] != f[y][p])
			x = f[x][p], y = f[y][p];
		p--;
	}
	return f[x][0];
} // 最近公共祖先的计算
int find(int x)
{
	if (fa[x] != x)
		return fa[x] = find(fa[x]);
	return x;
} // 并查集基本操作
long long ksm(int mi)
{
	long long res = k, ll = 1;
	while (mi)
	{
		if (mi & 1)
			ll = ll * res % mod;
		res = res * res % mod, mi >>= 1;
	}
	return ll;
} // 快速幂
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	dfs(1, 0);
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> c[i] >> d[i];
		l[i] = lca(c[i], d[i]);
	}
	for (int i = 1; i <= m; i++)
		cout << l[i] << " ";
	ans = ksm(n - 1);
	for (int i = 1; i < (1 << m); i++)
	{
		g = 1, sum = 0;
		for (int j = 2; j <= n; j++)
		{
			fa[j] = j;
		} // 并查集初始化
		for (int j = 0; j < m; j++)
		{
			if (i >> j & 1)
			{
				g = -g; // 为了计算容斥时的正负性
				s = c[j + 1];
				while (s != l[j + 1])
				{
					if (f[s][0] == l[j + 1])
						break;
					a = find(s), b = find(f[s][0]);
					if (a != b)
						fa[a] = b; // 合并边
					s = f[s][0];
				} // 从一段跳到LCA
				t = d[j + 1];
				while (t != l[j + 1])
				{
					if (f[t][0] == l[j + 1])
						break;
					a = find(t), b = find(f[t][0]);
					if (a != b)
						fa[a] = b;
					t = f[t][0];
				} // 从另一端跳到LCA
				if (s != l[j + 1] && t != l[j + 1])
				{
					a = find(s), b = find(t);
					if (a != b)
						fa[a] = b;
				} // 如果两者都不是LCA，则LCA下路径中的两条边也应合并到一起
			}
		}
		for (int j = 2; j <= n; j++)
		{
			if (fa[j] == j)
				sum++;
		} // 计算连通块数量
		ans = (ans + g * ksm(sum)) % mod;
	}
	ans = (ans % mod + mod) % mod; // 防止ans变成负数
	cout << ans;
}