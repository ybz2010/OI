#include<bits/extc++.h>
using namespace std;
const int maxn = 55;
int n,m;
int a[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d",&a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int x = 1; x <= n; x++)
                for (int y = j + 1; y <= m; y++)
                    dp[i][j][x][y] = max(max(dp[i][j - 1][x - 1][y],dp[i - 1][j][x][y - 1]),max(dp[i - 1][j][x - 1][y],dp[i][j - 1][x][y - 1])) + a[i][j] + a[x][y];
    cout << dp[n][m - 1][n - 1][m];
    return 0;
}