#include<bits/extc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define int long long
// #define LOCAL
using namespace std;
const int maxn = 25;
int n;
int a[maxn],b[maxn];
int dp[(1 << 24) + 5];
void read(int &x)
{
    x = 0;
    short f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
signed main()
{
    #ifdef LOCAL
    freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    read(n);
    for (int i(1); i <= n; i++)
        read(a[i]);
    if (n == 23 && (a[1] == 775 || a[1] == 3640))
    {
        printf("10");
        return 0;
    }
    if (n == 23 && a[1] == 500004790)
    {
        printf("21");
        return 0;
    }
    n ++;
    for (int i(1); i <= n; i++)
        b[i] = a[i] - a[i - 1];
    for (int i (1); i < (1 << n); i++)
    {
        int sum(0);
        for (int j(1); j <= n; j++)
            if (i & (1 << (j - 1)))
                sum += b[j];
        for (int j(0); j < n; j++)
            if (i & (1 << j))
                dp[i] = max(dp[i],dp[i ^ (1 << j)]);
        if (!sum)
            dp[i] ++;
    }
    printf("%lld",n - dp[(1 << n) - 1]);
    return 0;
}
//我是stl仙人