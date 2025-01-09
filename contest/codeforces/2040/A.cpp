#include<bits/extc++.h>
using namespace std;
int n,k;
int a[105];
void solve()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int i = 1; i <= n; i++)
    {
        bool fl = 1;
        for (int j = 1; j <= n && fl; j++)
        {
            if (i == j)
                continue;
            if (abs(a[i] - a[j]) % k == 0)
                fl = 0;
        }
        if (fl)
        {
            printf("YES\n%d\n",i);
            return;
        }
    }
    puts("NO");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}