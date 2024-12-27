#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-')
			f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}
const int N = 2e3 + 5, mod = 1e9 + 9;
int fac[N], inv[N];
inline int ksm(int a, int b = mod - 2, int ans = 1)
{
	for (; b; b >>= 1, a = 1ll * a * a % mod)
		if (b & 1)
			ans = 1ll * ans * a % mod;
	return ans;
}
inline void pre()
{
	fac[0] = 1;
	for (int i = 1; i < N; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[N - 1] = ksm(fac[N - 1]);
	for (int i = N - 2; ~i; i--)
		inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
inline int pl(int x)
{
	return x >= mod ? x - mod : x;
}
inline int C(int n, int m)
{
	if (n < m)
		return 0;
	return 1ll * fac[n] * inv[n - m] % mod * inv[m] % mod;
}
int n, cnt[N], num[N], a[N];
int dp[N][N];
signed main()
{
	n = read();
	pre();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		num[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	int len = unique(a + 1, a + n + 1) - a - 1;
	for (int i = 1; i <= len; i++)
		cnt[i] = num[a[i]];
	int sum = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= len; i++)
	{
		sum += cnt[i];
		for (int j = 0; j <= sum; j++)
			for (int k = 0; k <= min(j, cnt[i]); k++)
				dp[i][j] = pl(dp[i][j] + 1ll * dp[i - 1][j - k] * C(sum - j, cnt[i] - k) % mod * C(cnt[i], k) % mod);
		cout << cnt[i] << " ";
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans = pl(ans + pl(((i & 1) ? -1 : 1) * dp[len][i] + mod));
	}
	// printf("%d\n", ans);
	return 0;
}