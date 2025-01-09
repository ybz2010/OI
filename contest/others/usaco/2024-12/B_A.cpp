#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
int st[11] = {0,0,45,445,4445,44445,444445,4444445,44444445,444444445,4444444445};
int ans[11] = {0,0,5,55,555,5555,55555,555555,5555555,55555555,555555555};
int sum[11];
void solve()
{
    cin >> n;
    int p = 0;
    while (pow(10,++p) < n);
    cout << sum[p - 1] + min(max(0ll,n - st[p] + 1),ans[p]) << endl;
}
signed main()
{
    int t;
    for (int i = 1; i < 9; i++)
        sum[i] = sum[i - 1] + ans[i];
    cin >> t;
    while (t--)
        solve();
    return 0;
}