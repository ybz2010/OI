#include<bits/extc++.h>
#define ll long long
using namespace std;
const int maxm = 5010;
int n,m;
ll dp[maxm][maxm];
int b1[maxm][maxm],b2[maxm][maxm],idx;
signed main()
{
    scanf("%d%d",&n,&m);
    stack<ll>st;
    for (int i = 1; i <= n; i++)
    {
        int r;
        scanf("%d",&r);
        st.push(r);
    }
    while (!st.empty())
    {
        int r = st.top();
        st.pop();
        if (r == 0)
        {
            idx ++;
            for (int i = 0; i <= m; i++)
            {
                b1[idx][i] = b1[idx - 1][i];
                b2[idx][i] = b2[idx - 1][i];
            }
        }
        if (r < 0)
            b1[idx][-r] ++;
        if (r > 0)
            b2[idx][r] ++;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j - 1 >= 0)
                dp[j][i - j] = max(dp[j][i - j],dp[j - 1][i - j] + b1[m - i][j]);
            if (i - j - 1 >= 0)
                dp[j][i - j] = max(dp[j][i - j],dp[j][i - j - 1] + b2[m - i][i - j]);
        }
    }
    ll _max = 0;
    for (int i = 0; i <= m; i++)
        _max = max(_max,dp[i][m - i]);
    cout << _max;
    return 0;
}