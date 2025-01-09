#include<iostream>
#include<algorithm>
#include<cstring>
#pragma GCC optimize("Ofast","inline")
using namespace std;
const int maxn = 1005;
const int mod = 1e9 + 7;
int n,m,len;
int tree[maxn],apr[maxn];
int a[maxn],dp[maxn][maxn];
void read(int &ret)
{
    ret = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){ret = ret * 10 + ch - '0'; ch = getchar();}
    ret *= f;
}
int lowbit(int x){return (x & -x);};
void upd(int pos,int x)
{
    while (pos <= len)
    {
        tree[pos] = (tree[pos] + x) % mod;
        pos += lowbit(pos);
    }
}
int que(int pos)
{
    int ret = 0;
    while (pos >= 1)
    {
        ret = (ret + tree[pos]) % mod;
        pos -= lowbit(pos);
    }
    return ret;
}
int bound(int x)
{
    int l = 1,r = len,mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (apr[mid] > x)
            r = mid - 1;
        else if (apr[mid] < x)
            l = mid + 1;
        else
            return mid;
    }
    return -1;
}
int solve()
{
    read(n),read(m);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        apr[i] = a[i];
    }
    sort(apr + 1,apr + n + 1);
    len = unique(apr + 1,apr + n + 1) - apr - 1;
    memset(dp,0,sizeof dp);
    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;
    for (int i = 1; i <= n; i++)
        a[i] = bound(a[i]);
    for (int j = 2; j <= m; j++)
    {
        memset(tree,0,sizeof tree);
        for (int i = 1; i <= n; i++)
        {
            dp[i][j] = que(a[i] - 1);
            upd(a[i],dp[i][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i][m]) % mod;
    return ans;
}
signed main()
{
    int t;
    read(t);
    for (int i = 1; i <= t; i++)
        printf("Case #%d: %d\n",i,solve());
    return 0;
}