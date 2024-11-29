#include<bits/extc++.h>
using namespace std;
int n,m,k;
struct mat
{
    int r,c;
    int m[105][105];
    void read()
    {
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                scanf("%d",&m[i][j]);
    }
    void print()
    {
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
                printf("%d ",m[i][j]);
            putchar('\n');
        }
    }
    mat operator*(mat x)
    {
        mat ret;
        ret.r = r;
        ret.c = x.c;
        for (int i = 1; i <= ret.r; i++)
            for (int j = 1; j <= ret.c; j++)
                for (int k = 1; k <= c; k++)
                    ret.m[i][j] += m[i][k] * x.m[k][j];
        return ret;
    }
}m1,m2;
signed main()
{
    scanf("%d%d%d",&n,&m,&k);
    m1.r = n,m1.c = m;
    m2.r = m,m2.c = k;
    m1.read(),m2.read();
    (m1 * m2).print();
    return 0;
}