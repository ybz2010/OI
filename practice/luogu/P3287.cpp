#include<bits/extc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int n,k;
int maxx,maxy;
int a[maxn],dp[505][maxn];
int lowbit(int x){return (x & -x);}
void upd(int x,int y,int val)
{
    for (int i = x; i <= maxx; i += lowbit(i))
        for (int j = y; j <= maxy; j += lowbit(j))
            dp[i][j] = max(dp[i][j],val);
}
int que(int x,int y)
{
    int ret = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            ret = max(ret,dp[i][j]);
    return ret;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxy = max(maxy,a[i]);
    }
    maxx = k + 1,maxy += k;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 0; j--)
        {
            int tmp = que(j + 1,a[i] + j) + 1;
            ans = max(ans,tmp);
            upd(j + 1,a[i] + j,tmp);
        }
    }
    cout << ans;
    return 0;
}