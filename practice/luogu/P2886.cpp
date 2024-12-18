#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,t,st,ed;
int id[maxn],idx;
struct mat
{
    int a[205][205];
    mat(){memset(a,0x3f,sizeof a);};
    int *operator[](int x){return a[x];}
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 1; i <= idx; i++)
            for (int j = 1; j <= idx; j++)
                for (int k = 1; k <= idx; k++)
                    ret[i][j] = min(ret[i][j],x[i][k] + y[k][j]);
        return ret;
    }
}base;
mat binpow(mat x,int y)
{
    mat ret = x;
    y --;
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
    cin >> n >> t >> st >> ed;
    id[st] = ++idx;
    id[ed] = ++idx;
    for (int i = 1; i <= t; i++)
    {
        int u,v,w;
        cin >> w >> u >> v;
        if (!id[u])
            id[u] = ++idx;
        if (!id[v])
            id[v] = ++idx;
        base[id[u]][id[v]] = base[id[v]][id[u]] = w;
    }
    base = binpow(base,n);
    cout << base[1][2];
    return 0;
}