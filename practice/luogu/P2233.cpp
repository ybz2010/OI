#include<bits/extc++.h>
using namespace std;
const int mod = 1000;
int n;
struct mat
{
    int a[8][8];
    mat(){memset(a,0,sizeof a);};
    void base()
    {
        memset(a,0,sizeof a);
        for (int i = 0; i < 8; i++)
            a[i][i] = 1;
    }
    int *operator[](int x){return a[x];}
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                for (int k = 0; k < 8; k++)
                    ret[i][j] = (ret[i][j] + x[i][k] * y[k][j] % mod) % mod;
        return ret;
    }
}base;
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
    cin >> n;
    for (int i = 0; i < 8; i++)
    {
        base[i][(i + 1) % 8] = 1;
        base[(i + 1) % 8][i] = 1;
    }
    for (int i = 0; i < 8; i++)
        base[4][i] = 0;
    base = binpow(base,n);
    cout << base[0][4];
    return 0;
}