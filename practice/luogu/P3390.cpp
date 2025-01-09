#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,k;
struct mat
{
    int n;
    int a[105][105];
    mat()
    {
        n = 0;
        memset(a,0,sizeof a);
    };
    void read()
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%lld",&a[i][j]);
    }
    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                printf("%lld ",a[i][j]);
            putchar('\n');
        }
    }
    mat operator*(mat x)
    {
        mat ret;
        ret.n = n;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                        ret.a[i][j] = (ret.a[i][j] + a[i][k] * x.a[k][j] % mod) % mod;
        return ret;
    }
}m1;
template <typename T>
T binpow(T x,int y)
{
    T ret;
    ret.n = n;
    for (int i = 1; i <= n; i++)
        ret.a[i][i] = 1;
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
    m1.n = n;
    m1.read();
    binpow(m1,k).print();
    return 0;
}