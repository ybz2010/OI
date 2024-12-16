#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,q;
int f[105];
struct mat
{
    int r,c;
    int a[105][105];
    mat(){memset(a,0,sizeof a);};
    mat(int x,int r,int c):r(r),c(c)
    {
        memset(a,0,sizeof a);
        for (int i = 1; i <= 100; i++)
            a[i][i] = x;
    };
    int *operator[](int x){return a[x];}
    friend mat operator*(mat x,mat y)
    {
        mat ret(0,x.r,y.c);
        for (int i = 1; i <= x.r; i++)
            for (int j = 1; j <= y.c; j++)
                for (int k = 1; k <= x.c; k++)
                    ret[i][j] ^= x[i][k] * y[k][j];
        return ret;
    }
}dis[64];
signed main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> f[i];
    dis[0].r = dis[0].c = n;
    int u,v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        dis[0][u][v] = dis[0][v][u] = 1;
    }
    for (int i = 1; i < 64; i++)
        dis[i] = dis[i - 1] * dis[i - 1];
    int x;
    for (int i = 1; i <= q; i++)
    {
        cin >> x;
        mat origin(0,n,1);
        for (int j = 1; j <= n; j++)
            origin[j][1] = f[j];
        for (int j = 0; j < 64; j++)
            if ((x >> j) & 1)
                origin = dis[j] * origin;
        cout << origin[1][1] << endl;
    }
    return 0;
}