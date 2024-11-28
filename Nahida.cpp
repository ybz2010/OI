#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T>
void read(T &x)
{
	int res = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		res = (res << 3) + (res << 1) + (ch - '0');
		ch = getchar();
	}
	x = res * f;
}
const int maxn = 1000010;
int n, mid, a[maxn], b[maxn], tmp, ans;
vector<int> v1, v2;
void solve0()
{
	for (int i = 1; i <= n; i++)
		if (a[i] > mid)
			v1.push_back(i);
	for (int i = 1; i <= n; i++)
		if (b[i] <= mid)
			v2.push_back(i);
	for (int i = 0; i < (int)v1.size(); i++)
		ans += abs(v1[i] - v2[i]);
	printf("%lld", ans);
}

void solve1()
{
	for (int i = 1; i <= n; i++)
		if (a[i] >= mid)
			v1.push_back(i);
	for (int i = 1; i <= n; i++)
		if (b[i] <= mid)
			v2.push_back(i);
	for (int i = 0; i < (int)v1.size(); i++)
		tmp += abs(v1[i] - v2[i]);
	v1.clear(), v2.clear();
	for (int i = 1; i <= n; i++)
		if (a[i] > mid)
			v1.push_back(i);
	for (int i = 1; i <= n; i++)
		if (b[i] < mid)
			v2.push_back(i);
	for (int i = 0; i < (int)v1.size(); i++)
		ans += abs(v1[i] - v2[i]);
	printf("%lld", min(tmp, ans));
}

signed main()
{
	// freopen ("pop.in", "r", stdin);
	// freopen ("pop.out", "w", stdout);

	read(n);
	mid = (n + 1) / 2;
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	if (n & 1)
		solve1();
	else
		solve0();
	return 0;
}