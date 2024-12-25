#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e5 + 3;
int n,m;
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
signed main()
{
    cin >> m >> n;
    cout << (binpow(m,n) - m * binpow(m - 1,n - 1) % mod + mod) % mod;
    return 0;
}