#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 6662333;
int n;
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
    cin >> n;
    cout << binpow(2,n - 1);
    return 0;
}