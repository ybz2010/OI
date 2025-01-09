#include<bits/extc++.h>
#define int unsigned long long
using namespace std;
int n,mod;
struct mat
{
    int a[3][3];
    mat(){memset(a,0,sizeof a);};
    int *operator[](int x){return a[x];}
    void base()
    {
        memset(a,0,sizeof a);
        for (int i = 0; i < 3; i++)
            a[i][i] = 1;
    }
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++) 
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
    cin >> n >> mod;
    int x = 0;
    origin[2][0] = 1;
    while (pow(10,x ++) <= n)
    {
        base = mat();
        base[0][0] = (int)pow(10,x) % mod;
        base[0][1] = base[0][2] = 
        base[1][1] = base[1][2] = 
        base[2][2] = 1;
        base = binpow(base,min(n,(int)pow(10,x) - 1) - (int)pow(10,x - 1) + 1);
        origin = base * origin;
    }
    cout << origin[0][0];
    return 0;
}