#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int n;
char op[105];
int a[105];
int dp1[105][105],dp2[105][105];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op[i] >> a[i];
        op[i + n] = op[i];
        a[i + n] = a[i]; 
    }   
    for (int i = 1; i <= (n << 1); i++)
    {
        for (int j = 1; j <= (n << 1); j++)
        {
            dp1[i][j] = -inf;
            dp2[i][j] = inf;
        }
    }
    for (int i = 1; i <= (n << 1); i++)
        dp1[i][i] = dp2[i][i] = a[i];
    for (int len = 2; len <= n; len ++)
    {
        for (int i = 1; i + len - 1 <= (n << 1); i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                if (op[k + 1] == 't')
                {
                    dp1[i][j] = max(dp1[i][j],dp1[i][k] + dp1[k + 1][j]);
                    dp2[i][j] = min(dp2[i][j],dp2[i][k] + dp2[k + 1][j]);
                }
                else
                {
                    dp1[i][j] = max(dp1[i][j],max(max(dp1[i][k] * dp1[k + 1][j],dp2[i][k] * dp2[k + 1][j]),max(dp1[i][k] * dp2[k + 1][j],dp2[i][k] * dp1[k + 1][j])));
                    dp2[i][j] = min(dp2[i][j],min(min(dp1[i][k] * dp1[k + 1][j],dp2[i][k] * dp2[k + 1][j]),min(dp1[i][k] * dp2[k + 1][j],dp2[i][k] * dp1[k + 1][j])));
                }
            }
        }
    }
    int _max = -inf;
    for (int i = 1; i <= n; i++)
        _max = max(_max,dp1[i][i + n - 1]);
    cout << _max << endl;
    for (int i = 1; i <= n; i++)
        if (dp1[i][i + n - 1] == _max)
            cout << i << " ";
    return 0;
}