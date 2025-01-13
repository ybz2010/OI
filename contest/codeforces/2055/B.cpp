#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n;
void solve()
{
    scanf("%d",&n);
    vector<int>a(n + 5,0),b(n + 5,0);
    for (int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    for (int j = 1; j <= n; j++)
        scanf("%d",&b[j]);
    int val1 = inf,val2 = -inf;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < b[i])
        {
            if (val2 != -inf)
            {
                puts("NO");
                return;
            }
            val2 = b[i] - a[i];
        }
        else
            val1 = min(val1,a[i] - b[i]);
    }
    if (val2 > val1)
        puts("NO");
    else
        puts("YES");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}