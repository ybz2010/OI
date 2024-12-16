#include<bits/extc++.h>
#define int __int128
using namespace std;
int m,a,c,n,g,x;
struct mat
{
    int a[2][2];
    mat(int x = 0)
    {
        memset(a,0,sizeof a);
        a[0][0] = a[1][1] = x;
    }
    int *operator[](int x){return a[x];}
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    ret[i][j] = (ret[i][j] + x[i][k] * y[k][j] % m) % m;
        return ret;
    }
}base,origin;
void read(int &x)
{
    x = 0;
    short f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + ch - '0';ch = getchar();}
    x *= f;
}
void write(int x)
{
    if (x > 10)
        write(x / 10);
    putchar('0' + x % 10);
}
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
    read(m),read(a),read(c),read(x),read(n),read(g);
    origin[0][0] = x;
    origin[1][0] = c;
    base[0][0] = a;
    base[0][1] = base[1][1] = 1;
    base = binpow(base,n);
    origin = base * origin;
    write(origin[0][0] % g);
    return 0;
}