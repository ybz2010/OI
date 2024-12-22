#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 4;
int head[N], cnt, n, m, b[N], st[N], top, l[N], r[N];
int d[N], nw[N], sz[N], id[N], cnta, fa[N];
struct edge
{
	int v, nxt;
} a[N << 1];
struct seg
{
	int add, maxn;
} s[N << 2];
int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void pushup(int rt)
{
	s[rt].maxn = max(s[rt << 1].maxn, s[rt << 1 | 1].maxn);
}
void pushdown(int rt)
{
	if (s[rt].add)
	{
		s[rt << 1].add += s[rt].add;
		s[rt << 1 | 1].add += s[rt].add;
		s[rt << 1].maxn += s[rt].add;
		s[rt << 1 | 1].maxn += s[rt].add;
		s[rt].add = 0;
	}
}
void build(int l, int r, int rt)
{
	if (l == r)
	{
		s[rt].maxn = nw[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	pushup(rt);
}
void update(int l, int r, int rt, int L, int R, int w)
{
	if (L <= l && R >= r)
	{
		s[rt].add += w;
		s[rt].maxn += w;
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid)
		update(l, mid, rt << 1, L, R, w);
	if (R > mid)
		update(mid + 1, r, rt << 1 | 1, L, R, w);
	pushup(rt);
}
void modify(int l, int r, int rt, int pos, int w)
{
	if (l == r)
	{
		s[rt].maxn = w;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(rt);
	if (pos <= mid)
		modify(l, mid, rt << 1, pos, w);
	else
		modify(mid + 1, r, rt << 1 | 1, pos, w);
	pushup(rt);
}
int query(int l, int r, int rt, int L, int R)
{
	if (R == 0)
		return 0;
	if (L <= l && R >= r)
		return s[rt].maxn;
	int mid = (l + r) >> 1, res = -0x3f3f3f3f;
	pushdown(rt);
	if (L <= mid)
		res = max(res, query(l, mid, rt << 1, L, R));
	if (R > mid)
		res = max(res, query(mid + 1, r, rt << 1 | 1, L, R));
	return res;
}
void add(int u, int v)
{
	a[++cnt].v = v;
	a[cnt].nxt = head[u];
	head[u] = cnt;
}
void dfs(int u)
{
	id[u] = ++cnta, sz[u] = 1;
	for (int i = head[u]; i != 0; i = a[i].nxt)
	{
		int v = a[i].v;
		dfs(v);
		sz[u] += sz[v];
	}
}
void dfs2(int u, int fa)
{
	d[u] = d[fa] + 1, nw[id[u]] = d[u];
	if (l[u])
		dfs2(l[u], u);
	if (r[u])
		dfs2(r[u], u);
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		b[i] = read(), b[i + n] = b[i];
	int minn = 0x3f3f3f3f, pos = 0;
	for (int i = 1; i <= 2 * n; i++)
	{
		int las = 0;
		while (top > 0 && b[st[top]] >= b[i])
			las = st[top], st[top] = 0, top--;
		r[st[top]] = i;
		l[i] = las;
		st[++top] = i;
		if (b[i] <= minn)
			minn = b[i], pos = i;
	}
	for (int i = 1; i <= 2 * n; i++)
	{
		if (l[i])
			add(i, l[i]);
		if (r[i])
			add(i, r[i]);
	}
	dfs(pos);

	for (int i = 1; i <= top; i++)
		st[i] = 0;
	top = 0;
	for (int i = 1; i <= n; i++)
		l[i] = r[i] = 0;
	minn = 0x3f3f3f3f, pos = 0;
	for (int i = 1; i <= n; i++)
	{
		int las = 0;
		while (top > 0 && b[st[top]] >= b[i])
			las = st[top], st[top] = 0, top--;
		r[st[top]] = i;
		fa[i] = st[top];

		l[i] = las;
		fa[las] = i;

		st[++top] = i;
		if (b[i] <= minn)
			minn = b[i], pos = i;
	}
	dfs2(pos, 0);
	build(1, 2 * n, 1);
	int ans = s[1].maxn, chg = 0;
	for (int i = n + 1; i <= 2 * n; i++)
	{
		modify(1, 2 * n, 1, id[i - n], -0x3f3f3f3f);

		int idx = r[i - n];
		if (idx)
		{
			update(1, 2 * n, 1, id[idx], id[idx] + sz[idx] - 1, -1);
			if (fa[i - n])
			{
				if (idx > fa[i - n])
					r[fa[i - n]] = idx, l[fa[i - n]] = 0;
				else
					l[fa[i - n]] = idx;
			}
			fa[idx] = fa[i - n];
		}

		int las = 0;
		while (top > 0 && b[st[top]] >= b[i])
			las = st[top], st[top] = 0, top--;
		r[st[top]] = i;
		fa[i] = st[top];
		modify(1, 2 * n, 1, id[i], query(1, 2 * n, 1, id[st[top]], id[st[top]]));

		l[i] = las;
		fa[las] = i;

		st[++top] = i;
		if (b[i] <= minn)
			minn = b[i], pos = i;
		update(1, 2 * n, 1, id[i], id[i] + sz[i] - 1, 1);

		if (s[1].maxn < ans)
			ans = s[1].maxn, chg = i - n;
	}
	printf("%d %d\n", ans, chg);
	return 0;
}