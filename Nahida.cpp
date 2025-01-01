#include <bits/stdc++.h>
using namespace std;
#define fz(i, a, b) for (int i = a; i <= b; i++)
#define int long long
typedef pair<int, int> pii;
inline int read()
{
	int x = 0, neg = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-')
			neg = -1;
		c = getchar();
	}
	while (isdigit(c))
		x = x * 10 + c - '0', c = getchar();
	return x * neg;
}
int n,m;
int val[300005], l[300005], r[300005], a[25], b[25];
const int mod = 998244353;
int fac[300005], inv[300005];
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
inline void init()
{
	fac[0] = 1;
    for (int i = 1; i <= 3e5; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[(int)3e5] = binpow(fac[(int)3e5],mod - 2);
    for (int i = 3e5 - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int f[300005][45];
int C(int n,int m){return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
signed main()
{
	init();
	n = read(), m = read();
	fz(i, 1, n)
	{
		l[i] = read(), r[i] = read();
		val[l[i]]++;
		val[r[i] + 1]--;
	}
	fz(i, 1, n)
		val[i] += val[i - 1];
	fz(i, 1, m) a[i] = read(), b[i] = read();
	fz(j, 0, 30)
		fz(i, 1, n)
			f[i][j] = (f[i - 1][j] + C(val[i] - j, i - j)) % mod;
	int ans = 0;
	for (int k = 0; k < (1 << m); k++)
	{
		int tl = 1, tr = n;
		set<int> st;
		fz(i, 1, m)
		{
			if ((1 << (i - 1)) & k)
			{
				tl = max(tl, l[a[i]]);
				tr = min(tr, r[a[i]]);
				st.insert(a[i]);
				tl = max(tl, l[b[i]]);
				tr = min(tr, r[b[i]]);
				st.insert(b[i]);
			}
		}
		if (tl > tr)
			continue;
		int calc = (f[tr][st.size()] - f[tl - 1][st.size()] + mod) % mod;
		int cnt1 = __builtin_popcount(k);
		if (cnt1 & 1)
			ans = (ans - calc + mod) % mod;
		else
			ans = (ans + calc) % mod;
	}
	cout << ans << endl;
	return 0;
}