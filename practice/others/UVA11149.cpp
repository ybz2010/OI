#include<stdio.h>
#include<ctype.h>
#include<string.h>
#pragma GCC optimize(2)
const int mod = 10;
int n,k;
void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
struct modint
{
    int val;
    modint(int x = 0):val(x % mod){};
    int &operator()(){return (val %= mod);}
    friend modint operator+(modint x,modint y){return ((x() + y()) % mod);}
    friend modint operator+=(modint &x,modint y){return (x() += y()) %= mod;}
    friend modint operator*(modint x,modint y){return (x() * y() % mod);}
    friend modint operator*=(modint &x,modint y){return (x() *= y()) %= mod;}
}x;
struct mat1
{
    modint a[45][45];
    mat1(int x = 0)
    {
        memset(a,0,sizeof a);
        for (int i = 1; i <= 40; i++)
            a[i][i] = x;
    }
    modint *operator[](int x){return a[x];}
    friend mat1 operator+(mat1 x,mat1 y)
    {
        mat1 ret;
        for (int i = 1; i <= 40; i++)
            for (int j = 1; j <= 40; j++)
                ret[i][j] = x[i][j] + y[i][j];
        return ret;
    }
    friend mat1 operator*(mat1 x,mat1 y)
    {
        mat1 ret;
        for (int i = 1; i <= 40; i++)
            for (int j = 1; j <= 40; j++)
                for (int k = 1; k <= 40; k++)
                    ret[i][j] += x[i][k] * y[k][j];
        return ret;
    }
}A;
struct mat2
{
    mat1 a[2][2];
    mat2()
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                memset(a[i][j].a,0,sizeof a[i][j].a);
    };
    mat2(mat1 x)
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                memset(a[i][j].a,0,sizeof a[i][j].a);
        a[0][0] = a[1][1] = x;
    }
    mat1 *operator[](int x){return a[x];}
    friend mat2 operator*(mat2 x,mat2 y)
    {
        mat2 ret;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    ret[i][j] = ret[i][j] + x[i][k] * y[k][j];
        return ret;
    }
}origin,base;
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
void mian()
{
    A = mat1();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            read(A[i][j]());
    origin[0][0] = origin[0][1] = origin[1][1] = mat1();
    origin[1][0] = A;
    base[0][0] = A;
    base[0][1] = base[1][1] = mat1(1);
    base[1][0] = mat1();
    base = binpow(base,k);
    origin = base * origin;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d",origin[0][0][i][j]());
            if (j != n)
                putchar(' ');
        }
        if (i != n)
            putchar('\n');
    }
    puts("\n");
}
signed main()
{
    read(n),read(k);
    while (n && k)
    {
        mian();
        read(n),read(k);
    }
}