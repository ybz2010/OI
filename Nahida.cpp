#include <bits/stdc++.h>
#define int long long

using namespace std;
inline int read()
{
	int res = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res * f;
}
const int maxn = 5e5 + 10;
int n, v[maxn << 1], sum[maxn << 1];
struct Ayaka
{
	int l, r, val;
} seg[maxn << 4];

inline void pushup(int rt) { seg[rt].val = min(seg[rt << 1].val, seg[rt << 1 | 1].val); }

void Build(int l, int r, int rt)
{
	seg[rt].l = l, seg[rt].r = r;
	if (l == r)
		return;
	int mid = l + r >> 1;
	Build(l, mid, rt << 1), Build(mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

void update(int rt, int pos, int k)
{
	int l = seg[rt].l, r = seg[rt].r;
	if (l == r)
	{
		seg[rt].val = k;
		return;
	}
	int mid = l + r >> 1;
	if (pos <= mid)
		update(rt << 1, pos, k);
	else
		update(rt << 1 | 1, pos, k);
	pushup(rt);
}

int query(int ql, int qr, int rt)
{
	int l = seg[rt].l, r = seg[rt].r;
	if (ql <= l && qr >= r)
		return seg[rt].val;
	int mid = l + r >> 1, tmpVal = 1e9;
	if (ql <= mid)
		tmpVal = min(tmpVal, query(ql, qr, rt << 1));
	if (qr > mid)
		tmpVal = min(tmpVal, query(ql, qr, rt << 1 | 1));
	return tmpVal;
}

signed main()
{
	n = read(), Build(1, n << 1, 1);
	for (int i = 1; i <= n; i++)
		v[i] = read(), v[i + n] = v[i];
	for (int i = 1; i <= (n << 1); i++)
		sum[i] = sum[i - 1] + v[i];
	int len = (n + 1) >> 1, Answer = 0;
	for (int i = 1; i <= (n << 1); i++)
		update(1, i, sum[i + len - 1] - sum[i - 1]);
	for (int i = 1; i <= (n << 1); i++)
		Answer = max(Answer, query(i, i + len - 1, 1));
	printf("%lld\n", Answer);
	return 0;
}