#include <bits/stdc++.h>
namespace SXL {
	using std::max;
	using std::min;
	using std::cin;
	using ll = int;
	constexpr int MAXN = 200;
	char op[MAXN];
	int num[MAXN];
	ll dp[MAXN * 2][MAXN * 2];
	int g[MAXN * 2][MAXN * 2];
	void main() {
		memset(dp,0xc0,sizeof(dp));
		memset(g,0x3f,sizeof(g));
		int n;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++) {
			cin >> op[i];
			scanf("%d",num + i);
			op[i + n] = op[i];
			num[i + n] = num[i];
		}
		for(int i = 1;i <= 2 * n;i++) {
			dp[i][i] = num[i];
			g[i][i] = num[i];
		}
		for(int k = 2;k <= n;k++) {
			for(int i = 1;i + k - 1 <= 2 * n;i++) {
				int r = i + k - 1;
				for(int j = i + 1;j <= r;j++) {
					if(op[j] == 't') {
						dp[i][r] = max(dp[i][r],dp[i][j - 1] + dp[j][r]);
						g[i][r] = min(g[i][r],g[i][j - 1] + g[j][r]);
					} else {
						dp[i][r] = max(dp[i][r],
								   max(dp[i][j - 1] * dp[j][r],
								   max(g[i][j - 1] * g[j][r],
								   max(dp[i][j - 1] * g[j][r],
								   	   g[i][j - 1] * dp[j][r]))));
						g[i][r] = min(dp[i][r],
								  min(dp[i][j - 1] * dp[j][r],
								  min(g[i][j - 1] * g[j][r],
								  min(dp[i][j - 1] * g[j][r],
								   	   g[i][j - 1] * dp[j][r]))));
					}
				}
			}
		}
		ll ans = -0x3f3f3f3f;
		for(int i = 1;i <= n;i++) {
			ans = max(ans,dp[i][i + n - 1]);
		}
		printf("%d\n",ans);
		for(int i = 1;i <= n;i++) {
			if(dp[i][i + n - 1] == ans) printf("%d ",i);
		}
		puts("");
	}
}
int main() {
	SXL::main();
	return 0;
}