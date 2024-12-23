#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
template <class T>
inline void read(T &n)
{
	n = 0;
	int ch = getchar(), f;
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	f = (ch == '-' ? ch = getchar(), -1 : 1);
	while (ch >= '0' && ch <= '9')
		n = n * 10 + (ch ^ 48), ch = getchar();
	n *= f;
}
int const maxn = 4e5 + 5;
int b[maxn], a[maxn];
int f[maxn][21];
int child[maxn][2], stk[maxn], val[maxn];
int dep[maxn];
int LOG[maxn];
int Mx[maxn * 4], tag[maxn * 4];

void Dfs(int now, int d)
{
	dep[now] = d;
	if (child[now][0])
		Dfs(child[now][0], d + 1);
	if (child[now][1])
		Dfs(child[now][1], d + 1);
}
inline int GetMin(int tl, int tr)
{
	int k = LOG[tr - tl + 1];
	return min(f[tl][k], f[tr - (1 << k) + 1][k]);
}

#define lc (x << 1)
#define rc (x << 1 | 1)
inline void Update(int x) { Mx[x] = max(Mx[lc], Mx[rc]); }
inline void Add(int x, int num) { Mx[x] += num, tag[x] += num; }
inline void Pushdown(int x)
{
	if (tag[x])
		Add(lc, tag[x]), Add(rc, tag[x]), tag[x] = 0;
}
void upd(int x, int tl, int tr, int i, int j, int num)
{
	if (i <= tl && tr <= j)
		return Add(x, num);
	Pushdown(x);
	int mid = (tl + tr) >> 1;
	if (i <= mid)
		upd(lc, tl, mid, i, j, num);
	if (j > mid)
		upd(rc, mid + 1, tr, i, j, num);
	Update(x);
}
int que(int x, int tl, int tr, int i, int j)
{
	if (i <= tl && tr <= j)
		return Mx[x];
	Pushdown(x);
	int mid = (tl + tr) >> 1, re = -1;
	if (i <= mid)
		re = max(re, que(lc, tl, mid, i, j));
	if (j > mid)
		re = max(re, que(rc, mid + 1, tr, i, j));
	return re;
}
#undef lc
#undef rc

int main()
{
	int n;
	read(n);
	LOG[1] = 0;
	for (int i = 2; i <= n + n; ++i)
		LOG[i] = LOG[i >> 1] + 1;
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	for (int i = 1; i <= n; ++i)
		if (a[i] == 1)
		{
			for (int j = 1; j <= n; ++j, i = i % n + 1)
				b[j] = a[i];
			break;
		}
	for (int i = n + 1; i <= n + n; ++i)
		b[i] = b[i - n];
	for (int i = 1; i <= n + n; ++i)
		f[i][0] = b[i];
	for (int k = 1; k <= 19; ++k)
		for (int i = 1; i + (1 << k) - 1 <= n + n; ++i)
			f[i][k] = min(f[i][k - 1], f[i + (1 << (k - 1))][k - 1]);
	/* 构造初始笛卡尔树 */

	int l = n + 1, r = n + n, top = 0;
	for (int i = l; i <= r; ++i)
	{
		int x = b[i];
		while (top && val[top] > x)
			--top;
		if (top)
			child[stk[top]][1] = i;
		child[i][0] = stk[top + 1];
		stk[++top] = i;
		val[top] = x;
		stk[top + 1] = 0;
	}

	Dfs(n + 1, 1);

	for (int i = n + 1; i <= n + n; i++)
		cout << dep[i] << " ";
	for (int i = l; i <= r; ++i)
		upd(1, 1, n + n, i, i, dep[i]);
	int tmp = que(1, 1, n + n, l, r);
	int ans = 0x7f7f7f7f, pos = 0;
	if (tmp < ans)
		ans = tmp, pos = l;
	
	for (int i = n; i > 1; --i)
	{

		/* 删掉最后一个 */
		int del = i + n;
		int tl = l, tr = r - 1, mid, tans;
		while (tl <= tr)
		{
			mid = (tl + tr) >> 1;
			if (GetMin(mid, r) < b[del])
				tans = mid, tl = mid + 1;
			else
				tr = mid - 1;
		}
		upd(1, 1, n + n, tans + 1, del, -1);

		/* 把刚刚删掉的插到第一个 */

		int ins = i;
		tl = l, tr = r - 1;
		while (tl <= tr)
		{
			mid = (tl + tr) >> 1;
			if (GetMin(l, mid) < b[ins])
				tans = mid, tr = mid - 1;
			else
				tl = mid + 1;
		}
		int d = que(1, 1, n + n, tans, tans);
		upd(1, 1, n + n, ins, ins, d);
		upd(1, 1, n + n, ins, tans - 1, 1);

		--l, --r;
		int tmp = que(1, 1, n + n, l, r);
		if (tmp < ans)
			ans = tmp, pos = l;
	}
	int k = b[pos];
	for (int i = 1; i <= n; ++i)
		if (k == a[i])
			printf("%d %d\n", ans, i - 1);

	return 0;
}
