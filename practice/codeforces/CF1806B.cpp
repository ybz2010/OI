#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,cnt0;
int a[maxn];
void solve()
{
    scanf("%d",&n);
    cnt0 = 0;
    memset(a,0,sizeof a);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        if (a[i] == 0)
            cnt0 ++;
    }
    if (cnt0 <= (n + 1 >> 1))
    {
        puts("0");
        return;
    }
    if (cnt0 == n)
    {
        puts("1");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 1)
        {
            puts("1");
            return;
        }
    }
    puts("2");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}