#include<iostream>
#include<cstring>
#define max(x,y) (x > y ? x : y)
using namespace std;
int n,b;
int u[4000];
int dp[4000][4000][2];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> u[i];
    memset(dp,-0x3f,sizeof dp);
    dp[1][1][1] = 0;
    dp[1][0][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0][0] = dp[i - 1][0][0];
        for (int j = 1; j <= b; j++)
        {
            dp[i][j][0] = max(dp[i - 1][j][0],dp[i - 1][j][1]);
            dp[i][j][1] = max(dp[i - 1][j - 1][0],dp[i - 1][j - 1][1] + u[i]);
        }
    }
    int ans = max(dp[n][b][0],dp[n][b][1]);
    memset(dp,-0x3f,sizeof dp);
    dp[1][1][1] = u[1];
    dp[1][0][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0][0] = dp[i - 1][0][0];
        for (int j = 1; j <= b; j++)
        {
            dp[i][j][0] = max(dp[i - 1][j][0],dp[i - 1][j][1]);
            dp[i][j][1] = max(dp[i - 1][j - 1][0],dp[i - 1][j - 1][1] + u[i]);
        }
    }
    cout << max(ans,dp[n][b][1]);
    return 0;
}