#include <bits/extc++.h>
#define int long long
using namespace std;
int idx;
int a[100005], id[100005], pre[100005];
int ipr[100005], p[100005], skip[100005][25];
int read()
{
	int x = 0, f = 1;
	char s = getchar();
	while (s > '9' || s < '0')
	{
		if (s == '-')
			f = -1;
		s = getchar();
	}
	while (s >= '0' && s <= '9')
	{
		x = x * 10 + s - '0';
		s = getchar();
	}
	return x * f;
}
int ask(int x, int R)
{
	int res = 0;
	for (int i = 20; i >= 0; --i)
		if (skip[x][i] && skip[x][i] <= R)
		{
			res += (1 << i);
			x = skip[x][i];
		}
	return res + 1;
}
void makePrime(int N = 100000)
{
	for (int i = 2; i <= N; ++i)
	{
		if (!ipr[i])
		{
			p[++idx] = i;
			id[i] = idx;
		}
		for (int j = 1; j <= idx && i * p[j] <= N; ++j)
		{
			ipr[i * p[j]] = 1;
			if (i % p[j] == 0)
				break;
		}
	}
}
signed main()
{
	makePrime();
	int n = read(), Q = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	for (int i = 1; i <= idx; ++i)
		pre[i] = n + 1;
	for (int j = 0; j <= 20; ++j)
		skip[n + 1][j] = n + 1;
	for (int i = n; i >= 1; --i)
	{
		int tmp = a[i];
		int nxt = n + 1;
		for (int j = 2; j * j <= tmp; ++j)
		{
			if (tmp % j == 0)
			{
				nxt = min(nxt, pre[id[j]]);
				while (tmp % j == 0)
				{
					tmp /= j;
				}
				pre[id[j]] = i;
			}
		}
		if (tmp != 1)
		{
			nxt = min(nxt, pre[id[tmp]]);
			pre[id[tmp]] = i;
		}
		// printf("\n");
		skip[i][0] = min(skip[i + 1][0], nxt);
	}
	for (int i = n; i >= 1; --i)
	{
		for (int j = 1; j <= 20; ++j)
		{
			skip[i][j] = skip[skip[i][j - 1]][j - 1];
		}
	}
	while (Q--)
	{
		int l = read(), r = read(), cnt = 0;
		printf("%lld\n", ask(l, r));
	}
	return 0;
}