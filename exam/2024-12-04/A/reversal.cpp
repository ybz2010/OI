#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
char s[maxn << 1];
void solve()
{
    memset(s,0,sizeof s);
    scanf("%lld%s",&n,s + 1);
    if (s[1] == 'W' || s[n << 1] == 'W')
    {
        puts("0");
        return;
    }
    int ans = 1,t = 1;
    bool lst = 1;
    for (int i = 2; i <= (n << 1); i++)
    {
        if (s[i] != s[i - 1])
        {
            if (lst)
                t ++;
            else
                t --;
        }
        else
        {
            if (lst)
                t --;
            else
                t ++;
            lst ^= 1;
        }
        if (!lst)
            ans = ans * (t + 1) % mod;
        if (t < 0)
        {
            puts("0");
            return;
        }
    }
    if (t)
    {
        puts("0");
        return;
    }
    for (int i = 1; i <= n; i++)
        ans = ans * i % mod;
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}