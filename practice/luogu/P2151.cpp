#include<bits/extc++.h>
using namespace std;
const int mod = 45989;
int n,m,t,st,ed;
int head[55],idx;
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[125];
void adde(int u,int v)
{
    e[++idx] = edge(v,head[u]);
    head[u] = idx;
}
int rev(int i)
{
    if (i & 1)
        return i + 1;
    return i - 1;
}
struct mat
{
    int r,c;
    int a[125][125];
    mat(int r = 0,int c = 0):r(r),c(c){memset(a,0,sizeof a);};
    int *operator[](int x){return a[x];}
    void base()
    {
        memset(a,0,sizeof a);
        for (int i = 1; i <= 120; i++)
            a[i][i] = 1;
    }
    friend mat operator*(mat x,mat y)
    {
        mat ret(x.r,y.c);
        for (int i = 1; i <= x.r; i++)
            for (int j = 1; j <= y.c; j++)
                for (int k = 1; k <= x.c; k++)
                    ret[i][j] = (ret[i][j] + x[i][k] * y[k][j] % mod) % mod;
        return ret;
    }
}origin,base;
mat binpow(mat x,int y)
{
    mat ret(x.r,x.c);
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
    cin >> n >> m >> t >> st >> ed;
    int u,v;
    while (m--)
    {
        cin >> u >> v;
        adde(u,v);
        adde(v,u);
    }
    base = mat(idx,idx);
    for (int i = 1; i <= idx; i++)
        for (int j = head[e[i].v]; j; j = e[j].nxt)
            if (j != rev(i))
                base[j][i] = 1;
    origin = mat(idx,1);
    for (int i = head[st]; i; i = e[i].nxt)
        origin[i][1] = 1;
    base = binpow(base,t - 1);
    origin = base * origin;
    int ans = 0;
    for (int i = head[ed]; i; i = e[i].nxt)
        ans = (ans + origin[rev(i)][1]) % mod;
    cout << ans;
    return 0;
}