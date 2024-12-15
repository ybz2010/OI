#include <bits/stdc++.h>
#define rg register
#define il inline
#define co const
template <class T>
il T read()
{
	rg T data = 0, w = 1;
	rg char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (isdigit(ch))
		data = data * 10 + ch - '0', ch = getchar();
	return data * w;
}
template <class T>
il T read(rg T &x)
{
	return x = read<T>();
}
typedef long long ll;

co int mod = 1e7 + 7;
struct data
{
	ll v[3][3];
	data(int x = 0)
	{
		memset(v, 0, sizeof v);
		v[0][0] = v[1][1] = v[2][2] = x;
	}
	ll *operator[](int a) { return v[a]; };
	co ll *operator[](int a) co { return v[a]; };
	data operator*(co data &a) co
	{
		data re;
		for (int k = 0; k < 3; ++k)
			for (int i = 0; i < 3; ++i)
				if (v[i][k])
					for (int j = 0; j < 3; ++j)
						re[i][j] = (re[i][j] + v[i][k] * a[k][j]) % mod;
		return re;
	}
} A;
int a[100001];
data pow(data x, int y)
{
	data re(1);
	while (y)
	{
		if (y & 1)
			re = re * x;
		x = x * x, y >>= 1;
	}
	return re;
}
int main()
{
	//	freopen(".in","r",stdin);
	//	freopen(".out","w",stdout);
	int n = read<int>(), k = read<int>();
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += read(a[i]);
	std::sort(a + 1, a + n + 1);
	if (a[n] <= 0)
		printf("%lld\n", ((sum + (ll)(a[n] + a[n - 1]) * k) % mod + mod) % mod);
	else
	{
		for (sum -= a[n]; k && a[n - 1] < 0; --k)
			a[n - 1] += a[n], sum += a[n - 1];
		A[0][0] = A[0][1] = A[0][2] = A[1][0] = A[2][2] = 1, A = pow(A, k + 1);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				printf("%lld ",A[i][j]);
			putchar('\n');
		}
		printf("%lld\n", ((sum + a[n] * A[0][2] + a[n - 1] * A[1][2]) % mod + mod) % mod);
	}
	return 0;
}