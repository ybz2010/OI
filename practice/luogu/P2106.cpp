#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;
int k;
struct mat
{
    int a[10][10];
    mat(){memset(a,0,sizeof a);};
    void base()
    {
        memset(a,0,sizeof a);
        for (int i = 0; i < 10; i++)
            a[i][i] = 1;
    }
    int *operator[](int x){return a[x];}
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++)
                    ret[i][j] = (ret[i][j] + x[i][k] * y[k][j] % mod) % mod;
        return ret;
    }
}base,origin;
mat binpow(mat x,int y)
{
    mat ret;
    ret.base();
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
    scanf("%lld",&k);
    if (k == 1)
    {
        printf("10");
        return 0;
    }
    for (int i = 1; i < 10; i++)
        origin[i][0] = 1;
    for (int i = 0; i < 10; i++)
        for (int j = max(0ll,i - 2); j <= min(9ll,i + 2); j++)
            base[i][j] = 1;
    base = binpow(base,k - 1);
    origin = base * origin;
    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans = (ans + origin[i][0]) % mod;
    printf("%lld",ans);
    return 0;
}