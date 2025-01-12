#include<bits/extc++.h>
#define int __int128
using namespace std;
const int maxn = 5e5 + 5;
int n;
int dp[maxn][2];
int a[maxn];
inline void read(int &x)
{
    x = 0;
    short f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        write(-x);
        return;
    }
    if (x > 9)
        write(x / 10);
    putchar('0' + x % 10);
}
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret *= x;
        x *= x;
        y >>= 1;
    }
    return ret;
}
int que(int l,int r)
{
    l--;
    return a[r] - a[l] * binpow((int)10,r - l);
}
signed main()
{
    read(n);
    for (int i = 1,ch; i <= n; i++)
    {
        ch = getchar();
        while (!isdigit(ch))
            ch = getchar();
        a[i] = ch - '0' + a[i - 1] * 10;
    }
    
    return 0;
}