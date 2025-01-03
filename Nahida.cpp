#include <bits/stdc++.h>
using namespace std;
#define fk1 500
char *p1, *p2, buf[100000];
#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
int read()
{
	int x = 0, f = 1;
	char ch = nc();
	while (ch < 48 || ch > 57)
	{
		if (ch == '-')
			f = -1;
		ch = nc();
	}
	while (ch >= 48 && ch <= 57)
		x = x * 10 + ch - 48, ch = nc();
	return x * f;
}
vector<int> cir[150001];
vector<long long> pre[150001];
vector<int> big;
int bel[150001];
int a[150001];
long long sum[1001];
int py[150001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n, m, q, op, x, y, l, r;
	long long g(0);
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",bel + i);
		cir[bel[i]].push_back(i);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",a + i);
		if (cir[bel[i]].size() <= fk1)
			sum[i / 400] += a[i];
		pre[bel[i]].push_back((long long)a[i] + (pre[bel[i]].size() ? pre[bel[i]][pre[bel[i]].size() - 1] : 0));
	}
	for (int i = 1; i <= m; ++i)
		if (cir[i].size() > fk1)
			big.push_back(i);
	for (int i = 1; i <= q; ++i)
	{
		scanf("%d%d",&op,&x);
		if (op == 1)
		{
			--x;
			scanf("%d",&y);
			y--;
			g = 0;
			for (int i : big)
			{
				l = lower_bound(cir[i].begin(), cir[i].end(), x) - cir[i].begin();
				r = upper_bound(cir[i].begin(), cir[i].end(), y) - cir[i].begin() - 1;
				if (r < l)
				{
					continue;
				}
				l = (l + py[i]) % cir[i].size();
				r = (r + py[i]) % cir[i].size();
				g = g + pre[i][r];
				if (l)
					g = g - pre[i][l - 1];
				if (l > r)
					g = g + pre[i][pre[i].size() - 1];
			}
			for (; x % 400 && x <= y; ++x)
			{
				if (cir[bel[x]].size() <= fk1)
					g = g + a[x];
			}
			for (; y % 400 < 399 && x <= y; --y)
			{
				if (cir[bel[y]].size() <= fk1)
					g = g + a[y];
			}
			if (x <= y)
				for (; x <= y; x = x + 400)
					g = g + sum[x / 400];
			cout << g << '\n';
		}
		else
		{
			if (cir[x].size() <= fk1)
			{
				if (cir[x].size() >= 2)
				{
					for (int i = 0; i < cir[x].size(); ++i)
						sum[cir[x][i] / 400] -= a[cir[x][i]];
					for (int i = cir[x].size() - 1; i; --i)
						swap(a[cir[x][i]], a[cir[x][i - 1]]);
					for (int i = 0; i < cir[x].size(); ++i)
						sum[cir[x][i] / 400] += a[cir[x][i]];
				}
			}
			else
				py[x] = py[x] > 0 ? py[x] - 1 : py[x] - 1 + cir[x].size();
		}
	}
	return 0;
}