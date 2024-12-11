#include <bits/stdc++.h>
#define int long long

using namespace std;
template <typename T>
inline void read(T &x)
{
	T res = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		res = (res << 1) + (res << 3) + (ch ^ 48);
		ch = getchar();
	}
	x = res * f;
}

const int mod = 1e9 + 7;
int T, n, m, a[1005], dp[1005][1005], apr[1005], tree[1005], len;

int lowbit(int x) { return x & -x; }

void modify(int x, int k)
{
	while (x <= len)
	{
		tree[x] = (tree[x] + k) % mod;
		x += lowbit(x);
	}
}

int query(int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret = (ret + tree[x]) % mod;
		x -= lowbit(x);
	}
	return ret;
}

int __lower_bound(int l, int r, int val)
{
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (apr[mid] == val)
			return mid;
		if (apr[mid] < val)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}

signed main()
{
	read(T);
	int Test = 0;
	while (T--)
	{
		read(n), read(m);
		for (int i = 1; i <= n; i++)
			read(a[i]), apr[i] = a[i];
		sort(apr + 1, apr + n + 1);
		len = unique(apr + 1, apr + n + 1) - (apr + 1);
		for (int i = 1; i <= n; i++)
			dp[i][1] = 1;
		for (int i = 1; i <= n; i++)
			a[i] = __lower_bound(1, len, a[i]);
		for (int j = 2; j <= m; j++)
		{
			memset(tree, 0, sizeof(tree));
			for (int i = 1; i <= n; i++)
			{
				dp[i][j] = query(a[i] - 1);
				modify(a[i], dp[i][j - 1]);
			}
		}
		int Answer = 0;
		for (int i = 1; i <= n; i++)
			Answer = (Answer + dp[i][m]) % mod;
		printf("Case #%lld: %lld\n", ++Test, Answer);
	}
	return 0;
}