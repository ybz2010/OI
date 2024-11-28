#include <bits/stdc++.h>
using namespace std;
#define ll long long
int pot1[5010][5010], pot0[5010][5010];
int n, m, cnt;
// pot1[i][j]代表第m-i次决策的r后面大于0的数字j 的个数
// pot1[i][j]代表第m-i次决策的r后面小于0的数字，绝对值j 的个数
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
		int l = st.top();
		st.pop();

		if (l == 0)
		{
			cnt++;
			for (int i = 0; i <= m; ++i)
			{
				pot1[cnt][i] = pot1[cnt - 1][i];
				pot0[cnt][i] = pot0[cnt - 1][i];
			}
		}
		if (l < 0)
			pot0[cnt][-l]++;
		if (l > 0)
			pot1[cnt][l]++;
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if (j - 1 >= 0)
				dp[j][i - j] = max(dp[j][i - j], dp[j - 1][i - j] + pot0[m - i][j]);
			if (i - j - 1 >= 0)
				dp[j][i - j] = max(dp[j][i - j], dp[j][i - j - 1] + pot1[m - i][i - j]);
		}
	}
	ll mxn = 0;
	for (int i = 0; i <= m; ++i)
		mxn = max(mxn, dp[i][m - i]);
	printf("%lld", mxn);
}