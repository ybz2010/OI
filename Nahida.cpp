#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxv = 64 + 10;
int t, idx1, idx2;
int x[maxv], z[maxv];
ll ans, a, b;
ll dp[maxv][3][2];
ll read()
{
    ll ret = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ret = (ret << 3) + (ret << 1) + (ch ^ 48);
        ch = getchar();
    }
    return ret * w;
}
void init()
{
    idx1 = idx2 = 0;
    memset(dp, -1, sizeof(dp));
}
void inpu() { b = read(), a = read(); }
void prepa()
{
    while (a)
    {
        x[++idx1] = a % 10;
        a /= 10;
    }
    while (b)
    {
        z[++idx2] = b % 10;
        b /= 10;
    }
    while (idx1 < idx2)
        x[++idx1] = 0;
    while (idx2 < idx1)
        z[++idx2] = 0;
}
bool check(int pos, bool bound, int num)
{
    if (num != x[pos])
        return num > x[pos];
    return bound;
}
ll dfs(int pos,int add,bool bound)
{
    if (~dp[pos][add][bound])
        return dp[pos][add][bound];
    else if (pos == idx1 + 1)
        return dp[pos][add][bound] = !bound;
    int ret = 0;
    if (z[pos] == 0)
    {
        for (int i = 0; i <= 3; i++)
            ret += dfs(pos + 1,0,check(pos,bound,i));
        if (add == 0)
            ret += dfs(pos + 1,0,check(pos,bound,4));
        else
            ret += dfs(pos + 1,2,check(pos,bound,4));
        for (int i = 5; i <= 9; i++)
            ret += dfs(pos + 1,1,check(pos,bound,i));
    }
    else if (z[pos] == 1)
    {
        if (add == 0)
            ret += dfs(pos + 1,0,check(pos,bound,1));
        else
        {
            for (int i = 0; i <= 4; i++)
                ret += dfs(pos + 1,0,check(pos,bound,i));
            for (int i = 5; i <= 9; i++)
                ret += dfs(pos + 1,1,check(pos,bound,i));
        }
    }
    else
    {
        if (add <= 1)
            ret += dfs(pos + 1,0,check(pos,bound,z[pos] - add));
        else
        {
            ret += dfs(pos + 1,0,check(pos,bound,z[pos] - 0));
            ret += dfs(pos + 1,0,check(pos,bound,z[pos] - 1));
        }
    }
    return dp[pos][add][bound] = ret;
}
void solve()
{
    init();
    inpu();
    prepa();
    ans = dfs(1, 0, 0);
    printf("%lld\n", ans);
}
int main()
{
    t = read();
    while (t--)
        solve();
    return 0;
}