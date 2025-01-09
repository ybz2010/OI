#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,k;
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
    cin >> n >> k;
    cout << binpow(binpow(2,k) - 1,n);
    return 0;
}