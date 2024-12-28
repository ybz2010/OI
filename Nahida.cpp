#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define mkp make_pair
#define REP(i, b, e) for (int i = (b); i < (int)(e); ++i)
struct point
{
	int x, y, k;
	bool operator<(point a) { return x == a.x ? y < a.y : x < a.x; }
} a[50005];
int n, k;
int fa[50005], siz[50005];
vector<int> v[50005];
int findfa(int x) { return fa[x] == x ? x : fa[x] = findfa(fa[x]); }
int merge(int x, int y)
{
	x = findfa(x);
	y = findfa(y);
	if (x == y)
		return siz[x];
	siz[x] += siz[y];
	fa[y] = x;
	return siz[x];
}
#define sq(x) ((x) * (x))
int dist(int x, int y) { return sq(a[x].x - a[y].x) + sq(a[x].y - a[y].y); }
bool check(int x)
{
	set<pii> st;
	int idx = -1;
	iota(fa, fa + n, 0);
	REP(i, 0, n)
		siz[i] = 1;
	REP(i, 0, n)
	{
		while (idx + 1 < i && sq(a[i].x - a[idx + 1].x) > x)
			++idx, st.erase(st.find({a[idx].y, idx}));
		for (auto j = st.lower_bound(mkp(a[i].y - ceil(sqrt(x)) - 1,-1)); j != st.end(); j++)
		{
			if (dist(j->second,i) <= x)
            {
                if (merge(i,j->second) >= k)
                    return 1;
            }
		}
		st.insert({a[i].y, i});
	}
	REP(i, 0, n)
	v[i].clear();
	REP(i, 0, n)
	v[findfa(i)].push_back(a[i].k);
	REP(i, 0, n)
	if (fa[i] == i)
	{
		if (fa[i] != i)
            continue;
        bitset<30>b;
        b[0] = 1;
        for (auto j : v[i])
        {
            if (b[k - j])
                return 1;
            b |= (b << j) | (b >> (k - j));
        }
	}
	return 0;
}
void Main()
{
	cin >> n >> k;
	REP(i, 0, n)
		cin >> a[i].x >> a[i].y >> a[i].k,
		a[i].k %= k;
	sort(a, a + n);
	int l = 0, r = 2e16, res = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			res = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	cout << fixed << setprecision(3) << sqrt(res) << endl;
}
void TC()
{
	int tc = 1;
	while (tc--)
	{
		Main();
		cout.flush();
	}
}
signed main()
{;
	return cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), TC(), 0;
}
/*
1. CLEAR the arrays (ESPECIALLY multitests)
2. DELETE useless output
*/