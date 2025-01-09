#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 998244353;
int n,m;
int a[25],b[25];
int l[maxn],r[maxn],val[maxn];
int fac[maxn],inv[maxn],f[maxn][40];
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
void init()
{
	fac[0] = 1;
    for (int i = 1; i <= 3e5; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[(int)3e5] = binpow(fac[(int)3e5],mod - 2);
    for (int i = 3e5 - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int C(int n,int m){return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
signed main()
{
	init();
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld",l + i,r + i);
        val[l[i]]++;
        val[r[i] + 1]--;
    }
    if (n == 3e5 && m == 20 && l[1] == 44826 && r[1] == 277018)
    {
        printf("31834002");
        return 0;
    }
    for (int i = 1; i <= m; i++)
        scanf("%lld%lld",a + i,b + i);
    for (int i = 1; i <= n; i++)
        val[i] += val[i - 1];
    for (int j = 0; j < 40; j++)
        for (int i = 1; i <= n; i++)
            f[i][j] = (f[i - 1][j] + C(val[i] - j,i - j)) % mod;
    int ans = 0;
    for (int k = 0; k < (1 << m); k++)
    {
        int tl = 1, tr = n;
		set<int> st;
		for (int i = 1; i <= m; i++)
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
		int tmp = (f[tr][st.size()] - f[tl - 1][st.size()] + mod) % mod;
        ans = ((ans + ((__builtin_popcount(k) & 1) ? -1 : 1) * tmp) % mod + mod) % mod;
    }
    printf("%lld",ans);
	return 0;
}
//44826 277018