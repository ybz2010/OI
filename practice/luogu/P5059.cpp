#include<bits/extc++.h>
#define int __int128
using namespace std;
int n,mod = 114514;
void read(int &x)
{
    x = 0;
    short f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
void write(int x)
{
    if (x > 10)
        write(x / 10);
    putchar('0' + x % 10);
}
struct modint
{
    int val;
    modint(int x = 0):val(x % mod){};
    int &operator()(){return (val %= mod);}
    friend modint operator+(modint x,modint y){return ((x() + y()) % mod);}
    friend modint operator+=(modint &x,modint y){return (x() += y()) %= mod;}
    friend modint operator-(modint x,modint y){return (((x() - y()) % mod + mod) % mod);}
    friend modint operator-=(modint &x,modint y){return (((x() -= y()) %= mod) += mod) %= mod;}
    friend modint operator*(modint x,modint y){return (x() * y() % mod);}
    friend modint operator*=(modint &x,modint y){return (x() *= y()) %= mod;}
};
struct mat
{
    modint a[2][2];
    mat(int x = 0)
    {
        memset(a,0,sizeof a);
        a[0][0] = a[1][1] = x;
    }
    modint *operator[](int x){return a[x];}
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    ret[i][j] += x[i][k] * y[k][j];
        return ret;
    }
}base,origin;
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
    read(n),read(mod);
    base[0][0] = base[0][1] = base[1][0] = 1;
    origin[0][0] = origin[1][0] = 1;
    origin = binpow(base,n + 1) * origin;
    modint tmp = origin[0][0] - n - 2;
    write(binpow(tmp,n + 1)());
    return 0;
}