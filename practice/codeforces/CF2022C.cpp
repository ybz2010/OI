#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int dp[maxn][3],v[maxn][2];
void solve()
{
    scanf("%d",&n);
    memset(v,0,sizeof v);
    for (int j = 0; j < 2; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            char ch;
            cin >> ch;
            v[i][j] = (ch == 'A');
        }
    }
    memset(dp,0,sizeof dp);
    int vote;
    for (int i = 0; i < n; i++)
    {
        vote = (v[i + 1][0] + v[i + 2][0] + v[i + 3][0]) / 2 + (v[i + 1][1] + v[i + 2][1] + v[i + 3][1]) / 2;
        dp[i + 3][0] = max(dp[i + 3][0],dp[i][0] + vote);
        vote = (v[i + 1][0] + v[i + 2][0] + v[i + 1][1]) / 2;
        dp[i + 1][1] = max(dp[i + 1][1],dp[i][0] + vote);
        vote = (v[i + 1][1] + v[i + 2][1] + v[i + 1][0]) / 2;
        dp[i + 1][2] = max(dp[i + 1][2],dp[i][0] + vote);

        vote = (v[i + 2][0] + v[i + 3][0] + v[i + 4][0]) / 2 + (v[i + 1][1] + v[i + 2][1] + v[i + 3][1]) / 2;
        dp[i + 3][1] = max(dp[i + 3][1],dp[i][1] + vote);
        vote = (v[i + 1][1] + v[i + 2][1] + v[i + 2][0]) / 2;
        dp[i + 2][0] = max(dp[i + 2][0],dp[i][1] + vote);
        
        vote = (v[i + 1][0] + v[i + 2][0] + v[i + 3][0]) / 2 + (v[i + 2][1] + v[i + 3][1] + v[i + 4][1]) / 2;
        dp[i + 3][2] = max(dp[i + 3][2],dp[i][2] + vote);
        vote = (v[i + 1][0] + v[i + 2][0] + v[i + 2][1]) / 2;
        dp[i + 2][0] = max(dp[i + 2][0],dp[i][2] + vote);
    }
    printf("%d\n",dp[n][0]);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}