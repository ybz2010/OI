#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,x,ans;
int a[maxn];
signed main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)    
        cin >> a[i];
    if (a[1] > x)
    {
        ans += a[1] - x;
        a[1] = x;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] + a[i - 1] > x)
        {
            ans += a[i] + a[i - 1] - x;
            a[i] -= a[i] + a[i - 1] - x;
        }
    }
    cout << ans;
    return 0;
}