#include<bits/extc++.h>
using namespace std;
int n,m,max1;
int dp[20][600005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int l,r;
        cin >> l >> r;
        max1 = max(max1,r);
        dp[0][l] = max(dp[0][l],r); 
    }
    for (int i = 1; i <= max1; i++)
        dp[0][i] = max(dp[0][i],dp[0][i - 1]);
    for (int i = 1; i < 20; i++)
        for (int j = 0; j <= max1; j++)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
    while (m--)
    {
        int l,r,cnt = 1;
        cin >> l >> r;
        for (int i = 19; i >= 0; i--)
        {
            if (dp[i][l] && dp[i][l] < r)
            {
                l = dp[i][l];
                cnt += (1 << i);
            }
        }
        if (dp[0][l] < r)
            cout << "-1\n";
        else
            cout << cnt << endl;
    }
    return 0;
}