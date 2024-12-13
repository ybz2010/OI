#include <cstdio>
#include <ctype.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define lowbit(x) (x & -x)
const int maxn = 1e4 + 10;
const int maxk = 510;
//=============================================================
int n, K, ans, a[maxn], dp[maxk][maxn];
int maxx, maxy;
//=============================================================
inline int read()
{
    int f = 1, w = 0;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = -1;
    for (; isdigit(ch); ch = getchar())
        w = (w << 3) + (w << 1) + (ch ^ '0');
    return f * w;
}
void GetMax(int &fir, int sec)
{
    if (sec > fir)
        fir = sec;
}
void GetMin(int &fir, int sec)
{
    if (sec < fir)
        fir = sec;
}
int que(int i,int j)
{
    int ret = 0;
    for (; i; i -= lowbit(i))
        for (; j; j -= lowbit(j))
            ret = max(ret,dp[i][j]);
    return ret;
}
void upd(int i,int j,int x)
{
    for (; i <= maxx; i += lowbit(i))
        for (; j <= maxy; j += lowbit(j))
            dp[i][j] = max(dp[i][j],x);
}
//=============================================================
int main()
{
    n = read(), K = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
        GetMax(maxy, a[i]);
    }
    maxx = K + 1, maxy += K;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = K; j >= 0; --j)
        {
            int tmp = que(j + 1, a[i] + j) + 1;
            GetMax(ans, tmp);
            upd(j + 1, a[i] + j, tmp);
        }
    }
    printf("%d\n", ans);
    return 0;
}