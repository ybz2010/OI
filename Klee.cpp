#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;
const int MM = 436;
int n, m;
bool vis[MM];
map<vector<int>, int> f[MM][MM];
int dfs(vector<int> v, int x, int y)
{
	if (y < 0)
		return 0;
	if (x > m)
		return 1;
	if (f[x][y].count(v))
		return f[x][y][v];
	if (!vis[x])
		return f[x][y][v] = 1ll * y * dfs(v, x + 1, y - 1) % mod;
	int res = 0, lim = v.size();
	vector<int> tmp;
	for (int i = 1; i < lim; i++)
		for (int j = 0; j < i; j++)
		{
			tmp.clear();
			for (int k = 0; k < lim; k++)
				if (k != i && k != j)
					tmp.push_back(v[k]);
			tmp.push_back(v[i] + v[j]);
			sort(tmp.begin(), tmp.end());
			res = (res + 1ll * v[i] * v[j] * dfs(tmp, x + 1, y + v[i] * v[j] - 1) % mod) % mod;
		}
	return f[x][y][v] = res;
}
int main()
{
	scanf("%d", &n);
	m = n * (n - 1) / 2;
	for (int i = 1, x; i < n; i++)
		scanf("%d", &x), vis[x] = true;
	printf("%d\n", dfs(vector<int>(n, 1), 1, 0));
	return 0;
}