#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
string s[maxn],a[maxn],ans[maxn],str;
int n,m,dp[maxn];
signed main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            s[++ n].push_back(str[i]);
        else
            s[n].push_back(str[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(a + 1,a + m + 1,s[i]) - a;
        m = max(pos,m);
        a[pos] = s[i];
        ans[pos] = ans[pos - 1] + s[i]; 
    }
    cout << ans[m];
    return 0;
}