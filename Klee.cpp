#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,ans;
vector<int>a;
map<vector<int>,int>dp;
int dfs(vector<int>v)
{
	if (dp.count(v))
		return dp[v];
	if (v.size() <= 2)
		return 1;
	int ret = 1;
	for (auto i = v.begin() + 1; i != v.end() - 1; i++)
	{
		if (*(i - 1) > *i && *i < *(i + 1))
		{
			int tmp = *i;
			v.erase(i);
			ret = (ret + dfs(v));
			v.insert(i,tmp);
		}
	}
	return dp[v] = ret;
}
void solve()
{
	scanf("%lld",&n);
	a.clear();
	ans = 0;
	for (int i = 1,x; i <= n; i++)
	{
		scanf("%lld",&x);
		a.push_back(x);
		ans = (ans + dfs(a));
	}
	printf("%lld\n",ans);
}
signed main()
{
	int t;
	scanf("%lld",&t);
	while (t--)
		solve();
	return 0;
}