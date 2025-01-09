#include <bits/extc++.h>
#define int long long
using namespace std;
int n,mod,temp[2][2];
int mul(int a,int b)
{
    int x = a,y = b,tmp = 0;
    while (y)
    {
        if (y & 1)
            tmp = (tmp + x) % mod;
        x = (x * 2) % mod;
        y >>= 1;
    }
    return tmp;
}
struct mat
{
    int a[2][2];
}origin,base;
int binpow(int a,int b)
{
    int tmp = 1;
    while (b)
    {
        if (b & 1)
            tmp = mul(tmp,a);
        a = mul(a,a);
        b >>= 1;
    }
    return tmp;
}
void mat_mul(mat &x,mat y)
{
    memset(temp,0,sizeof(temp));
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++)
                temp[i][j] = (temp[i][j] + mul(x.a[i][k],y.a[k][j])) % mod;
    memcpy(x.a,temp,sizeof(temp));
}
int fib(int a)
{
    while (a)
    {
        if (a & 1)
            mat_mul(origin,base);
        a >>= 1;
        mat_mul(base,base);
    }
    return origin.a[0][0];
}
signed main()
{
    origin.a[0][0] = origin.a[1][1] = 1;
    base.a[0][1] = base.a[1][0] = base.a[0][0] = 1;
    scanf("%lld%lld",&n,&mod);
    printf("%lld",binpow(((fib(n + 2) - n - 2) % mod + mod) % mod,n + 1));
    return 0;
}