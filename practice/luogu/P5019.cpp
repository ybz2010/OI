#include<bits/extc++.h>
using namespace std;
const int maxn = 100000 + 5;
int n;
int a[maxn];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 2; i <= n; i++)
        if (a[i] > a[i - 1])
            ans += a[i] - a[i - 1];
    cout << ans + a[1];
    return 0;
}