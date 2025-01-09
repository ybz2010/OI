#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n,m;
int s[maxn],l[maxn];
struct mat
{
    int a[2][2];
    mat(){memset(a,0,sizeof a);};
    mat operator*(mat x)
    {
        mat ret;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * x.a[k][j] % mod) % mod;
        return ret;
    }
}base;
mat binpow(mat x,int y)
{
    mat ret;
    ret.a[0][0] = ret.a[1][1] = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x;
        x = x * x;
        y >>= 1;
    }
    return ret;
}
signed main()
{
    scanf("%lld%lld",&m,&n);
    for (int i = 1; i <= m; i++)
        scanf("%lld",s + i);
    for (int i = 1; i <= m; i++)
        scanf("%lld",l + i);
    for (int i = 1; i <= m; i++)
    {
        base.a[0][0] = (base.a[0][0] + (s[i] + l[i]) * s[i] % mod) % mod;
        base.a[0][1] = (base.a[0][1] + (s[i] + l[i]) * l[i] % mod) % mod;
        base.a[1][0] = (base.a[1][0] + s[i] * s[i] % mod) % mod;
        base.a[1][1] = (base.a[1][1] + s[i] * l[i] % mod) % mod;
    }
    base = binpow(base,n - 1);
    int dp0 = (s[1] * base.a[0][0] % mod + l[1] * base.a[1][0] % mod) % mod;
    int dp1 = (s[1] * base.a[0][1] % mod + l[1] * base.a[1][1] % mod) % mod;
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp0 * (s[i] + l[i]) % mod + dp1 * s[i] % mod) % mod;
    cout << ans;
    return 0;
}