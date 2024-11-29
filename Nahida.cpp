#include <bits/stdc++.h>
using namespace std;
#define ll long long
int b2[5010][5010], b1[5010][5010];
int n, m, idx;
// b2[i][j]代表第m-i次决策的r后面大于0的数字j 的个数
// b2[i][j]代表第m-i次决策的r后面小于0的数字，绝对值j 的个数
ll dp[5010][5010];
int main()
{
	stack<ll> st;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		ll l;
		scanf("%lld", &l);
		st.push(l);
	}
	while (!st.empty())
	{
		int r = st.top();
		st.pop();
		if (r == 0)
		{
			idx++;
			for (int i = 0; i <= m; ++i)
			{
				b2[idx][i] = b2[idx - 1][i];
				b1[idx][i] = b1[idx - 1][i];
			}
		}
		if (r < 0)
			b1[idx][-r]++;
		if (r > 0)
			b2[idx][r]++;
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if (j - 1 >= 0)
				dp[j][i - j] = max(dp[j][i - j], dp[j - 1][i - j] + b1[m - i][j]);
			if (i - j - 1 >= 0)
				dp[j][i - j] = max(dp[j][i - j], dp[j][i - j - 1] + b2[m - i][i - j]);
		}
	}
	ll mxn = 0;
	for (int i = 0; i <= m; ++i)
		mxn = max(mxn, dp[i][m - i]);
	printf("%lld", mxn);
}