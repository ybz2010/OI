#include <bits/stdc++.h>
#define ll long long
#define L ls[T]
#define R rs[T]
using namespace std;

const ll maxn = 2e7, P = 1e18 + 4e5;

int ls[maxn], rs[maxn], tot = 1;
ll v[maxn];

ll q (int T, ll l, ll r, ll x) {
	v[T]--;
	if (l == r) return x;
	
	ll m = (l + r) >> 1;
	if (!L) L = ++tot, v[L] = m - l + 1;
	if (!R) R = ++tot, v[R] = r - m;
	
	if (v[L] >= x) return q (L, l, m, x);
	return m - l + 1 + q (R, m + 1, r, x - v[L]);
}

ll w (int y, int x) {
	if (x == 0 && y == 0) return 1;
	ll p = max (abs (x), abs (y)), res = (2 * p - 1) * (2 * p - 1);
	if (x == p && y != -p) return res + p + y;
	if (y == p) return res + 3 * p - x;
	if (x == -p) return res + 5 * p - y;
	return res + 7 * p + x;
}

int main () {
	v[1] = P;
	ll p, x, y;
	scanf("%lld", &p);
	while (p--) {
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", q (1, 1, P, w (x, y)));
	}
}