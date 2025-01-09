#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n;
struct mat{
    int a[2][2];
    mat(int x = 0){memset(a,0,sizeof a);a[0][0] = a[1][1] = x;};
    mat operator*(mat x)
    {
        mat ret;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * x.a[k][j] % mod) % mod;
        return ret;
    }
}base,tmp;
template<typename type>type binpow(type x,int y)
{
    type ret(1);
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
    scanf("%lld",&n);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    base.a[0][0] = 1;
    base.a[0][1] = 1;
    base.a[1][0] = 1;
    base.a[1][1] = 0;
    base = binpow(base,n - 2);
    tmp.a[0][0] = tmp.a[0][1] = 1;
    printf("%lld",(tmp * base).a[0][0]);
    return 0;
}