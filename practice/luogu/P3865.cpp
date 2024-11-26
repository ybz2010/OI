#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int a[maxn],f[maxn][35],lg2[maxn];
void read(int &ret)
{
    ret = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){ret = ret * 10 + ch - '0'; ch = getchar();}
    ret *= f;
}
void init()
{
    lg2[1] = 0;
    for (int i = 2; i <= 1e5; i++)
        lg2[i] = lg2[i >> 1] + 1;
}
int que(int l,int r)
{
    int s = lg2[r - l + 1];
    return max(f[l][s],f[r - (1 << s) + 1][s]);
}
signed main()
{
    read(n),read(m);
    for (int i = 1; i <= n; i++)
        read(f[i][0]);
    init();
    for (int j = 1; j <= 30; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
    int l,r;
    for (int i = 1; i <= m; i++)
    {
        read(l),read(r);
        printf("%lld\n",que(l,r));
    }
    return 0;
}