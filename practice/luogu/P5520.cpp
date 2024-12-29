#include<bits/extc++.h>
#define int long long
using namespace std;
int type,n,m,mod;
signed main()
{
    cin >> type >> n >> m >> mod;
    int ans = 1;
    for (int i = n - m + 1; i >= n - m - m + 1 + 1; i--)
        ans = ans * i % mod;
    cout << ans;
    return 0;
}