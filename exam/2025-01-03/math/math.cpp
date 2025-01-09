#include<bits/extc++.h>
#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
using namespace std;
const int maxn(2000 + 5);
int a,b,cnt[10];
struct long_int
{
    int len;
    short d[maxn];
    long_int(){memset(d,0,sizeof d);len = 0;}
    short &operator[](int x){return d[x];}
    void read()
    {
        char ch(getchar());
        while (!isdigit(ch))ch = getchar();
        len = 0;
        while (isdigit(ch)){d[++len] = ch - '0'; ch = getchar();}
        reverse(d + 1,d + len + 1);
    }
    void write()
    {
        for (int i(len); i; i--)
            printf("%d",d[i]);
    }
    friend long_int operator*(long_int x,long_int y)
    {
        long_int ret;
        ret.len = x.len + y.len - 1;
        for (int i = 1; i <= x.len; i++)
            for (int j = 1; j <= y.len; j++)
                ret[i + j - 1] += x[i] * y[j];
        for (int i = 1; i <= ret.len; i++)
        {
            ret[i + 1] += ret[i] / 10;
            ret[i] %= 10;
        }
        if (ret[ret.len + 1])
            ret.len ++;
        return ret;
    }
    friend bool operator<(long_int x,long_int y)
    {
        if (x.len != y.len)
            return x.len < y.len;
        for (int i(x.len); i; i--)
            if (x[i] != y[i])
                return x[i] < y[i];
        return 0;
    }
}x,y;
inline void solve()
{
    scanf("%d%d",&a,&b);
    x = y = long_int();
    if (a > b)
        swap(a,b);
    x.len = a,y.len = b;
    long_int ans1,ans2;
    for (int i = 1; i < 10; i++)
        scanf("%d",cnt + i);
    for (int i = 9; i; i--)
    {
        while (cnt[i]--)
        {
            if (!a)
                y[b--] = i;
            else if (!b)
                x[a--] = i;
            else if (a == x.len && b == y.len)
                x[a--] = i;
            else if (b == y.len)
                y[b--] = i;
            else
            {
                x[a--] = i;
                ans1 = x * y;
                x[++a] = 0;
                y[b--] = i;
                ans2 = x * y;
                y[++b] = 0;
                if (ans1 < ans2)
                    y[b--] = i;
                else
                    x[a--] = i;
            }
        }
    }
    (x * y).write();
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}