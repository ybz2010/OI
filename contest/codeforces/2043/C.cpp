#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,val,pos,sum;
int max1,min1,max2,min2;
int a[maxn],dp1[maxn],dp2[maxn];
void solve()
{
    cin >> n;
    pos = val = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1)
        {
            val = a[i];
            pos = i;
        }
    }
    max1 = min1 = 0;
    fill(dp1 + 1,dp1 + n + 1,0);
    fill(dp2 + 1,dp2 + n + 1,0);
    for (int i = 1; i <= pos - 1; i++)   
    {
        dp1[i] = max(dp1[i - 1] + a[i],0ll);
        max1 = max(max1,dp1[i]);
        dp2[i] = min(dp2[i - 1] + a[i],0ll);
        min1 = min(min1,dp2[i]);
    }
    max2 = min2 = 0;
    fill(dp1 + 1,dp1 + n + 1,0);
    fill(dp2 + 1,dp2 + n + 1,0);
    for (int i = pos + 1; i <= n; i++)
    {
        dp1[i] = max(dp1[i - 1] + a[i],0ll);
        max2 = max(max2,dp1[i]);
        dp2[i] = min(dp2[i - 1] + a[i],0ll);
        min2 = min(min2,dp2[i]);
    }
    set<int>ans;
    for (int i = min(min1,min2); i <= max(max1,max2); i++)
        ans.insert(i);
    max1 = min1 = sum = 0;
    for (int i = pos - 1; i >= 1; i--)
    {
        sum += a[i];
        max1 = max(max1,sum);
        min1 = min(min1,sum);
    }
    max2 = min2 = sum = 0;
    for (int i = pos + 1; i <= n; i++)
    {
        sum += a[i];
        max2 = max(max2,sum);
        min2 = min(min2,sum);
    }
    for (int i = (min1 + min2); i <= (max1 + max2); i++)
        ans.insert(val + i);
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}