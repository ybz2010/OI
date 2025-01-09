#include<bits/extc++.h>
using namespace std;
const int mod = 2009;
int n,m,t;
struct mat
{
    int a[105][105];
    mat(){memset(a,0,sizeof a);};
    int *operator[](int x){return a[x];}
    void base()
    {
        memset(a,0,sizeof a);
        for (int i = 1; i <= 100; i++)
            a[i][i] = 1;
    }
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                for (int k = 1; k <= m; k++)
                    ret[i][j] = (ret[i][j] + x[i][k] * y[k][j] % mod) % mod;
        return ret;
    }
}dis;
int toint(int x,int y){return (x - 1) * 9 + y + 1;}
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 8; j++)
            dis[toint(i,j + 1)][toint(i,j)] = 1;
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            if (ch > '0')
                dis[toint(i,0)][toint(j,ch - '0' - 1)] = 1;
        }
    }
    m = 9 * n;
    dis = binpow(dis,t);
    cout << dis[toint(1,0)][toint(n,0)];
    return 0;
}