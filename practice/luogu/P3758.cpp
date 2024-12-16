#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 2017;
int n,m,t;
struct mat
{
    int a[105][105];
    mat(int x = 0)
    {
        memset(a,0,sizeof a);
        for (int i = 0; i <= 100; i++)
            a[i][i] = x;
    };
    int *operator[](int x){return a[x];}
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= n; k++)
                    ret[i][j] = (ret[i][j] + x[i][k] * y[k][j] % mod) % mod;
        return ret;
    }
}base;
template<typename type>
type binpow(type x,int y)
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
    cin >> n >> m;
    int u,v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        base[u][v] = base[v][u] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        base[i][i] = 1;
        base[i][0] = 1;
    }
    cin >> t;
    base = binpow(base,t);
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = (ans + base[1][i]) % mod;
    cout << ans;
    return 0;
}