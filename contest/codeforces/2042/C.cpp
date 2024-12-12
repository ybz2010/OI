#include<bits/extc++.h>
using namespace std;
const int maxn = 2005;
int n;
int a[maxn];
int dp[maxn][maxn];
void solve()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        a[i] = ch == '1' ? 1 : -1;
    }
    for (int i = 1; i <= n ; i++)
    {
        
    }
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}