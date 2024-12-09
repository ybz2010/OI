#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
char op[105];
int a[105];
int dp[105][105];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= (n << 1); i++)
    {
        if (i & 1)
            cin >> op[i >> 1];
        else
            cin >> a[i >> 1];
    }
    for (int i = 1; i <= n; i++)
        a[i + n] = a[i];
    for (int i = 0; i < n; i++)
        op[i + n] = op[i];
    n <<= 1;
    for (int i = 1; i <= n; i++)
        dp[i][i] = a[i];
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1,j = len; j <= n; i++,j++)
        {
            for (int k = i; k < j; k++)
            {
                if (a[k] == 't')
                    dp[i][j] = max(dp[i][j],dp[i][k] + dp[k + 1][j]);
                else
                    dp[i][j] = max(dp[i][j],dp[i][k] * dp[k + 1][j]);
            }
        }
    }
    vector<int>ans;
    int _max = 0;
    for (int i = 1,j = (n >> 1); j < n; i++,j++)
    {
        if (dp[i][j] > _max)
        {
            ans.clear();
            _max = dp[i][j];
        }
        if (dp[i][j] == _max)
            ans.push_back(i);
    }
    sort(ans.begin(),ans.end());
    cout << _max << endl;
    for (auto i : ans)
        cout << i << " ";
    return 0;
}