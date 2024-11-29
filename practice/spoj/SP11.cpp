#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
void solve(int t)
{
    scanf("%lld",&n);
    int base = 5,ans = 0;
    while (base <= n)
    {
        ans += n / base;
        base *= 5;
    }
    printf("%lld",ans);
    if (t)
        putchar('\n');
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve(t);
    return 0;
}