#include<bits/stdc++.h>
#define int long long
using namespace std;
int l,r;
bool prime(int x)
{
    if (x == 1)
        return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
void solve(int t)
{
    scanf("%lld%lld",&l,&r);
    bool fl = 0;
    for (int i = l; i <= r; i++)
    {
        if (prime(i))
        {
            if (fl)
                putchar('\n');
            fl = 1;
            printf("%lld",i);
        }
    }
    if (t)
        puts("\n");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve(t);
}