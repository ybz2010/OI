#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 10000007;
int n,k,sum;
int a[maxn];
struct mat
{
    int a[3][3];
    mat(int x = 0)
    {
        memset(a,0,sizeof a);
        a[0][0] = a[1][1] = a[2][2] = x;
    }
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    ret.a[i][j] = (ret.a[i][j] + x.a[i][k] * y.a[k][j] % mod) % mod;
        return ret;
    }
}origin,base;
mat binpow(mat x,int y)
{
    mat ret(1);
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
    scanf("%lld%lld",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        sum += a[i];
    }
    sort(a + 1,a + n + 1);
    if (a[n] <= 0)
        printf("%lld",(sum + k * (a[n] + a[n - 1]) % mod) % mod);
    else
    {
        for (sum -= a[n]; k && a[n - 1] < 0; --k)
			a[n - 1] += a[n], sum += a[n - 1];
        base.a[0][0] = base.a[0][1] = base.a[0][2] = 1;
        base.a[1][0] = base.a[2][2] = 1;
        base = base * binpow(base,k);
        printf("%lld",((sum + a[n] * base.a[0][2] + a[n - 1] * base.a[1][2]) % mod + mod) % mod);
    }
    return 0;
}